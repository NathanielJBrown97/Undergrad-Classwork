# Rust Universal Machine (RUM) Documentation
## Nathaniel Brown
### CSC 411 - A5 RUM - 11/16/2023

## Invariants
- **Segment 0 Existence:** Always at least one segment, Segment 0 is essential for the program's operation.
- **Unique Segment Identifiers:** Each memory segment has a unique identifier, crucial for distinguishing and referencing memory segments.

## Data Structures
- **General Purpose Registers (GPR):** 8 GPRs, each storing a word.
  - **Representation:** Vector of U32s, size 8.
  - **Storage:** Main struct of Universal Machine.
- **Memory Segments:** Contain instructions, identified by unique identifiers.
  - **Representation:** HashMap <u32, Vec<u32>>, for segment identifiers and content.
  - **Storage:** Main struct of Universal Machine.
- **Counter:** Tracks the address of the next instruction.
  - **Representation:** A u32 for the address.
  - **Storage:** In the UM struct, initialized in main.

## Architecture and Modularity
- **Decoupled Modules for Testing:** Separating program into modules for specific functionalities.
- **Main.rs:** Initializes the program, handles command-line arguments, and starts the main loop.
- **UM.rs:** Sets up the UniversalMachine struct and contains methods for initializing and loading memory.
- **Memory.rs:** Manages memory segment operations like creation, modification, and deletion.
- **Register.rs:** Controls operations within GPRs and functions for modifying/accessing them.
- **Instructions.rs:** Defines the 14 instructions, their execution, and logic for decoding.
- **Counter.rs:** Functions for updating and checking the program counter.

## Testing Plan
- **Registers.rs:** Tests for setting/getting, and boundary tests for overflow prevention.
- **Memory.rs:** Tests for segment creation, modification, deletion, and boundary tests for access.
- **Instructions.rs:** Tests for each instruction's execution and integration with GPRs and memory segments.
- **Counter.rs:** Tests for resetting/shifting the counter and boundary tests for segment access.

---

*This document summarizes the design aspects and testing plan of the Rust Universal Machine (RUM) for the CSC 411 assignment.*
