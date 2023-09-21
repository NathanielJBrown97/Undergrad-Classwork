use csc411_image::{Read, GrayImage}; //enables the 'Read and GrayImage' modules from the 411csc package.
use std::env; //enables the standard environment package. 

fn main() {

    let input = env::args().nth(1);  // variable to store CLA passed into the program. (Using env) .nth selects the position 1 argument. (filename)
    assert!(env::args().len() == 2, "Error Message: Incorrect Number of Arguments"); // if more than 1 argument, error message.

    let img = GrayImage::read(input.as_deref()).unwrap(); //define our image as a GrayImage package structure. .as_deref will convert the string to a reference (As per requirements of Options<&str> not Option<str>) Finally unwrap will extract the image.
    
    let denom = img.denominator as u32; // initialize denominator for normalization of brightness average later.

    let mut total_value = 0 as u32; // initialize  a total value counter for the brightness values.

    // iterate through the pixels vector within our image
    for pixel in img.pixels{
        //take the current pixels value, and add it into our total
        let cur_pixel_val = pixel.value as u32;
        total_value += cur_pixel_val;
    }
    
    let length = img.height * img.width as u32; // set the length of our vector = to the height * width of the img object.
    let avg_pixel_bri =   total_value / length; //set the average brightness equal to the total / by the length 
    let normalized_brightness = (avg_pixel_bri as f32) / (denom as f32); // normalize this average by dividing by the denominator
    
    println!("{:.3}" , normalized_brightness); // Print the normalized brightness according to the rules. 3 decimals after .
}
