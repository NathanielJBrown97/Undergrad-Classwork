#include "Cat.h"
#include "Dog.h"
#include "Bird.h"
#include "Hamster.h"
#include "Snake.h"
#include "Animal.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
int main(int argc, char*argv[]){

    // Extract # of animals we're expecting to read from the CLA
    int number_of_animals = strtol(argv[1], nullptr, 10);
    // Extract the name of the file we'll be reading from the CLA
    std::string file_name = argv[2];
        // fstream open file for while
        // FIXED*** issue converting file_name from string --> fstream? ***
    std::ifstream open_file (file_name);
	// Create a collection (data structure) of the appropriate size to hold the # of animals we are creating
	std::vector<Animal*> collection_of_animals_vector;
    std::string unfiltered_current_line;
	// Loop through the number of animals we have.
        // Read the current line from the file
		while( std::getline(open_file, unfiltered_current_line)){
            std::istringstream chopThis(unfiltered_current_line);
            std::string current_token;
            std::vector<std::string> token_vector;
            // Tokenize the line into type, hunger, thirst
                // this will seperate each space seperated value in the .txt file into the token vector
            while(std::getline(chopThis, current_token, ' ')){
                token_vector.push_back(current_token);
            }
            if (token_vector.size() == 3) {
                std::string type = token_vector[0];
                //FIXED*** i think i need to convert the token vector elements 1/2 into floats first ****
                    //attempted conversion of string ---> float via std::stof() function.
                float hunger = std::stof(token_vector[1]);
                float thirst = std::stof(token_vector[2]);
                // Based on the type, create the appropriate animal and add it to your collection of animals
                // FIXED WITH CONDITIONALS** type needs a type-specifier... std::string? **
                if (type == "Dog"){
                    collection_of_animals_vector.push_back(new Dog(hunger,thirst));
                }
                else if(type == "Cat"){
                    collection_of_animals_vector.push_back(new Cat(hunger,thirst));
                }
                else if(type == "Hamster"){
                    collection_of_animals_vector.push_back(new Hamster(hunger,thirst));
                }
                else if(type == "Snake"){
                    collection_of_animals_vector.push_back(new Snake(hunger,thirst));
                }
                else if(type == "Bird"){
                    collection_of_animals_vector.push_back(new Bird(hunger,thirst));
                }
            }
        }
	// Loop through your collection of animals
	    for(std::size_t current_animal = 0; current_animal < collection_of_animals_vector.size(); current_animal++){
            // Speak
            collection_of_animals_vector[current_animal]->Speak();
            // Output hunger
                // *** not outputting hunger or thirst... - speak is right order ***
            std::cout << collection_of_animals_vector[current_animal]->GetHunger() <<  "\n";

            // Output thirst
            std::cout << collection_of_animals_vector[current_animal]->GetThirst() << "\n";
        }

}

