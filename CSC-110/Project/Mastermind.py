#Nathaniel Brown
#Final Project: Mastermind Choice
#March 29, 2023
#CSC 110
##################################
## Design Requirement Section   ##
##################################
##         Description          ##
##################################
# I will be designing the Mastermind game; as you know it requires
# the computer to create a combination of four colors that will act as
# the code for the human player to attempt to guess. The human player 
# has 10 attempts to break the code; and will receive a clue as to
# how well the player had guessed the code each attempt.
###################################
##    General Solution           ##
###################################
# Create a function that contains a list of colors; upon launching program.
# have it randomly select four colors and store them into a new list called 
# passcode. return this list and pass it to another function that runs the game
# this function will take the passcode and prompt the user ot enter a guess. This will call
# the required check the guess function, and return a clue as per the rquirements.
# it will then direct the user as to the correct nature of their guess or give them a 
# clue as relevant. This function will keep a counter; to limit the player
# to 10 attempts. It will return the results and within main, which will then call
# a final print function which will display the results to the user.
####################################
##   Pseudo For Main             ###
####################################
# def main():
# call generate passcode function - which will return a list of four colors
# for the player to attempt to guess.
# call game function - which will prompt the user to input a guess, keep tally of 
# the amount of attempts the user is at. 
# Within the game function we will call our check guess function: which will return
# an update as to the correctness of the players guess and a clue needed to continue.
# when the game function ends it will return the results of the game and be passed to our output
# function.
# finally we will call our print results function and output the results of the game.
#####################################
##     Function Design             ##
# def main(): - will call  each of our functions and store variables for the return values.
# no real processes happen within this main function except for starting other functions.
# passcode = generateCode(): is passed nothing, but returns a list of a randomized list of colors.
# this will be used as the code the player will guess against.
# results = runGame(passCode): will be passed the passcode generated from generate code function.
# this function will keep a counter of the attempted guesses and prompt the user for input. 
# after each input the function will call the functoin below (checkGuess()). 
# upon conclusion of runGame the results will be returned to main.
# clue = checkGuess(guess): Thsi function will be passed the users guess created in runGame. 
# it will then run a series of conditionals to determine if the guess is accurate. And how many pegs
# were marked as correct. it will then generate a clue that it will return and be displayed to the user.
# then runGame will continue until the conclusion of the game.
# printResults(results): this function is simply passed the results of runGame and will
# display whether the user won or not, as well as what hte passcode was.
#######################################
#######################################
#######################################
#######################################
# PROGRAM START #######################
#######################################
#import random
import random
#function passed our global list of colors. Generates our passcode.
def generateCode(color_choice):
    # empty list to be filled with random elements of our global list.
    passCode = []
    #while the length of our passCode is less than 4
    while(len(passCode) < 4):
        #append an element of our global list into our passcode. Random element from 0 - length of global list.
        passCode.append(color_choice[random.randint(0, len(color_choice)-1)])
    #returns the passCode for the game
    return passCode

#function passed color choice list, turn_limit. Will collect and return a list of the users guesses.
def get_guess(color_choice, turn_limit):
    guessedCode = []
    #output print for gradescopes requirements
    print("-----------------------------")
    print("Make a guess of four colors:")
    print("0 - red")
    print("1 - orange")
    print("2 - yellow")
    print("3 - green")
    print("4 - blue")
    print("5 - purple")
    print("-----------------------------")
    #whlie length of our guessed code is less than 4
    while(len(guessedCode) < 4):
        # variable to collect the index of their guess
        current_guess = input("Guess color:")
        if current_guess.isdigit() and int(current_guess) in range(len(color_choice)):
            #append the index of their color_choice guess.
            guessedCode.append(color_choice[int(current_guess)])
        #if its out of range - number error
        elif current_guess not in range(len(color_choice)) and current_guess.isdigit():
            print("Invalid guess, try again:")
        #if its not a number - guess error.
        else:
            print("Invalid number, try again:")
    print("-----------------------------")
    #return the guessed code
    return guessedCode


def checkGuess(guessedCode, passCode):
    # track how many correct pos to push into our clueList
    correct_pos = 0
    # track how many correct colors to push into our cluelist
    correct_color = 0
    #remaining guess/pass lists for later for loop to determine correcpos/color counters.
    remaining_guess = []
    remaining_pass = []
    
    # Count the number of correctly placed colors
    # loop to the length of the guessedCode
    for i in range(len(guessedCode)):
        #if the current iteration of guessedCode list is equal to the passCode position
        if guessedCode[i] == passCode[i]:
            #increment correct pos counter
            correct_pos += 1
        #otherwise; append the guessedCode/passCode iteration to remaining guess/pass
        else:
            remaining_guess.append(guessedCode[i])
            remaining_pass.append(passCode[i])
    
    # Count the number of correctly guessed colors in the wrong position
    for color in remaining_guess:
        #if the color is in remaining_passes list
        if color in remaining_pass:
            #increment correct color by 1
            correct_color += 1
            #remove the current color from remaining_passes list
            remaining_pass.remove(color)
    
    # Create the clue list for return; by adding 1 and 2 value multiplied by the amount of correct pos/colors.
    clueList =  [1] * correct_color + [2] * correct_pos

    # return the clueList
    return clueList


#function used to call our smaller modular functions. SeedIn as parameter for gradescope.
def main(seedIn):
    # random seed as per instructions
    random.seed(seedIn)
    #bool for play again feature
    play_again = True
    #while play_again true; start game
    while play_again:
        #Turn counter; used to limit the player to 10 options
        turn_limit = 10
        #Color chocie list; passed to other function. Modify this if you want to increase options.
        color_choice = ['red', 'orange', 'yellow', 'green', 'blue', 'purple']
        # definition of passCode is the function generateCode(passed our color choice list)
        passCode = generateCode(color_choice)
        print("The secret code has been chosen. You have 10 tries to guess the code.")
        # while the turn limit is greater than 0, get chocie, check choice, return clue.
        while(turn_limit > 0):
            #at start of turn decrement limit
            turn_limit -= 1
            #call get_guess passed color_choice and turn limit, to define our playesr Guesses
            guessedCode = get_guess(color_choice, turn_limit)
            #output as per gradescope requirements
            print("Your guess is: " , guessedCode)
            #call checkGuess passed our players guesses and the passCode. Defines our cluelist.
            clueList = checkGuess(guessedCode, passCode)
            #if the clue list is perfect; output correct and break
            if (clueList == [2,2,2,2]):
                print("Correct! You finished in ", 10 % turn_limit, "guesses")
                break
            #if turn limit reaches 0, output gradescope requirements
            elif (turn_limit == 0):
                print("Your clue is: " , clueList)
                print("No more guesses, the hidden colors were:")
                print(passCode)
            # otherwise; display clue, turn limit and continue iterations of while loop.
            else:
                print("Your clue is: " , clueList)
                print("You have ", turn_limit, " guesses left")
        #after while loop cloess; ask for input on play again
        play_again = input("Would you like to play again? (Y/N)")
        #if yes; rest time limit. And the first layer while loop will restart the program.
        if play_again == 'y' or play_again == 'Y':
            turn_limit = 10
        #otherwise; they don't. Dispaly thank you and flag play_again to false... 
        else:
            print("Thank you for playing. Good-bye!")
            # this flag switch ends the program by breaking first while.
            play_again = False
            
main(1)
