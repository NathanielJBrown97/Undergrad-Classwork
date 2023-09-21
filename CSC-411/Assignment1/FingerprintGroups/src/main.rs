use std::collections::HashMap;
use std::io;

fn main() {
    // Create a mutable HashMap to store fingerprint and name pairs
    // _ , _ - type inference. As long as consisten, this way dont need to define which types.
    let mut hashmap_data: HashMap<String , Vec<String>> = HashMap::new(); //types were reference in class?


    for line in io::stdin().lines() {
        // Create a mutable String to store user input
        let current_input = line.unwrap(); 

        // Split and collect the input by whitespace, push those values into the vector of strings
        let parts_of_input: Vec<&str> = current_input.trim().split_whitespace().collect();

        // Check if there are at least two parts within the vector (fingerprint and name)
        if parts_of_input.len() >= 2 {
            // Store the first part in the vector as the fingerprint.
            let fingerprint = parts_of_input[0].to_string();

            // store ALL elements from the 1st element till the end of the vector, seperated by whitespaces as the name.
            let name = parts_of_input[1..].join(" ").to_string();

            match hashmap_data.get_mut(&fingerprint) {
                //if key exists; add to the value vector of strings.
                Some (current_name) => {
                    current_name.push(name);
                }
                None => { hashmap_data.insert(fingerprint, vec![name]);}
            }
        } 
    }

    let mut remaining_fingerprints = hashmap_data.len(); // SOLUTION?
    // Iterate over the entries in the HashMap
    for (fingerprints, name) in &hashmap_data {
        // Check if the vector associated with the key has more than 1 element
        if name.len() > 1 {
            if let Some(values) = hashmap_data.get(fingerprints){
                for name in values{
                    println!("{}", name);
                }
            }
        }
        remaining_fingerprints -= 1; // finished one of our groups, decrement.
        if remaining_fingerprints != 0 {
    // newline inbetween fgroups
            println!();
         }

    
    }
}

    // //PRINTS ALL ALL VALUES SEPERATED BY GROUP
    // //iterate through the fingerprints
    // let mut remaining_fingerprints = hashmap_data.len(); // SOLUTION?

    // for fingerprints in hashmap_data.keys() {
    //     // Access the associated values using get
    //     if let Some(values) = hashmap_data.get(fingerprints) {
    //         if hashmap_data.len() > 1 {
    //             for name in values {
    //                 println!("{}", name);
    //             }
    //         }
    //     }
    //     remaining_fingerprints -= 1; // finished one of our groups, decrement.
    //     if remaining_fingerprints != 0 {
    //         // newline inbetween fgroups
    //         println!();
    //     }
    // }
//}
