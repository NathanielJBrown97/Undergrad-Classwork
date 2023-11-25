pub struct Memory {
    segments: Vec<Option<Vec<u32>>>,
    unmapped_ids: Vec<u32>,
}

impl Memory {
    pub fn new() -> Self {
        let initial_segments = vec![Some(Vec::new())]; // Initialize with the '0' segment
        Self {
            segments: initial_segments,
            unmapped_ids: Vec::new(),
        }
    }

    pub fn map_segment(&mut self, size: u32) -> u32 {
        let segment = vec![0; size as usize];

        if let Some(id) = self.unmapped_ids.pop() {
            self.segments[id as usize] = Some(segment);
            return id;
        }

        let id = self.segments.len() as u32;
        self.segments.push(Some(segment));
        id
    }

    pub fn unmap_segment(&mut self, id: u32) {
        if id >= self.segments.len() as u32 || self.segments[id as usize].is_none() {
            panic!("Unmap Segment: Invalid or unmapped segment");
        }
        self.segments[id as usize] = None;
        self.unmapped_ids.push(id);
    }

    pub fn load_program(&mut self, program: Vec<u32>) {
        self.segments[0] = Some(program);
    }

    pub fn read_instruction(&self, program_counter: usize) -> u32 {
        self.segments[0].as_ref().unwrap_or(&vec![])[program_counter]
    }
    // Method to get ref to segment
    pub fn get_segment(&self, segment_id: usize) -> Option<&Vec<u32>> {
        self.segments.get(segment_id).and_then(|segment| segment.as_ref())
    }
    
    pub fn write_memory(&mut self, segment_id: usize, offset: usize, value: u32) {
        // First, check if the segment_id is valid and the segment is mapped
        if let Some(segment) = self.segments.get_mut(segment_id) {
            if let Some(ref mut segment) = segment {
                // Check if the offset is within the bounds of the segment
                if offset < segment.len() {
                    segment[offset] = value;
                } else {
                    panic!("write_memory: Offset out of bounds");
                }
            } else {
                panic!("write_memory: Unmapped segment");
            }
        } else {
            panic!("write_memory: Invalid segment ID");
        }
    }
}
