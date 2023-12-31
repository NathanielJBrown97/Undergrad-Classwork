///////////////////// Libraries ////////////////////
#include <iostream>
#include "kochsnowflake.cpp"
#include "SierpinskiTriangle.cpp"
#include "hilbertCurve.cpp"
////////////////////////////////////////////////////


//// Main Menu Display Function; passed a boolean to check if the intro message has yet to be displayed.
void displayMainMenu(bool firstDisplay){
    if (firstDisplay == false) {
        std::cout << "\n\nWelcome to our project 212 user interface. Please read through following menu. \n" <<
                  "Upon selection of your algorithm of choice you will be requested for input of the \n" <<
                  "appropriate parameters required for the construction of the graphic. \n\n";
    }
    std::cout << "1.) Hilbert's Curve \n" <<
              "2.) Sierpinski's Triangle \n" <<
              "3.) Koch's Snowflake \n" <<
              "4.) End Program \n\n";
}


//// Sub Menu Display Function; passed the main menu choice, to direct output.
void displaySubMenu(int mainMenuChoice){
    //// HILBERT'S CURVE - The messages and parameters are templates. Adjust to what is needed in future additions.
    if (mainMenuChoice == 1){
        std::cout << "Welcome to the Hilbert's Curve Algorithm \n" <<
                  "Please follow the prompts and enter a file name for your image creation. *Must* end with .png. \n\n";
    }
        //// SIERPINSKI'S TRIANGLE
    else if (mainMenuChoice == 2){
        std::cout << "Welcome to the Sierpinski's Triangle Algorithm \n" <<
                  "Please follow the prompts and enter a file name for your image creation. *Must* end with .png. \n"
                  "Then select a color from the following menu (Input the corresponding number): \n"
                  "1.) Red \n"
                  "2.) Magenta \n"
                  "3.) White \n"
                  "4.) Yellow \n\n";

    }
        //// KOCH'S SNOWFLAKE
    else if (mainMenuChoice == 3){
        std::cout << "Welcome to the Koch's Snowflake Algorithm \n" <<
                  "Please follow the prompts and enter a file name for your image creation. *Must* end with .png. \n"
                  "Then select a color from the following menu (Input the corresponding number): \n"
                  "1.) Red \n"
                  "2.) Magenta \n"
                  "3.) White \n"
                  "4.) Yellow \n\n";
    }
}

sf::Color getColor(int userInput){
    sf::Color userColor;

    if (userInput == 1){
        userColor = sf::Color::Red;
    }
    else if (userInput == 2){
        userColor = sf::Color::Magenta;
    }
    else if (userInput == 3){
        userColor = sf::Color::White;
    }
    else if (userInput == 4){
        userColor = sf::Color::Yellow;
    }
    else{
        std::cout << "Detecting an inability to count from 1 - 4... auto selecting the worst color... \n";
        userColor = sf::Color:: Blue;
    }
    return userColor;
}

//// Main function; Initiates program and starts the user interface, includes boolean catch to avoid reprinting intro message repeatedly.
int main(){
    bool firstDisplay; // boolean to stop Main menu from outputting introduction every time it's called.
    displayMainMenu(firstDisplay);
    firstDisplay = true; // flip boolean to prevent future introduction output.

    //// MainMenuChoice determines selection of outer loop.
    int mainMenuChoice = 666; //int variable to store outer loop choice. Set to a number outside of range.

    //// Loop through until the user selects 5 to end the program.
    while(mainMenuChoice != 4) {
        int subMenuChoice = 666; //int variable to store the inner loops choices. Resets to number outside of range after each iteration of outer loop.

        std::cout << "Please input the number of your choice: "; std::cin >> mainMenuChoice; std::cout << "\n"; //Request Menu Choice

        //// HILBERT'S CURVE
        if (mainMenuChoice == 1){
            std::string fileNameDirectory = "../";
            std::string fileName; // initialize necessary params for future function/class call from Hilbert files.
            displaySubMenu(mainMenuChoice);
            std::cout << "Please enter the file name you wish to save the Hilbert's Curve to: "; std::cin >> fileName;
            fileNameDirectory += fileName;
            initiateCurve(fileNameDirectory);
        }
            //// SIERPINSKI'S TRIANGLE
        else if (mainMenuChoice == 2){
            std::string fileName; // initialize necessary params for future function/class call from Sierpinski files.
            std::string fileNameDirectory = "../"; // moves file up one directory
            int windowHeight = 1000; // sets height of window for Koch
            int windowWidth = 1000; // sets width of window for koch
            sf::Color userColorMain; // Creates an object of type template-color class in the SF library.
            sf::Color userColorContrast;
            int userSelectionMainColor; // Int representing color selection -> used to set userColor object.
            int userSelectionContrastColor;
            int endStage; // Int that will store a number containing the amount of iterations the user decides they want the snowflake program to process. (i.e. stage of snowflake)
            displaySubMenu(mainMenuChoice);

            std::cout << "Please enter the file name you wish to save the Sierpinski's Triangle to:  "; std::cin >> fileName;
            std::cout << "Please enter your main color selection. (Type the corresponding number): "; std::cin >> userSelectionMainColor;
            userColorMain = getColor(userSelectionMainColor);
            std::cout << "Please enter your contrast color selection. (Type the corresponding number): "; std::cin >> userSelectionContrastColor;
            userColorContrast = getColor(userSelectionContrastColor);
            std::cout << "Please enter the stage of Sierpinski's Triangle you would like. (Enter a number from 0 - 5; anything higher will affect runtime.): "; std::cin >> endStage;

            fileNameDirectory += fileName;
            initiateSierpinski(windowHeight, windowWidth, fileNameDirectory, userColorMain, userColorContrast, endStage);
        }
            //// KOCH'S SNOWFLAKE
        else if (mainMenuChoice == 3){
            std::string fileName; // initialize necessary params for future function/class call from Koch files.
            std::string fileNameDirectory = "../"; // moves file up one directory
            int windowHeight = 1000; // sets height of window for Koch
            int windowWidth = 1000; // sets width of window for koch
            sf::Color userColor; // Creates a object of type template-color class in the SF library.
            int userSelection; // Int representing color selection -> used to set userColor object.
            int endStage; // Int that will store a number containing the amount of iterations the user decides they want the snowflake program to process. (i.e. stage of snowflake)
            displaySubMenu(mainMenuChoice);
            std::cout << "Please enter the file name you wish to save the Koch's Snowflake to:  "; std::cin >> fileName;
            std::cout << "Please enter your color selection. (Type the corresponding number): "; std::cin >> userSelection;
            std::cout << "Please enter the stage of Koch's Snowflake you would like. (Enter a number from 0 - 5; anything higher will affect runtime.): "; std::cin >> endStage;

            userColor = getColor(userSelection);

            fileNameDirectory += fileName;

            initiateKOCH(windowHeight, windowWidth, fileNameDirectory, userColor, endStage); /// Initiates the Koch's Snowflake passed a height, width dimensions for the graphic window. As well as a file name for the png output, and a user selected color of the graphic, and the end stage (i.e. iteration count).

        }
            //// TERMINATE PROGRAM - END OUTER WHILE
        else if (mainMenuChoice == 4){
            std::cout << "Program is ending... Thank you!\n\n";
            break;
        }
        else{
            std::cout << "Enter an appropriate number between 1 and 5. \n\n";
        }

        displayMainMenu(firstDisplay); //if while loop is not broke within elif #5... display menu for next selection.
    }
}