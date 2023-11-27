use super::memory::Memory; //read for this function

// Conditional Move:   0
// If the value in register C is not zero, then the value in register A is replaced with the value in register B.
pub fn cond_move(instruction: u32, registers: &mut [u32; 8]) {
    let a = (instruction >> 6) & 0b111; //shift instruction right by 6 with mask of binary 111 Reps A Index.
    let b = (instruction >> 3) & 0b111; //shift instruction right by 3. Reps B Index.
    let c = instruction & 0b111; // Register C Index

    // ONLY if the conditional move to register C is NOT 0
    if registers[c as usize] != 0 {
        registers[a as usize] = registers[b as usize]; // perform the move.
    }
}

// Segmented Load:   1
// The value in the memory segment identified by the value in register B at the offset of the value in register C 
// is loaded into register A.
pub fn seg_load(instruction: u32, memory: &Memory, registers: &mut [u32; 8]) {
    let a = (instruction >> 6) & 0b111; // REg A Exctraction
    let b = (instruction >> 3) & 0b111; // Reg B Extraction
    let c = instruction & 0b111; // Reg C

    // Set the Segment ID and offset based on register B and C
    let segment_val = registers[b as usize] as usize; 
    let offset = registers[c as usize] as usize;
    
    // Loads value from segment and offset into Register A
    if let Some(segment) = memory.get_segment(segment_val) {
        if offset < segment.len() { // if the offset is within bounds
            registers[a as usize] = segment[offset]; //load seg
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
    let a = (instruction >> 6) & 0b111; // Reg A
    let b = (instruction >> 3) & 0b111; // REg B
    let c = instruction & 0b111; // Reg C

    // Set Segment ID from Register A, offset from Register B, and Value from Register C
    let segment_id = registers[a as usize] as usize;
    let offset = registers[b as usize] as usize;
    let value = registers[c as usize];

    memory.write_memory(segment_id, offset, value); // Write to memory with the appropriate segment, id, and value
}

// Addition:   3
//Store into register A the sum of the values in registers B and C.
pub fn add(instruction: u32, registers: &mut [u32; 8]) {
    let a = (instruction >> 6) & 0b111; // Register A
    let b = (instruction >> 3) & 0b111; // Register B
    let c = instruction & 0b111; // Register C

    registers[a as usize] = registers[b as usize].wrapping_add(registers[c as usize]);
}

// Multiplication:   4
// Store into register A the product of the values in registers B and C.
pub fn multiply(instruction: u32, registers: &mut [u32; 8]) {
    let a = (instruction >> 6) & 0b111;
    let b = (instruction >> 3) & 0b111;
    let c = instruction & 0b111;

    registers[a as usize] = registers[b as usize].wrapping_mul(registers[c as usize]);
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
    
    // bitwise nand on the values in reg b and C --> store them ni register C
    registers[a as usize] = !(registers[b as usize] & registers[c as usize]);
} 

// Halt: 7    --- just doing this one directly; some weird error with match bool return not matching... reeeee
//Terminate the program execution.
// pub fn halt() -> bool {
//     false // Returning false to indicate the machine should stop executing
// }

// Map Segment:  8
pub fn execute_map_segment_instruction(instruction: u32, memory: &mut Memory, registers: &[u32; 8]) {
    let b = (instruction >> 3) & 0b111;  // B holds size for new Seg
    let size = registers[b as usize]; // set the size from register b
    memory.map_segment(size); // call map function with given size.
}

// Unmap Segment: 9
pub fn execute_unmap_segment_instruction(instruction: u32, memory: &mut Memory, registers: &[u32; 8]) {
    let c = instruction & 0b111;  // C holds the ID Segments for Unmap
    let id = registers[c as usize]; // set id from register c
    memory.unmap_segment(id); // call unmap function passed hte id
}

// Output:   10
//Output the character represented by the value in register C.
use std::io::{self, Write}; 
pub fn output(instruction: u32, registers: &[u32; 8]) {
    let c = instruction & 0b111; // Reg C Index
    let value = registers[c as usize]; // Set value from register C

    if value <= 0xFF { // if the value is 0-255
        print!("{}", value as u8 as char); //output it
        io::stdout().flush().unwrap(); // Ensure immediate output without buffering
    } else { //otherwise panic; not expected character type.
        panic!("Output: Value in register is not a valid ASCII character");
    }
}

// Input:  11
// Read a character from the standard input and store its ASCII value in register C.
use std::io::Read;
pub fn input(instruction: u32, registers: &mut [u32; 8]) {
    let c = instruction & 0b111; // register c from instruction

    let mut buffer = [0; 1]; // set buffer for a singular character
    match io::stdin().read_exact(&mut buffer) {
        Ok(_) => { // put ascii value of read char into register c
            registers[c as usize] = buffer[0] as u32;
        }
        Err(_) => {
            // Store this value if error occurs or end of input.
            registers[c as usize] = 0xFFFFFFFF;
        }
    }
}

// Load Program: 12
//Load a program from the segment indicated by the value in register B and set the program counter to the value in register C.
pub fn load_program(instruction: u32, memory: &mut Memory, registers: &mut [u32; 8], program_counter: &mut usize) {
    let b = (instruction >> 3) & 0b111; // Reg B
    let c = instruction & 0b111; // Reg C

    // Segment ID from Register B and Program Counter from Register C
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
    let a = (instruction >> 25) & 0b111; // shift a by 25 for register A index
    let value = instruction & 0b1_1111_1111_1111_1111_1111; // Mask the 25 rightmost bits to get value for load 
    
    registers[a as usize] = value; // now load register A with the value above.
}
