pub struct Array2<T: Clone> {
    // Store the width of the array
    pub width: usize,
    // Store the height of the array
    pub height: usize,
    // Store the actual data as a one-dimensional Vec
    pub data: Vec<T>,
}

impl<T: Clone> Array2<T> {
    //Column Major Constructor: Args 3: Width, height of usize; and an initial value of type T. Returns an object of self; effectively fills a new array of the given size with a particular value.
    pub fn new(width: usize, height: usize, initial_value: T) -> Self {
        // Allocate a new Vec<T> with the desired initial value.
        let mut data = Vec::new();
        for _i in 0..width { //loop through the columns (width)
            for _j in 0..height { //in each column loop through the rows, height.
                let this_initial_value = initial_value.clone(); //clone the value we will fill the new array with
                data.push(this_initial_value); //push the value into the data vec; to ensure it is of proper size
            }
        }
        // Initialize the Array2<T> struct with the new Vec<T>.
        Array2 {
            width,
            height,
            data,
        }
    }

    //iterate by column major; Args: Ref to self and returns an Iterater by Column Major of a given type T.
    pub fn iter_col_major(&self) -> Array2ColMajorIter<T>{
        Array2ColMajorIter{
            array: self,
            row: 0,
            col: 0,
        }
    }

    //iterate by row major; Args: Ref to self and returns an iterator by row major of a given type T.
    pub fn iter_row_major(&self) -> Array2RowMajorIter<T>{
        Array2RowMajorIter{
            array: self,
            row: 0,
            col: 0,
        }
    }

    // Getter Method - Args 3: ref to struct,  given column / row. Returns option of ref T.
    pub fn get(&self, column: usize, row: usize) -> Option<&T> {
        self.get_index(column, row) //on given struct ref call index helper method, passed the row/col
            .map(|index| &self.data[index]) //map by index the given objects data at a given index
    }

    // Mutable Getter Method - functions the same as above; but passed a mut reference to the self object and returns a reference mutable.
    pub fn get_mut(&mut self, column: usize, row: usize) -> Option<&mut T> {
        self.get_index(column, row).map(move |index| &mut self.data[index])
    }

    // Get index method - Args: 3 reference to the object; and a given column and row. Returns Option of usize.
    fn get_index(&self, column: usize, row: usize) -> Option<usize> {
        if column < self.width && row < self.height { // if the column and row passed are within the bounds of the objects height/width
            Some(row * self.width + column) // it will return the index at row * column + column. 
        } else { //otherwise it's out of bounds
            None //return None.
        }
    }

    // setter method to set element at specific row/col: Args 3: MUTABLE ref to self object, row/column of usize, and the value to set of given T type. Returns a boolean of success/fail
    pub fn set(&mut self, row: usize, column: usize, value: T) -> bool {
        if row < self.width && column < self.height { //if the passed row/column are within the bounds of the objects width/height
            let index = column * self.width + row; //set the index to our formula column * column + row
            self.data[index] = value; //set the data at the index to the given value
            true
        } else { //otherwise out of bounds; return false.
            false
        }
    }

}

// Iterator Struct for column major iteration
pub struct Array2ColMajorIter<'a, T: Clone> { //generic params 'a (lifetime reference to array), and T for given Type in the array
    pub array: &'a Array2<T>, //declare array of a passed type with lifetime of 'a
    pub row: usize, 
    pub col: usize,
}

// Iterator Struct for Row Major iteration ---- same description as above.
pub struct Array2RowMajorIter<'a, T: Clone> {
    pub array: &'a Array2<T>,
    pub row: usize,
    pub col: usize,
}


// define a type called 'Item'; of a given type and lifetime 'a. Set it to a touple of generic params (usize, usize, reference to type of lifetime 'a)
type Item<'a, T> = (usize, usize, &'a T); //i.e. column, row, iterator

// implementation of iterator for Column Major Traversal: given a lifetime type T clone
impl<'a, T: Clone> Iterator for Array2ColMajorIter<'a, T> {
    type Item = Item<'a, T>;  //define the type of Item for iterator

    fn next(&mut self) -> Option<Self::Item> {  //next method takes mut ref to object; returns Option of objects item
        if self.col < self.array.width { //if given column is within bounds of objects width.
            let item = (self.row, self.col, &self.array.data[self.row * self.array.width + self.col]); //create touple item of cur row, col and ref to data at location.
            self.row += 1; //increment row
            if self.row == self.array.height { //if the current row is at the maximum for objects height
                self.row = 0; //set row to 0 (start)
                self.col += 1; //start next col
            }
            Some(item)  //return item
        } else { //otherwise outside of bounds; return None
            None
        }
    }
}

// implementation of iterator for row Major Traversal: given a lifetime type T clone
impl<'a, T: Clone> Iterator for Array2RowMajorIter<'a, T> {
    type Item = Item<'a, T>; //define the type of Item for iterator

    fn next(&mut self) -> Option<Self::Item> { //next method takes mut ref to object; returns Option of objects item
        if self.row < self.array.height { //if given row is within bounds of objects height.
            let item = (self.row, self.col, &self.array.data[self.row * self.array.width + self.col]); //create touple item of cur row, col and ref to data at location.
            self.col += 1; //increment column
            if self.col == self.array.width { //check if column is the max for objects width
                self.col = 0; //set column to start (0)
                self.row += 1; //move to next row
            }
            Some(item) //return the item
        } else { //otherwise out of bounds; return None
            None
        }
    }
}
