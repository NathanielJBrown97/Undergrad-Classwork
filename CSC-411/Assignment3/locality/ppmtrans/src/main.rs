extern crate clap; //clap crate used for command line argument parsing
use array2::Array2; //custom 2d representitve linear array - credit to Professor Daniels.
use csc411_image::{Read, RgbImage, Write}; //custom csc411 crate; includes RgbImage structure, methods, ect. 
use clap::Parser; // set clap crates parser trait for the argument structures

// Modules for Rotation - Modularization of Program
mod rotate90; //Args: array2, and major order - Returns: Writes new ppm/prints to stdout
mod rotate180; //Same as above
mod rotate270; //Args3: array2, major order, monkey_method counter. - Returns: Writes new ppm/prints to stdout

// Struct to contain arguments using Clap Parser
#[derive(Parser, Debug)]
#[clap(author, version, about, long_about = None)]
struct Args {
    #[clap(long)]
    rotate: Option<u32>, // set the rotation degree

    #[clap(long)]
    col_major: bool, // flag to specify column-major order

    #[clap(long)]
    row_major: bool, // flag to specify row-major order

    file: Option<String>, // given file name to transform
}




// Main creates an initial rgb image of the given ppm, then handles the appropriate conditionals to rotate or transform accordingly. (Which will call seperate modules.)
fn main() {
    let args = Args::parse(); 
    let image = RgbImage::read(args.file.as_deref()).unwrap(); // Set the initial image to what the RgbImage library reads from the passed filename collected from our CLAP

    // Sets the major order according to CLAP declaration
    let major_order = if args.col_major {
        "col_major"
    } else if args.row_major {
        "row_major"
    } else { //catch all to set row_major as default -- if not specified.
        "row_major"
    };

    // set width, height, and values to width, height, pixels of the rgb image defined above. 
    let (width, height, values) = match major_order {
        "row_major" => (image.width, image.height, image.pixels),
        "col_major" => (image.width, image.height, image.pixels),
        _ => { eprintln!("No not allowed."); return;} //In any scenario without a defined major_order error.
    };

    // Set the src image to an array2 of type RGB, read from row major.
    let mut src = Array2::from_row_major(width.try_into().unwrap(), height.try_into().unwrap(), values).unwrap();
 
    // Now that the source image is created; check clap argument for rotate degree.
    if let Some(degrees) = args.rotate {
        match degrees { //match to appropriate degree 
            0 => { //if 0, simply return the src image. 
                let output = RgbImage {
                    pixels: src.data,
                    width: src.width as u32,
                    height: src.height as u32,
                    denominator: 255,
                };
                output.write(None).unwrap(); //write the output to a ppm
            }
            90 => { // IF 90 DEGREES -- send a ref mut of source image, and major_order to the rotate 90 module/function.
                rotate90::rotate90(&mut src, major_order); 
            }
            180 => { // IF 180 DEGREES -- send a ref mut of source image, and major_order to the rotate 180 module/function.
                rotate180::rotate180(&mut src); 
            }
            270 => { // If 270 DEGREES -- send ref mut of source, major order, and a monkey_method recursive tracker of 3 to the 270 module/function.
                rotate270::rotate270(&mut src, major_order, 3);
            }
            _ => eprintln!("This has been rejected..."), //All other scenarios are being rejected.
        }
    }
            
}
