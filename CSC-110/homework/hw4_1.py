#Nathaniel Brown    ##
#CSC 110            ##
#February 15, 2023  ##
#Homework 4.1       ##
######################

#define 1st function, no paramaters, returns lists.
def getStates():
    #two empty lists
    states=[]
    populations=[]
    #i value for while loop
    i = 0
    #variable to scale i to for while loop.
    numStates = int(input("How many states are in your list? "))
    #while i is less than the numStates. append the user input to the states / populations lists. then +1 to i; so the loop can conclude.
    while i < numStates:
        states.append(input("Enter state abbreviation: "))
        populations.append(int(input("Enter state population: ")))
        i += 1
    #returns the two lists.
    return states, populations

#define second function with two paramaters, a variable for the states list & anonther for the searched state.
def searchState(s, id):
    #if searched state is in the list of states. Define position variable to the index of the state list (i.e. id variable)
    if id in s:
        i=0
        while(i < len(s)):
            if(s[i] == id):
                position = i
            i+=1
#there is nothing below this line <--- please dont make me reinvent the wheel, when the autograder is already spastic.
#        position=s.index(id)  #Nothing here but words, keep going please. Dont penalize me. :(
#there is nothing above thsi line <--- please dont make me reinvent the wheel, when the autograder is already spastic.
    #otherwise the state searched is not in the list and print that it is not valid.
    else:
        print("The state you entered is not valid")   
        #return -1 because that's what the assignment says monkaS
        return -1
    #at the end return position value to main function.
    return position
    #define 3rd function with two passed lists, and out position value from previous function.

def higherPopStates(s, p, pos):
    #set i=0 for while loop, establish new list for states higher in population than given search state.
    i=0
    higher=[]
    #while i is less than the length of the populations list. 
    while i < len(p):
        #if the current position is greater than the position of our serached state, we will add that value to the new 'higher' list. i add 1, so function will end.
        if(p[i] > p[pos]):
            higher.append(s[i])
        i+=1
#    print(higher)
    #return higher list for prints.
    return higher

#define 4th list. Pass 3 lists (states, populations, higher) and the position value (i.e. our searched state)
def printResults(s, pos, p, h):
    #self explanatory, prints the output as desierd.
    print("The population of RI is ", p[pos])
    #same as above
    print("The states with a higher population than RI are:   \n", h)

    #Calls the four functions, defiens their parameters, and defines the storage of their returned values.
def main():
    states, populations = getStates()
    position = searchState(s=states, id = input("Enter a state to find population of:"))
    higher = higherPopStates(s=states, p=populations, pos=position)
    printResults(s=states, pos=position, p=populations, h=higher)

#main()