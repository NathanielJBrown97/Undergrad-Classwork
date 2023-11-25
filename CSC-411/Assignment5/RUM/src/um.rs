use self::memory::Memory;

mod memory;
mod instructions;

const NUM_REGISTERS: usize = 8;

pub struct UniversalMachine {
    memory: memory::Memory,  // Custom memory module to handle segmented memory.
    registers: [u32; NUM_REGISTERS],
    program_counter: usize,
}

impl UniversalMachine {
    pub fn new(initial_program: Vec<u32>) -> Self {
        let mut machine = Self {
            memory: memory::Memory::new(),
            registers: [0; NUM_REGISTERS],
            program_counter: 0,
        };

        // Load the initial program into the '0' segment.
        machine.memory.load_program(initial_program);

        machine
    }

    pub fn run(&mut self) {
        loop {
            let instruction = self.fetch_instruction();
            if !self.execute_instruction(instruction, &mut self.memory, &mut self.registers, &mut self.program_counter) {
                break;
            }
            self.program_counter += 1;
        }
    }

    fn fetch_instruction(&self) -> u32 {
        // Fetch instruction from the '0' segment at the current program counter.
        self.memory.read_instruction(self.program_counter)
    }

    fn execute_instruction(&mut self, instruction: u32, memory: &mut Memory, registers: &mut [u32; 8], program_counter: &mut usize) -> bool {
        let opcode = instruction >> 28;
        match opcode {
            0 => instructions::cond_move(instruction, registers),
            1 => instructions::seg_load(instruction, memory, registers),
            2 => instructions::seg_store(instruction, memory, registers),
            3 => instructions::add(instruction, registers),
            4 => instructions::multiply(instruction, registers),
            5 => instructions::divide(instruction, registers),
            6 => instructions::bitwise_nand(instruction, registers),
            7 => return false,  // Halt
            8 => instructions::execute_map_segment_instruction(instruction, memory, registers),
            9 => instructions::execute_unmap_segment_instruction(instruction, memory, registers),
            10 => instructions::output(instruction, registers),
            11 => instructions::input(instruction, registers),
            12 => instructions::load_program(instruction, memory, registers, program_counter),
            13 => instructions::load_value(instruction, registers),
            _ => panic!("Invalid opcode"),
        }
        true
    }
}
