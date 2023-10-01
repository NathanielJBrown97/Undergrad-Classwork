pub struct array2<T> {
    height: usize,
    width: usize,
    array: Vec<Vec<T>>,
}

impl<T> array2<T> {
    pub fn new(height: usize, width: usize, initial_value: T) -> Self {
        let data = vec![vec![initial_value; width]; height]; //fill data with a given value
        array2{
            height,
            width,
            array,
        }
    }
    // iterate by row major; using reference of self (array2). Returns an iterator of a given type.
    pub fn iter_row_major(&self) -> RowMajorIterator<T> {
        //tbd
    }
    // iterate by col major; using reference of self (array2). Returns an iterator of a given type.
    pub fn iter_col_major(&self) -> ColMajorIterator<T> {
        //tbd
    }

    // Getter function to find and grab the value at a given row/col.
    pub fn get(&self, row: usize, col: usize) -> Option<&T>{
        // if row and col are less height/width
            //grab data at those coords
        // otherwise
            // nothing, its out of bounds.
    }
    
    pub fn set(&mut self, row: usize, col: usize, value: T) --> bool {
        // if row and col are less than height/width
            //set coords to value
            //flip bool for success confirmation
        // otherwise
            //flip bool for coords out of bounds.
    }

}

