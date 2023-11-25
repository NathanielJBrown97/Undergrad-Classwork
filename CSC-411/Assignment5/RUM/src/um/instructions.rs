use super::memory::Memory; //read for this function

// Conditional Move:   0
// If the value in register C is not zero, then the value in register A is replaced with the value in register B.
pub fn cond_move(instruction: u32, registers: &mut [u32; 8]) {
    let a = (instruction >> 6) & 0b111;
    let b = (instruction >> 3) & 0b111;
    let c = instruction & 0b111;

    if registers[c as usize] != 0 {
        registers[a as usize] = registers[b as usize];
    }
}

// Segmented Load:   1
// The value in the memory segment identified by the value in register B at the offset of the value in register C 
// is loaded into register A.
pub fn seg_load(instruction: u32, memory: &Memory, registers: &mut [u32; 8]) {
    let a = (instruction >> 6) & 0b111;
    let b = (instruction >> 3) & 0b111;
    let c = instruction & 0b111;

    let segment_val = registers[b as usize] as usize;
    let offset = registers[c as usize] as usize;
    
    if let Some(segment) = memory.get_segment(segment_val) {
        if offset < segment.len() {
            registers[a as usize] = segment[offset];
        } else {
            panic!("Segmented Load: Offset out of bounds");
        }
    } else {
        panic!("Segmented Load: Invalid segment");
    }
}

// Segmented Store:  2
// Store the value in register C into the memory segment identified by register A at the offset of the value in register B.
pub fn seg_store(instruction: u32, memory: &mut Memory, registers: &[u32; 8]) {
    let a = (instruction >> 6) & 0b111;
    let b = (instruction >> 3) & 0b111;
    let c = instruction & 0b111;

    let segment_id = registers[a as usize] as usize;
    let offset = registers[b as usize] as usize;
    let value = registers[c as usize];

    memory.write_memory(segment_id, offset, value);
}

// Addition:   3
//Store into register A the sum of the values in registers B and C.
pub fn add(instruction: u32, registers: &mut [u32; 8]) {
    let a = (instruction >> 6) & 0b111;
    let b = (instruction >> 3) & 0b111;
    let c = instruction & 0b111;

    registers[a as usize] = (registers[b as usize] + registers[c as usize]) % (1 << 32);
}

// Multiplication:   4
// Store into register A the product of the values in registers B and C.
pub fn multiply(instruction: u32, registers: &mut [u32; 8]) {
    let a = (instruction >> 6) & 0b111;
    let b = (instruction >> 3) & 0b111;
    let c = instruction & 0b111;

    registers[a as usize] = (registers[b as usize] * registers[c as usize]) % (1 << 32);
}

// Division:   5
// Store into register A the result of dividing the value in register B by the value in register C.
pub fn divide(instruction: u32, registers: &mut [u32; 8]) {
    let a = (instruction >> 6) & 0b111;
    let b = (instruction >> 3) & 0b111;
    let c = instruction & 0b111;

    if registers[c as usize] == 0 {
        panic!("Division by zero");
    }

    registers[a as usize] = registers[b as usize] / registers[c as usize];
}

// Bitwise NAND: 6
//Store into register A the result of a bitwise NAND of the values in registers B and C.
pub fn bitwise_nand(instruction: u32, registers: &mut [u32; 8]) {
    let a = (instruction >> 6) & 0b111;
    let b = (instruction >> 3) & 0b111;
    let c = instruction & 0b111;

    registers[a as usize] = !(registers[b as usize] & registers[c as usize]);
} 

// Halt: 7    --- just doing this one directly; some weird error with match bool return not matching... reeeee
//Terminate the program execution.
// pub fn halt() -> bool {
//     false // Returning false to indicate the machine should stop executing
// }

// Map Segment:  8
pub fn execute_map_segment_instruction(instruction: u32, memory: &mut Memory, registers: &[u32; 8]) {
    let b = (instruction >> 3) & 0b111;  // Assuming register B holds the size for the new segment
    let size = registers[b as usize];
    memory.map_segment(size);
}

// Unmap Segment: 9
pub fn execute_unmap_segment_instruction(instruction: u32, memory: &mut Memory, registers: &[u32; 8]) {
    let c = instruction & 0b111;  // Assuming register C holds the segment ID to unmap
    let id = registers[c as usize];
    memory.unmap_segment(id);
}

// Output:   10
//Output the character represented by the value in register C.
use std::io::{self, Write}; 
pub fn output(instruction: u32, registers: &[u32; 8]) {
    let c = instruction & 0b111;
    let value = registers[c as usize];

    if value <= 0xFF {
        print!("{}", value as u8 as char);
        io::stdout().flush().unwrap(); // Ensure immediate output without buffering
    } else {
        panic!("Output: Value in register is not a valid ASCII character");
    }
}

// Input:  11
// Read a character from the standard input and store its ASCII value in register C.
use std::io::Read;
pub fn input(instruction: u32, registers: &mut [u32; 8]) {
    let c = instruction & 0b111;

    let mut buffer = [0; 1];
    match io::stdin().read_exact(&mut buffer) {
        Ok(_) => {
            registers[c as usize] = buffer[0] as u32;
        }
        Err(_) => {
            // Store a special value if the end of input is reached or if an error occurs
            registers[c as usize] = 0xFFFFFFFF;
        }
    }
}

// Load Program: 12
//Load a program from the segment indicated by the value in register B and set the program counter to the value in register C.
pub fn load_program(instruction: u32, memory: &mut Memory, registers: &mut [u32; 8], program_counter: &mut usize) {
    let b = (instruction >> 3) & 0b111;
    let c = instruction & 0b111;

    let segment_id = registers[b as usize] as usize;
    let counter_value = registers[c as usize] as usize;

    if segment_id == 0 {
        // If the segment is '0', just set the program counter.
        *program_counter = counter_value;
    } else {
        // Otherwise, duplicate the specified segment and replace the '0' segment.
        if let Some(segment) = memory.get_segment(segment_id) {
            memory.load_program(segment.clone());
            *program_counter = counter_value;
        } else {
            panic!("Load Program: Invalid or unmapped segment");
        }
    }
}

// Load Value:  13
// The 25-bit value is loaded into register A. This is the only instruction that uses a single register.
pub fn load_value(instruction: u32, registers: &mut [u32; 8]) {
    let a = (instruction >> 25) & 0b111;
    let value = instruction & 0b1_1111_1111_1111_1111_1111;
    
    registers[a as usize] = value;
}
