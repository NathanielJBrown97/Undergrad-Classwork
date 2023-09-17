// standard library 'env' module i.e. enviorenment module. (Used for CLA access)
use std::env;
//use csc411_image::{GrayImage, read};

fn main() {
    // Collect CLA
    // Let is declaration - colon indicates data type of variable 'arguments'
    // Vec<String> Vector of Strings.
    // env::args() function call that finds CLA's as iterators - using enviorenment module.
    // .collect() is a method helper called on the enviorenment arguments (Stores them into a collection)
    // I.E. declares arguments variable as a vector of strings, and uses module to loop through and collect arguments in the CL.
    //
    // Will rewrite this to be more applicable - wanted to test.
    let arguments: Vec<String> = env::args().collect();

    //checking lenght of arguments vector
    println!("{}", arguments.len());
    
    //prints arguments to terminal
    println!("{:?}", arguments);

    //// IF -- more than 1 argument -> halt w/ error message using assert()
    // if the length is >= 2, then panic and send the error msg.
    assert!(arguments.len() <= 2, "Error Message: More than 1 argument provided...");

    //Extract first argument
    let cla_string = &arguments[1];
    
    //Print the argument
    println!("Command Line String: {}", cla_string);

    // Part A of A1 PDF:
    // - Wait for Lab to be posted; do lab, then continue.

    // Sets input variable to the enviorenment package arguments variable, specifically the 'Nth' member variable passed 1.
    //let input = env::arguments().nth(1);

    // Sets image variable to grayImage package, using read member function passed the abovedefined 'input'.
    // GrayImage section - is an 'option type' - Type that has two possible values, what is in the brackets (GrayImage), the other value is none.
    // Unwrap will check if the above is a gray image, if it is good. IF NOT - panic. 
    //let image = GrayImage::read(input.as_deref()).unwrap();
}
