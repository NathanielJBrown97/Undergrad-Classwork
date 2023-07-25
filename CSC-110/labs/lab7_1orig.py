# Binary Search

# Given: A list of names, a list of phone numbers and a phone number to search for

# Function to open file using exception handling
def openFile():
    goodFile = False
    while goodFile == False:
        fname = input("Enter name of data file: ")
        # Begin exception handling
        try:
            # Try to open the file using the name given
            dataFile = open(fname, 'r')
            # If the name is valid, set Boolean to true to exit loop
            goodFile = True
        except IOError:
            # If the name is not valid - IOError exception is raised
            print("Invalid filename, please try again ... ")
    return dataFile

# Function to read the names and phones into lists
def getLists():
    fname = input("Enter name of data file: ")
    infile = open(fname,'r')
    line = infile.readline()

    names = []
    numbers = []

    while line != "":
        line = line.strip()
        name, number = line.split(',')
        names = names + [name]
        numbers = numbers + [number]
        line = infile.readline()

    infile.close()
    return names, numbers

# Function to find the name and return the associated phone number
def binarySearch(names, phones, name):
    #counter for comps
    comps = 0
    #start variable: starts at zero IE: FIRST ENTRY IN LIST
    start = 0
    #end variable equal to the length of states - 1. IE: LAST ENTRY IN LIST
    end = len(names)-1
    # LOOP UNTIL SEARCH RANGE IS EMPTY
    while(start <= end):
        #increment comp
        comps +=1
        #CALCULATE MIDPOINT OF SEARCH RANGE
        midpoint = (start + end) // 2
        #check if midpoint contains the target name
        if names[midpoint] == name:
            # print("Binary Search: comps = ", comps)
            return phones[midpoint]
        #if midpoint is less then name; update start index by 1 to the right.
        elif names[midpoint] < name:
            start = midpoint +1
        #if midpoint is greater than target name, update start index by 1 to the left
        else:
            end = midpoint -1
    
    #if the name is not found, return -1 || print overlards requirements first.
    # print("Binary Search: comps = ", comps)
    return ""

    # if found == 0:
    #     return ""
    # else:
    #     return phones[m]

    
# Main Function

def main():
    # Get the lists
    names, phones = getLists()
    # Get the name to search for
    theName = input("Enter the name to search for: ")

    # Find the phone number for the given name
    phoneNum = binarySearch(names, phones, theName)
    if phoneNum == "":
        print("Name not found")
    else:
        print("The phone number for ", theName, " is ", phoneNum)
