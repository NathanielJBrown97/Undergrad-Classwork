extern crate csc411_image; //crate for pgms / GrayImage prebuilt class
extern crate array2; //import custom array2

use std::env; //using standard enviorenement module; for cla access
use csc411_image::{GrayImage, Read}; //read grayimage from csc411 crate - used to store/read image

fn main() {
    let input = env::args().nth(1); //set the input to the first argument (i.e. filename)
    let image = GrayImage::read(input.as_deref()).unwrap(); //reads the image from input

    // Check if the image is a valid Sudoku solution
    if is_valid_sudoku(&image) { //if helper function returns true; exit(0)
        std::process::exit(0); // Sudoku is valid
    } else { //otherwise its false; exit(1)
        std::process::exit(1); // Sudoku is not valid
    }
}


//HELPER FUNCTION - Check if valid sudoku board; passed our image and returns a boolean (valid or not)
fn is_valid_sudoku(image: &csc411_image::GrayImage) -> bool {
    // Extract dimensions from the image
    let width = image.width as usize;
    let height = image.height as usize;

// If image is not 9x9; not sudoku and is invalid.
    if width != 9 || height != 9 || image.denominator != 9 {
        return false;
    }

// CHECK FOR - Duplicates in Row, Column

    for i in 0..9 {    //iterate through row
        let mut row_set = [false; 9]; //set row array; to track values (as false or true)
        let mut col_set = [false; 9]; //set col array; to track values.

        for j in 0..9 {     //iterate through column
            let row_value = image.pixels[i * width + j].value as usize - 1; //set value of current cell - for row
            let col_value = image.pixels[j * width + i].value as usize - 1; //set value of current cell - for column

            if row_set[row_value] || col_set[col_value] { //if the row value or col value is already in set
                return false; // DUPLICATE - False sudoku
            }

            row_set[row_value] = true; //mark current row/col as true
            col_set[col_value] = true;
        }
    }

// CHECK FOR - Duplicates in 3x3
    for i in 0..3 { //iterate through rows
        for j in 0..3 { //and columns
            let mut subgrid_set = [false; 9]; //set array of false 

            for row_offset in 0..3 { //iterate through offset row
                for col_offset in 0..3 { //and columns
                    let value = image.pixels[(i * 3 + col_offset) * width + j * 3 + row_offset].value as usize - 1; //set value of current cell

                    if subgrid_set[value] { //if the value is already in subgrid_set
                        return false; // DUPLICATE - False sudoku
                    }

                    subgrid_set[value] = true; //otherwise set value to true
                }
            }
        }
    }

    true // If we make it this far without flipping a false return; sudoku is true.
}
