use crate::memory;
use crate::instructions;

const NUM_REGISTERS: usize = 8; // constant maximum number of registers for the UM

// The Universal Machine Struct is used to emulate a Universal Machine's full functionality.
// This includes access to memory, registers, and utilizes a counter for working through
// any instructions. 
pub struct UniversalMachine {
    memory: memory::Memory, // memory field; using the memory module. Representing memory segments.
    registers: [u32; NUM_REGISTERS], // register field; via u32 array with a set size of 8 maximum registers.
    program_counter: usize, // counter field, used to track the current instruction position. 
}

// Implementation of UM.
// Methods: new, run, fetch, execute.
impl UniversalMachine {
    // Public constructor method for a new Universal Machine
    // Arguments 1: Vec of U32s representing the instructions of the initial program.
    pub fn new(initial_program: Vec<u32>) -> Self {
        let mut machine = Self { // intializes a UM struct object.
            memory: memory::Memory::new(), //calls constructor for memory segemnts.
            registers: [0; NUM_REGISTERS], //initializes 8 registers
            program_counter: 0, //Starts at counter 0; to work thorugh instructions.
        };

        machine.memory.load_program(initial_program); // Load the initial program into the '0' segment in memory, within the machine.

        machine // returns the intialized UM
    }
    
    // Public Run Method to initiate machine operations.
    // Arguments: 1 - A reference to the machine.
    pub fn run(&mut self) {
        // Loop through all instructions
        loop {
        // DEBUG PRINT    println!("Before: program_counter = {}", self.program_counter);
            let instruction = self.fetch_instruction(); // set the instruction to one associate with program counter.
            if !self.execute_instruction(instruction) { // If the instruction can not be executed
                break; // return false and halt program.
            }
            self.program_counter += 1; //instruction done, increment...
        // DEBUG PRINT    println!("After: program_counter = {}", self.program_counter);
        } 
    }

    // Private fetch method for retrieving an instruction from memory.
    fn fetch_instruction(&self) -> u32 {
        self.memory.read_instruction(self.program_counter) // Fetch instruction from the '0' segment at the current program counter.
    }

    // Private Execution Function:
    // Arguments: 2 - Mutable reference to the machine, and a u32 representing an instruction.
    // Returns a Boolean indicating success or fail of instruction.
    // Instruction can be 0-14 and pairs to corresponding match.
    fn execute_instruction(&mut self, instruction: u32) -> bool {
        let opcode = instruction >> 28;
        match opcode {
            0 => instructions::cond_move(instruction, &mut self.registers), //Conditional Move
            1 => instructions::seg_load(instruction, &mut self.memory, &mut self.registers), //Segment Load
            2 => instructions::seg_store(instruction, &mut self.memory, &mut self.registers), //Segment Store
            3 => instructions::add(instruction, &mut self.registers), //Addition
            4 => instructions::multiply(instruction, &mut self.registers), //Multiplication
            5 => instructions::divide(instruction, &mut self.registers), //Division
            6 => instructions::bitwise_nand(instruction, &mut self.registers), //Bitwise NAND
            7 => return false,  // Halt
            8 => instructions::execute_map_segment_instruction(instruction, &mut self.memory, &mut self.registers), //Map
            9 => instructions::execute_unmap_segment_instruction(instruction, &mut self.memory, &mut self.registers), //Unmap
            10 => instructions::output(instruction, &mut self.registers), //Output
            11 => instructions::input(instruction, &mut self.registers), //Input
            12 => instructions::load_program(instruction, &mut self.memory, &mut self.registers, &mut self.program_counter), //Load Program
            13 => instructions::load_value(instruction, &mut self.registers), //Load Value
            _ => panic!("Invalid opcode"), // Anything Else - Not Valid.
        }
        true //if exiting the match; operation was a success.
    }
}