use std::collections::HashMap;
use std::io;
// fn ws(c: char) -> bool {
//     return c == ' ' || c == '\t'
// }
fn main() {
    // Create a mutable HashMap to store fingerprint and name pairs
    // _ , _ - type inference. As long as consisten, this way dont need to define which types.
    let mut hashmap_data: HashMap<String , Vec<String>> = HashMap::new(); //types were reference in class?


    for line in io::stdin().lines() {
        // Create a mutable String to store user input
        let current_input = line.unwrap(); 

//TODO: Figure out how to properly take the input during help hours.
        // Read user current_input from the standard current_input (keyboard)
        println!("Input a Fingerprint followed by a name:");

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
//PRINT TO CHECK
    for (fgroup, names) in &hashmap_data {
        println!("fgroup: {}, Names: {:?}", fgroup, names);
    }

       
// for key in hmap.keys()
    // for name in hmap.get_mut(key)

}





// //TODO: IMPLEMENT GOOD DATA SORT
//     //initialize a vector of vector of strings. (Store the groups after HM processing)
//     let mut vector_of_fgroups: Vec<Vec<String>> = Vec::new();
//     //initialize a vector of 
//     let mut vector_of_visited_keys: Vec<String> = Vec::new();
// //ASK - is this iteration   
//     //start iteration through the hashmap
//     for(fingerprint, name) in &hashmap_data {
//         if !vector_of_visited_keys.contains(&fingerprint){
//             //push the unique fingerprint into visited. 
// //ASK - do I not need to copy the data?
//             vector_of_visited_keys.push(fingerprint.to_string());
//         }


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




    // CLASS EXAMPLE -- taking input

    // for line in io::stdin().lines() {
    //     let l = line.unwrap(); // changes line into words
    //     let words: Vec<&str> = l.split(ws).collect();
    //     // For every word seen so far, counter contains, associated with that word, an integer value indicating the number of occurences of that word so far.
    //     for word in words {
    //         match hashmap_data.get_mut(word) {
    //             Some(c) => {
    //                 *c += 1;
    //             }
    //             None => { hashmap_data.insert((&word).to_string(), 1_u64); }
    //         }
    //     }
    // }

//     //filter sets conditions for collecting. Collects two touples.
//     let mut multiwords: Vec<_> = hashmap_data.intro_iter().filter(|(_, v)| *v > 1).collect();
//     multiwords.sort_by_key(|k| k.1);
//     multiwords.iter().foreach(|(k,v)| println!("{k}\t{v}"));
// } //delete this when re-enabling your code later.

