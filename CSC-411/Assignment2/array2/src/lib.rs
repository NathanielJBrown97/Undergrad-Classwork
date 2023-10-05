pub struct Array2<T: Clone> {
    // Store the width of the array
    pub width: usize,
    // Store the height of the array
    pub height: usize,
    // Store the actual data as a one-dimensional Vec
    pub data: Vec<T>,
}

impl<T: Clone> Array2<T> {
    pub fn new(width: usize, height: usize, initial_value: T) -> Self {
        // Allocate a new Vec<T> with the desired initial value.
        let mut data = Vec::new();
        for _i in 0..width {
            for _j in 0..height {
                let this_initial_value = initial_value.clone();
                data.push(this_initial_value);
            }
        }

        // Initialize the Array2<T> struct with the new Vec<T>.
        Array2 {
            width,
            height,
            data,
        }
    }

    // Getter Method
    pub fn get(&self, column: usize, row: usize) -> Option<&T> {
        self.get_index(column, row).map(|index| &self.data[index])
    }

    // Mutable Getter Method
    pub fn get_mut(&mut self, column: usize, row: usize) -> Option<&mut T> {
        self.get_index(column, row).map(move |index| &mut self.data[index])
    }

    // Get index method
    fn get_index(&self, column: usize, row: usize) -> Option<usize> {
        if column < self.width && row < self.height {
            Some(row * self.width + column)
        } else {
            None
        }
    }

}

