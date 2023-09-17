use csc411_image::{Read, GrayImage}; //enables the 'Read and GrayImage' modules from the 411csc package.
use std::env; //enables the standard environment package. 

fn main() {

    let input = env::args().nth(1);  // variable to store CLA passed into the program. (Using env) .nth selects the position 1 argument. (filename)
    assert!(env::args().len() == 2, "Error Message: Incorrect Number of Arguments"); // if more than 1 argument, error message.
    //DO I NEED ADDITIONAL HALT CONDITIONS?
    //WHAT DOES IT MEAN BY READ STANDARD INPUT, IF GRAYSCALE PROMISED, BUT NOT DELIEVERED. 


    let img = GrayImage::read(input.as_deref()).unwrap(); //define our image as a GrayImage package structure. .as_deref will convert the string to a reference (As per requirements of Options<&str> not Option<str>) Finally unwrap will extract the image.
    
    let h = img.height; // sets a variable to the height of our image variable.
    let w = img.width; // sets a variable to the width of our image variable.
    println!("{:?} has dimensions width {} and height {}", input, w, h); //prints our output. in the order of input, w, h within the string.

    let mut total_pixel_value = 0; // mutable total tally.

    for y_height in 0..img.height {
        let current_y = y_height;
        for x_width in 0..img.width{
            let current_x = x_width;

            // CREATE A CURRENT PIXEL VALUE = X/Y VALUE, ADD IT TO TOTAL. REPEAT.
            //println!("Current Pixel: ({},{})", current_x, current_y);
        }
    }

    //TAKE TOTAL PIXEL VALUE, RUN CALCULATION TO DETERMINE BRIGHTNESS AND NORMALIZE IT TO 0-1 RANGE.
}

