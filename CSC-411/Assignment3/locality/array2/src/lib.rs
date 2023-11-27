// Credit for this library goes to Professor Daniels at the University of Rhode Island - Using this as a basis for the rotation aspect of the assignment.

//! `Array2` provides a fixed-size 2-dimensional array.
//! Elements contained must implement `Clone`.
#[derive(Debug, Clone, Eq, PartialEq)]
pub struct Array2<T: Clone> {
    pub width: usize,
    pub height: usize,
    pub data: Vec<T>,
}

impl<T: Clone> Array2<T> {
    /// Creates a new `Array2` containing identical
    /// values for every element.
    ///
    /// # Arguments
    ///
    /// * `width`: the width of the `Array2`.
    /// * `height`: the height of the `Array2`.
    /// * `val`: the value to fill every element with
    ///
    /// # Returns
    ///
    /// * An `Array2` of appropriate dimensions containing copies of `val`
    ///
    /// # Examples
    ///
    /// ```
    /// use array2;
    /// let a = Array2::new(2, 3, 42_u32);
    /// ```
    pub fn new(width: usize, height: usize, val: T) -> Self {
        let data = vec![val; width * height];
        Array2 {
            width,
            height,
            data,
        }
    }

    /// Creates a new `Array2` from a `Vec<T>`.
    ///
    /// # Arguments
    ///
    /// * `width`: the width of the `Array2`
    /// * `height`: the height of the `Array2`
    /// * `values`: A `Vec<T>`, in row-major order, whose
    ///             `length` must be `width * height`.
    /// # Returns
    ///
    /// * A `Result<Array2<T>, Error>` where the Array2 is of appropriate dimensions containing the
    /// elements of `values` as presented in row-major order.
    /// If the number of elements in `values` is not equal to `width*height`, the `Result` contains an error.
    ///
    pub fn from_row_major(width: usize, height: usize, values: Vec<T>) -> Result<Self, String> {
        if width * height != values.len() {
            Err(format!(
                "Values has {} elements, which is not the product of width {} and height {}",
                values.len(),
                width,
                height,
            ))
        } else {
            Ok(Array2 {
                width,
                height,
                data: values,
            })
        }
    }

    /// Creates a new `Array2` from a `Vec<T>`.
    ///
    /// # Arguments
    ///
    /// * `width`: the width of the `Array2`
    /// * `height`: the height of the `Array2`
    /// * `values`: A `Vec<T>`, in column-major order, whose
    ///             length must be `width * height`.
    /// # Returns
    ///
    /// * An `Array2` of appropriate dimensions containing the
    /// elements of `values` as presented in column-major order

    pub fn from_col_major(width: usize, height: usize, values: Vec<T>) -> Result<Self, String> {
        if width * height != values.len() {
            Err(format!(
                "Values has {} elements, which is not the product of width {} and height {}",
                values.len(),
                width,
                height,
            ))
        } else {
            Ok(Array2 {
                width,
                height,
                data: (0..height)
                    .map(|r| values.iter().skip(r))
                    .flat_map(|row| row.step_by(height))
                    .cloned()
                    .collect(),
            })
        }
    }

    /// The height
    pub fn height(&self) -> usize {
        self.height
    }

    /// The width
    pub fn width(&self) -> usize {
        self.width
    }

    /// Returns an immutable reference to the element at the given `column` and `row`
    /// as long as that index is in bounds
    /// (wrapped in [`Some`]). Returns [`None`] if out of bounds.
    ///
    /// # Arguments
    ///
    /// * `c`: the column index.
    /// * `r`: the row index.
    ///
    /// # Returns
    ///
    /// * An `Option<&T>` which is a reference to the value at
    /// coordinates `(c,r)` if those indices are in bounds,
    /// and `None` otherwise.
    pub fn get(&self, c: usize, r: usize) -> Option<&T> {
        self.get_index(c, r).map(|index| &self.data[index])
    }

    /// Returns an immutable reference to the element at the given `column` and `row`
    /// as long as that index is in bounds
    /// (wrapped in [`Some`]). Returns [`None`] if out of bounds.
    ///
    /// # Arguments
    ///
    /// * `c`: the column index.
    /// * `r`: the row index.
    ///
    /// # Returns
    ///
    /// * An `Option<&mut T>` which is a mutable reference to the value at
    /// coordinates `(c,r)` if those indices are in bounds,
    /// and `None` otherwise.
    pub fn get_mut(&mut self, c: usize, r: usize) -> Option<&mut T> {
        self.get_index(c, r).map(move |index| &mut self.data[index])
    }

    /// helper function which implements the representation invariant
    /// returns an `Option<usize>` which is the index in the
    /// internal `data` `Vec` of the requested element if it's in bounds,
    /// and `None` otherwise
    fn get_index(&self, c: usize, r: usize) -> Option<usize> {
        if c < self.width && r < self.height {
            Some(r * self.width + c)
        } else {
            None
        }
    }

    /// An Iterator over the values of the underlying
    /// representation.
    ///
    /// # Returns
    ///
    /// * An `Iterator<Item = &elem>` which is a reference to a contained value.
    fn _iter_values(&self) -> impl Iterator<Item = &T> {
        self.data.iter()
    }

    /// Returns an iterator over the rows of the underlying
    /// representation.
    ///
    /// # Returns
    ///
    /// * An `Iterator<Item = (row, &elem)>` which is a 2-tuple holding the row index and
    /// a reference to a contained value.
    fn iter_rows(&self) -> impl Iterator<Item = (usize, impl Iterator<Item = &T>)> {
        self.data
            .chunks(self.width)
            .enumerate()
            .map(|(i, row)| (i, row.iter()))
    }

    /// An Iterator over the values of the `Array2` in row-major order.
    ///
    /// # Returns
    ///
    /// * An `Iterator<Item = (col, row, &elem)>` which is a 3-tuple holding the column index,
    /// row index, and a reference to a contained value.
    pub fn iter_row_major(&self) -> impl Iterator<Item = (usize, usize, &T)> {
        self.iter_rows()
            .flat_map(|(r, row)| row.enumerate().map(move |(c, element)| (c, r, element)))
    }

    /// Returns an iterator over the columns of the underlying
    /// representation.
    ///
    /// # Returns
    ///
    /// * An `Iterator<Item = (col, &elem)>` which is a 2-tuple holding the column index and
    /// a reference to a contained value.
    fn iter_cols(&self) -> impl Iterator<Item = (usize, impl Iterator<Item = &T>)> {
        (0..self.width)
            // get the start of every column as a fresh iter and keep the index of the column
            .map(move |c| (c, self.data.iter().skip(c)))
            // for each iterator on a column, step forward by width for the correct next element in that column
            .map(move |(c, col_start)| (c, col_start.step_by(self.width)))
    }

    /// An Iterator over the values of the `Array2` in column-major order.
    ///
    /// # Returns
    ///
    /// * An `Iterator<Item = (col, row, &elem)>` which is a 3-tuple holding the column index,
    /// row index, and a reference to a contained value.
    pub fn iter_col_major(&self) -> impl Iterator<Item = (usize, usize, &T)> {
        self.iter_cols()
            .flat_map(|(c, col)| col.enumerate().map(move |(r, element)| (c, r, element)))
    }
}
