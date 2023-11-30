mod um; //um library
use um::UniversalMachine; //universal machine struct import

mod memory;
mod instructions;

use std::env; // Enviorenment Module for CLA access
use std::fs::File; 
use std::io::Read; // io for reading.


fn main() {
    // Get the UM program file from command line arguments
    let args: Vec<String> = env::args().collect();
    let filename = &args[1];

    // Read the UM program file
    let mut file = File::open(filename).expect("Unable to open file");
    let mut program_bytes = Vec::new();
    file.read_to_end(&mut program_bytes).expect("Error reading file");

    // Convert the program bytes to a Vec<u32>
    let initial_program = bytes_to_u32(program_bytes);
// DEBUG PRINT    
// for element in &initial_program {
//     println!("{}", element);
// }
    // Initialize the Universal Machine with the initial program
    let mut um = UniversalMachine::new(initial_program);

    // Run the UM program
    um.run();
}

// Helper function to convert a vector of bytes into a vector of u32
fn bytes_to_u32(bytes: Vec<u8>) -> Vec<u32> {
    bytes.chunks(4).map(|chunk| {
        let mut buffer = [0u8; 4];
        buffer.copy_from_slice(chunk);
        u32::from_be_bytes(buffer)
    }).collect()
}
