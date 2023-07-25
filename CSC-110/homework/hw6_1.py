#Nathaniel Brown
#March 21 2023
#CSC 110
#Homework 6 - Analysis of Algorithms Part I
################################################################################
################################################################################
################################################################################
################    DISCUSSION        ################
################     THING       ################
########## Note Assignment Instructions say nothing about best case ########
## Worst Case Input:
##      - Binary - The worst case input would be when the searched term is either 
## last in the list, or not in the list at all.
##      - Linear - The worst case scenario is when the searched term is last in hte list, or not at all.
## Comparison of the performance of hte two:
##      - Very often the binary search will find it's searched term much faster than linear.
## this is because the binary search seperates the list into two groups that it can iterate through
## much more effeciently. The only situation that a linear search will be faster is in the rare case that
## the first value is the searched value, linear would instantly complete this process whereas binary would need to 
## process through its group entirely. Simliarly; if the searched value is in the midpoint, binary would immediately find the 
## value in this particular program.
################################################################################
################################################################################
################################################################################
#importing csv module bc no one does that shit manually.
import csv

#function passed no parameters. Takes name of file, reads file, fills in columns as lists, converts lists to int, returns lists.
def getData(filename):

    #open the file as read, redeclare as f for future code.
    with open(filename, "r") as f:
        #csv function to read file.
        file = csv.reader(f)
        #two empty lists
        state_list = []
        population_list = []
        #fill lists by columns
        for row in file:
            state_list.append(row[0])
            population_list.append(row[1])
    #return variables
    return state_list, population_list

#function passed state and population list to perform a linear search
def getStateLinear(state_list, population_list, state):
    #counter for comps
    comps = 0
    #loop for range of the state list length
    for i in range(len(state_list)):
        #increment counter
        comps += 1
        #if iteration is state, update population, break from loop
        if state_list[i] == state:
            population = population_list[i]
            break
        #if iteration is not in the state list at all, must not exist return -1
        if state not in state_list:
            population = -1
    #print statement as per overlords requirements
    print("Linear Search: comps = " , comps)
    #return population value
    return population

#function passed both lists, and chosen state, to perform a binary search.
def getStateBinary(state_list, population_list, state):
    #counter for comps
    comps = 0
    #start variable: starts at zero IE: FIRST ENTRY IN LIST
    start = 0
    #end variable equal to the length of states - 1. IE: LAST ENTRY IN LIST
    end = len(state_list)-1
    # LOOP UNTIL SEARCH RANGE IS EMPTY
    while(start <= end):
        #increment comp
        comps +=1
        #CALCULATE MIDPOINT OF SEARCH RANGE
        midpoint = (start + end) // 2
        #check if midpoint contains the target state
        if state_list[midpoint] == state:
            print("Binary Search: comps = ", comps)
            return population_list[midpoint]
        #if midpoint is less then state; update start index by 1 to the right.
        elif state_list[midpoint] < state:
            start = midpoint +1
        #if midpoint is greater than target state, update start index by 1 to the left
        else:
            end = midpoint -1
    
    #if the state is not found, return -1 || print overlards requirements first.
    print("Binary Search: comps = ", comps)
    return -1


def main():
    #while filename isn't == state-pop.csv, infinitely error and ask for file name until true.
    filename = input("Please enter the name of the data file: ")
    while filename != 'state-pop.csv':
        print("Invalid file name, try again ... ")
        filename = input("Please enter the name of the data file: ")
    # collect state to search for
    state = input("Enter state abbreviation: ")
    #call get data passed filename and returning both the state and population lists
    state_list, population_list = getData(filename)
    #call linear search function, passed both lists and the searched state, returns and defines population as per requirements.
    population = getStateLinear(state_list, population_list, state)
    #call binary search function, passed both lists and the searched state, returns and defines population as per requirements.
    population = getStateBinary(state_list, population_list, state)

    #start output as needed: If not fonud and -1 was returned, display state not found
    if population == -1:
        print("State not found")
    #otherwise: Print the state overlords demanded output with the population vairable defiend in the search functions.
    else:
        print("The population of " , state, " is " , population)


