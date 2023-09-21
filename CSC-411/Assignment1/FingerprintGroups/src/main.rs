use std::collections::HashMap;
use std::io::{self, BufRead};

fn main() {
    let mut hashmap_data: HashMap<String, Vec<String>> = HashMap::new(); //Man Variant; hashmap containing key: of type string and value of type vec of strings.

    //read lines from standard input, lock it to standard input.
    for line in io::stdin().lock().lines() {
        //Try to read current line
        let current_input = match line {
            Ok(line) => line, //if read, store in line
            Err(_) => { //if not read, print error reading line
                eprintln!("ERROR: Cannot line read input");
                continue;
            }
        };

        //split the current input by whitespace and store them in vec of strings 
        let parts_of_input: Vec<&str> = current_input.trim().split_whitespace().collect();

        
        //If more than 2 parts of input
        if parts_of_input.len() >= 2 {
            let fingerprint = parts_of_input[0].to_string();
            let name = parts_of_input[1..].join(" ").to_string(); //join all parts after the first including whitespace

            //if group length exceeds 512 stderr
            if fingerprint.len() > 512 {
                // Fingerprint is too long, write an error message to stderr and continue.
                eprintln!("ERROR: Fingerprint exceeds 512 characters --> {}", fingerprint);
                continue;
            }

            //if name length exceeds maximum usize
            if name.len() > usize::MAX {
                // Name is too long, write an error message to stderr and continue.
                eprintln!("ERROR: Name is too long!");
                continue;
            }

            // check if the fingerprint is within the map
            match hashmap_data.get_mut(&fingerprint) {
                Some(current_name) => {
                    //if it exists, push the name into the associated key within the map
                    current_name.push(name);
                }
                None => {
                    //if no match is found, add the whole key:value pair.
                    hashmap_data.insert(fingerprint, vec![name]);
                }
            }
        } else {
            // If none of this happens; the input must be terrible
            eprintln!("ERROR: Badly formed input line --> {}", current_input);
        }
    }

    let mut remaining_fingerprints = hashmap_data.len(); // Goober Solutions; represents length of hashmap.

    // Iterate over the entries in the HashMap
    for (fingerprints, name) in &hashmap_data {
        //Handles first fgroup post; so that new lines are added properly.
        // If remaining fingerprints is equal to the length of our hashmap --- NO NEW LINE; print first group.
        if (remaining_fingerprints == hashmap_data.len()) && (name.len() > 1){
            remaining_fingerprints -= 1; //decrement remaining
            if let Some(values) = hashmap_data.get(fingerprints){
                for name in values{
                    println!("{}", name);
                }
            }
        }
        // if the vector of names has more than 1 entry        
        else if name.len() > 1 {
            println!(); //print new line 
            //iterate through the names printing them.
            if let Some(values) = hashmap_data.get(fingerprints){
                for name in values{
                    println!("{}", name);
                }
            }
        }
    }
}

