use std::collections::HashMap;
use std::io;

fn main() {
    // Create a mutable HashMap to store fingerprint and name pairs
    let mut hashmap_data: HashMap<String, String> = HashMap::new();

    let mut goober_solution = 0;
    while goober_solution < 4 {
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
        goober_solution += 1;
    }

//FOR TESTING PURPOSES - DELETE LATER
    // prints all key:vals within the hashmap
    println!("Data in the HashMap:");
    for (fingerprint, name) in &hashmap_data {
        println!("Fingerprint: {}, Name: {}", fingerprint, name);
    }

//TODO: IMPLEMENT GOOD DATA SORT
    //Start from top down? 
        //Take first Key - iterate through keys to look for matching keys?
            // if only associated with 1 value
                // ignore it and move on
            // if key is associated with multiple values...
                // this is a FINGERPRINT GROUP
//ASK 
                    // Do I store these groups as a vector of strings(names) WTIHIN a vector?
        // Repeat, but with NEXT UNIQUE KEY
//ASK
            //How should I handle this? Perhaps with a vector tracking 'visited' locations? Look into other methods within rust.
            //Repeat above; push into the Vec<Vec<strings>>

// Start Output According to Instructions:
    //if vec<vec<strings> is empty:
        //prints nothing and ends
    //if just 1 fingerprint group:
//ASK
        //print the group; how exactly? one entry per line? - Confirm with TAs for autograder
//ASK
    //if multiple fingerprint groups:
        //print each group, seperate them by newlines? - same as above; confirm specifications.
}
