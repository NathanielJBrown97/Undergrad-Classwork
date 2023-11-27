use array2::Array2; //Custom 2d array represented in linear fashion - Credit to Professor Daniels
use csc411_image::{RgbImage, Write}; // Custom CSC411 library with RGBImage structure and methods, as well as a write function.

//TESTING
use std::time::Instant;

// Take given image and rotate 180 degrees
// Arguments: 2 - Source Image and a given major_order. Returns: Nothing, writes a transformed ppm
pub fn rotate180(src: &mut Array2<csc411_image::Rgb>) {

//TESTING
let now = Instant::now();

    // Width and Height stay the same for 180
    let rotated_width = src.width();
    let rotated_height = src.height();
    let mut rotated = Array2::new(rotated_width, rotated_height, src.get(0, 0).cloned().unwrap()); // create a new mutable Array2, with the rotated width/heights.

    // ALL MAJORS -- iterate through the columns and rows
    for c in 0..rotated_width {
        for r in 0..rotated_height {
            // Take the value at each position in the array and get the value from the source image at [column - 1 - column , row - 1 - row] position. 
            if let Some(value) = src.get(rotated_width - 1 - c, rotated_height - 1 - r) {
                rotated.get_mut(c, r).map(|rotated_value| *rotated_value = value.clone()); //Get mutable reference at current position, apply transformation, assign the rotated value to a clone of the source value.
            }
        }
    }

//TESTING
let elapsed = now.elapsed();
eprintln!("{:.4?}", elapsed);

    // Create an output structure of RbgImage type
    let output = RgbImage {
        pixels: rotated.data, //set pixels to the rotated data
        width: rotated.width as u32,
        height: rotated.height as u32,
        denominator: 255,
    };

    output.write(None).unwrap(); // use the CSC411 library's write function to write this output to ppm/stout
}
