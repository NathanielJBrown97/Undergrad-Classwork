use array2::Array2; //Custom 2d array represented in linear fashion - Credit to Professor Daniels
use csc411_image::{RgbImage, Write}; // Custom CSC411 library with RGBImage structure and methods, as well as a write function.

// Take given image and rotate 270 degrees
// Arguments: 2 - Source Image and a given major_order, and a monkey method to determine recursive call base case. Returns: Nothing, writes a transformed ppm
pub fn rotate270(src: &mut Array2<csc411_image::Rgb>, major_order: &str, monkey_method: i8){
    // Swap width and height of the source image.
    let rotated_width = src.height(); 
    let rotated_height = src.width();
    let mut rotated = Array2::new(rotated_width, rotated_height, src.get(0, 0).cloned().unwrap()); // create a new mutable Array2, with the rotated width/heights.

    // FOR ROW_MAJOR -- Iterate through columns and rows in the width / height
    if major_order == "row_major" {
        for c in 0..rotated_width {
            for r in 0..rotated_height {
                // Take the value at each position in the array and get the value from the source image at [row - 1 - column] position. 
                if let Some(value) = src.get(r, rotated_width - 1 - c) {
                    rotated.get_mut(c, r).map(|rotated_value| *rotated_value = value.clone());  //Get mutable reference at current position, apply transformation, assign the rotated value to a clone of the source value.
                }
            }
        }
    }

    // FOR COL MAJOR -- Iterate through the ROWS, and then the columns in the height/width.
    if major_order == "col_major" {
        for r in 0..rotated_height {
            for c in 0..rotated_width {
                // Take the value at each position in the array and get the value from the source image at [row - 1 - column] position. 
                if let Some(value) = src.get(r, rotated_width - 1 - c) {
                    rotated.get_mut(c, r).map(|rotated_value| *rotated_value = value.clone()); //Get mutable reference at current position, apply transformation, assign the rotated value to a clone of the source value.
                }
            }
        }
    }

    
// MONKEY TIME

    //if monkey method recursion tactics have not decremented to 1, we aren't done rotating the image.
    if monkey_method != 1{
        rotate270(&mut rotated, major_order, monkey_method-1); //call again, but this time with the rotated image as our source, and a decremented monkey_method.
    }

    //if monkey methods have been sated, print for the sweet extra credit.
    if monkey_method == 1{
        // Create an output structure of RgbImage type
        let output = RgbImage {
            pixels: rotated.data, //set pixels to the rotated data
            width: rotated.width as u32, 
            height: rotated.height as u32,
            denominator: 255, 
        };

        output.write(None).unwrap(); //use the CSC411 library's write function to write this output to ppm/stdout
    }   
}
