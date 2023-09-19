use std::collections::HashMap;
use std::io;

fn main() {
    // Create a mutable HashMap to store fingerprint and name pairs
    let mut hashmap_data: HashMap<String, String> = HashMap::new();

    loop {
        // Create a mutable String to store user input
        let mut current_input = String::new();
        
//TODO: Figure out how to properly take the input during help hours.
        // Read user current_input from the standard current_input (keyboard)
        println!("Input a Fingerprint followed by a name:");
        if io::stdin().read_line(&mut current_input).is_err() {
            break; 
        }

        // Split and collect the input by whitespace, push those values into the vector of strings
        let parts_of_input: Vec<&str> = current_input.trim().split_whitespace().collect();

        // Check if there are at least two parts within the vector (fingerprint and name)
        if parts_of_input.len() >= 2 {
            // Store the first part in the vector as the fingerprint.
            let fingerprint = parts_of_input[0].to_string();

            // store ALL elements from the 1st element till the end of the vector, seperated by whitespaces as the name.
            let name = parts_of_input[1..].join(" ").to_string();

            // insert a clone of these two values into the hashmap. Key(Fingerprint):Value(Name)
            hashmap_data.insert(fingerprint.clone(), name.clone());

//FOR TESTING PURPOSES - DELETE LATER
            println!("Fingerprint: {}", fingerprint);
            println!("Name: {}", name);
        } else {
//FOR TESTING PURPOSES - DELETE LATER
            println!("Invalid input. Please provide both a fingerprint and a name separated by a space.");
        }
    }

    // Print the contents of the HashMap after the loop.
    println!("Data in the HashMap:");
    for (fingerprint, name) in &hashmap_data {
        println!("Fingerprint: {}, Name: {}", fingerprint, name);
    }
}
