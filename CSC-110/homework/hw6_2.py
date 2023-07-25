import csv
#Nathaniel Brown
#CSC110 
#HOmework 6.2
#March 22, 2023

#function passed no parameters. Takes name of file, reads file, fills in columns as lists, converts lists to int, returns lists.
def getData(filename):
    

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

def dualSelectionSort(state_list, population_list, aORd):    
    ### NOTE TO SELF ### try to store original lists, sort population list. then fill in state list by comparing each new population list indicie to its original counterpart, then make state list 
    state_list_old = state_list
    population_list_old = []
    for i in range(0, len(population_list)):
        population_list[i] = int(population_list[i])
    for i in range(0, len(population_list)):
        population_list_old.append(population_list[i])
    adjusted_state_list = []

    #ASCENDING SORT
    if aORd == "A":
        population_list.sort()
        #compare new population list indicies to old population list. Get indicie for identical value.
        for element in population_list:
            #defines an index which represents the original index of the population/state pair.
            current_index = population_list_old.index(element)
            #append the adjusted state list with the current index of the old state list.
            adjusted_state_list.append(state_list_old[current_index])
    if aORd == "D":
        population_list.sort(reverse=True)
        #compare new population list indicies to old population list. Get indicie for identical value.
        for element in population_list:
            #defines an index which represents the original index of the population/state pair.
            current_index = population_list_old.index(element)
            #append the adjusted state list with the current index of the old state list.
            adjusted_state_list.append(state_list_old[current_index])  


    #return new lists for write function
    return adjusted_state_list, population_list

def writeOutput(adjusted_state_list, population_list, aORd):
    if aORd == "A":
        suffix = "asc.csv"
    if aORd == "D":
        suffix = "desc.csv"
    outFilename = "sorted-pop-" + suffix
    
    with open(outFilename, 'w', newline='') as file:
    #initialize csv writer functionality
        writer = csv.writer(file)
        #add headers
        writer.writerow(['state','pop'])
        #for i in range of the length of womenGROWTH
        for i in range(len(population_list)):
            ## writes each element of pop list as a row in the new file.
            writer.writerow((population_list[i], adjusted_state_list[i]))
    #print as per requirements with file name.
    print("Sorted data has been written to the file " , outFilename)


def main():
    #while filename isn't == cs-grads.csv, infinitely error and ask for file name until true.
    filename = input("Please enter the name of the data file: ")
    while filename != 'state-pop.csv':
        print("Invalid file name, try again ... ")
        filename = input("Please enter the name of the data file: ")
    #open the file as read, redeclare as f for future code.
    aORd = input("Enter A for ascending, D for descending: ")
    while(aORd != 'A' and aORd != 'D'):
        aORd = input("Invalid input -- A or D: ")
    state_list, population_list = getData(filename)
    adjusted_state_list, population_list = dualSelectionSort(state_list, population_list, aORd)
    writeOutput(adjusted_state_list, population_list, aORd)
