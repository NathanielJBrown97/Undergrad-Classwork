Nathaniel Brown
11/16/2023
CSC 411 - A5 RUM

Rust Universal Machine Documentation

Invariants:
There are two main invariants that I can identify at this stage; although there may be more later on as I start working through the assignment. The first is the existence of a Segment 0; as stated in class and the assignment, there is always at least 1 segment. This is a given, that 1 segment is memory segment 0. Along with this is the existence of identifiers for the memory segments themselves that distinguish themselves from one another.

Segment 0:
This will be the primary invariant as it must always exist in order for the program as a whole to exist. It contains the program currently being executed, without it everything would be jumbled, nonsensical and not held together.

Unique Segment Identifiers:
Each memory segment will have its own identifier; these are represented later on when I describe how I plan to represent the memory segments via a data structure. Essentially they will be stored via the key in a HashMap as a u32. Without these identifiers it would be impossible to determine which memory segment is which, and consistently reference them as needed throughout the program.

Data Structures Per Part of UM and Where They’re Stored:
General Purpose Registers (GPR): The UM will have 8 gprs that will each store a word. 
Data Structure Representation: Vector of U32s with a specified size of 8 elements. (You can view this in the Architecture UM struct).
Storage Location: The main struct representing the Universal Machine. 
Memory Segment(s): The memory segments will always contain at least one or more memory segment(s). This is the allocated memory to store instructions. Each individual segment will be determined by a unique identifier (32 bit word).
Data Structure Representation: HashMap <u32, Vec<u32>> That is representative of the 32bit keys, and their pair of 32 bit word values. I.e. Segment Identifier (u32) and the content of the segment itself (Vec<u32>>).
Storage Location: This main struct representing the Universal Machine
Counter: This will represent a register used to track the address of the next instruction queued. Stored in segment 0.
Data Structure Representation: A u32 will store the address. 
Storage Location: Again, this will be stored in the UM struct that will be initialized within main.

Architecture (Organization and Decoupled for Unit Testing):
In order to ensure the elements of the Universal Machine are decoupled and easily testable on a piece by piece basis I will separate the entire program into a series of modules handling specific aspects of the programs overall functionality. I will define my initial plan for them below:

Main.rs:
Main will be the initializing point for the entire program, it will handle the command line arguments (1 argument), boot the Universal Machine (through UM.rs), and then initiate the main loop within UM.

UM.rs:
This will be used to set the UniversalMachine Struct seen below:
Struct UniversalMachine {
	Gpr_vec: [u32; 8] // Representative of the 8 general purpose registers.
	Memory: HashMap <u32, Vec<u32>> // Memory stored in hashmap
	Counter:  u32  // Program Counter
}
This will contain methods for initializing the machine and loading the appropriate memory specified via cla’s specifications and calling the helper modules.


Memory.rs:
This will handle all of the memory segment operations. Memory.rs will facilitate the creation, modification, and deletion of each individual memory segment.

Register.rs:
This will control the operations within the general purpose registers, as well as all functions for modifying / accessing the universal machine’s registers.

Instructions.rs:
This will define each of the 14 instructions and how to handle their execution. By creating various functions to initiate depending upon the given instruction. I will also write the logic that will help decode the execution instructions.

Counter.rs: 
This will have the functions for updating and checking the program counter. (This could probably be done elsewhere; I’m internally debating if it’s worthy of it’s own module).


Testing Plan Per Part:
Below I will detail the areas I believe will be important to ensure are working as intended to avoid complications and bugs in the future:

Registers.rs:
I will develop unit tests to handle two primary vulnerable points. First I will handle the setting and getting. Second I will test the boundaries for the register, to ensure there are no overflows.

Memory.rs:
In memory I will write tests that ensure creation, modification, and deletion of segments is working as intended. As well again I will write boundary tests to ensure accessing invalid segments or out of bounds access is handled properly.

Instructions.rs:
Each individual instruction will need to be tested. More importantly these tests need to ensure the individual instruction executions properly integrate within the general purpose registers and memory segments. (This will be the heaviest on unit testing as far as I am expecting currently).

Counter.rs:
Counter could have a test to ensure resetting / shifting the u32 happens properly, and boundary testing to ensure no out of segment access is attempted.
