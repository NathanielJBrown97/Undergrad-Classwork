use csc411_image::{Read, GrayImage}; //enables the 'Read and GrayImage' modules from the 411csc package.
use std::env; //enables the standard environment package. 

fn main() {

    let input = env::args().nth(1);  // variable to store CLA passed into the program. (Using env) .nth selects the position 1 argument. (filename)
    assert!(env::args().len() == 2, "Error Message: Incorrect Number of Arguments"); // if more than 1 argument, error message.

    let img = GrayImage::read(input.as_deref()).unwrap(); //define our image as a GrayImage package structure. .as_deref will convert the string to a reference (As per requirements of Options<&str> not Option<str>) Finally unwrap will extract the image.
    
    let denom = img.denominator as u32;

    let mut total_value = 0 as u32; // mutable total tally.

    for pixel in img.pixels{
        let cur_pixel_val = pixel.value as u32;

        total_value += cur_pixel_val;
 //       println!("Denominator of current pixel: {:?}", cur_pixel_val);
    }
    let length = img.height * img.width as u32;
    let avg_pixel_bri =   total_value / length;
    let normalized_brightness = (avg_pixel_bri as f32) / (denom as f32);
    println!("{:.3}" , normalized_brightness);
}


