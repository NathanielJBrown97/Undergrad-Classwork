// Memory Struct - Allowing for management of memory segments. 
// Contains individual segments, and IDs of unmapped segments.
pub struct Memory {
    segments: Vec<Option<Vec<u32>>>, // Vector of Option Vectors of U32s. Segment of memory is 1 vector of u32
    unmapped_ids: Vec<u32>, // Vector of u32s representing IDs of the segments that are unmapped and can be reused.
}

// Implementation of Memory:
// Contains methods for; new, map, unmap, load, read instruction, getter, and write_memory.
impl Memory {
    // Constructor
    pub fn new() -> Self {
        let initial_segments = vec![Some(Vec::new())]; // Initialize with the '0' segment
        Self {
            segments: initial_segments, // set the initial_segments
            unmapped_ids: Vec::new(), // set unmapped id's to a new vector.
        }
    }

    // Method to create new memory segment of given size.
    // Args: 2 - Ref Mut Self, and set size of segement.
    pub fn map_segment(&mut self, size: u32) -> u32 {
        let segment = vec![0; size as usize]; //initializes a vec to the given size as a segment

        if let Some(id) = self.unmapped_ids.pop() { // If there are any unmapped IDs, use one for the segment
            self.segments[id as usize] = Some(segment);
            return id; // return the id
        }

        // Otherwise; create a brand new id and segment
        let id = self.segments.len() as u32;
        self.segments.push(Some(segment));
        id
    }

    // Method to remove the segment by its ID
    // Args: 2 - self, and u32 of id.
    pub fn unmap_segment(&mut self, id: u32) {
        if id >= self.segments.len() as u32 || self.segments[id as usize].is_none() { // check if invalid or alerady unmapped
            panic!("Unmap Segment: Invalid or unmapped segment");
        }

        self.segments[id as usize] = None; // set the segment to None
        self.unmapped_ids.push(id); // add id to the unmapped ID's vector for reuse.
    }

    // Method to Load Program (Defaults to the 0 Segment)
    pub fn load_program(&mut self, program: Vec<u32>) {
        self.segments[0] = Some(program);
    }

    // Method to read instructions
    // Args: 2 - Self and a program counter (indicates instruction #)
    pub fn read_instruction(&self, program_counter: usize) -> u32 {
        //grabs 0 segment and finds instruction at given program counter value
        if let Some(segment) = self.segments.get(0).and_then(|seg| seg.as_ref()) {
            if program_counter < segment.len() { // if the counter is within the segment
                segment[program_counter]  // here is our instruction
            } else { //otherwise out of bounds
                panic!("read_instruction: Program counter out of bounds");
            }
        } else { // if 0 segment couldn't be accessed its unmapped.
            panic!("read_instruction: Segment 0 is unmapped");
        }
    }

    // Method to get ref to segment
    pub fn get_segment(&self, segment_id: usize) -> Option<&Vec<u32>> {
        self.segments.get(segment_id).and_then(|segment| segment.as_ref())
    }
    
    // Method to Write to Memory
    // Args: 4 - self, Segment_ID, Offset, and value
    pub fn write_memory(&mut self, segment_id: usize, offset: usize, value: u32) {
        // check if the segment_id is valid and the segment is mapped
        if let Some(segment) = self.segments.get_mut(segment_id) {
            if let Some(ref mut segment) = segment {
                // Check if the offset is within the bounds of the segment
                if offset < segment.len() {
                    segment[offset] = value; // if so; write the value to the offset.
                } else { //otherwise out of bounds
                    panic!("write_memory: Offset out of bounds");
                }
            } else { // if can't access...
                panic!("write_memory: Unmapped segment");
            }
        } else { // if can't get mut of index, it's not valid id.
            panic!("write_memory: Invalid segment ID");
        }
    }
}
