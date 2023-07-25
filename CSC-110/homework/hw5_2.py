#Nathaniel Brown
#CSC110 
#HOmework 5.2
#Feb 28
#import csv, 
import csv

#function passed no parameters. Takes name of file, reads file, fills in columns as lists, converts lists to int, returns lists.
def getData():
    #while filename isn't == cs-grads.csv, infinitely error and ask for file name until true.
    filename = input("Please enter the name of the data file: ")
    while filename != 'cs-grads.csv':
        print("Invalid file name, try again ... ")
        filename = input("Please enter the name of the data file: ")
    #open the file as read, redeclare as f for future code.
    with open(filename, "r") as f:
        #csv function to read file.
        file = csv.DictReader(f)
        #four empty lists
        ay = []
        women = []
        #fill lists by columns
        for col in file:
            ay.append(col['AY'])
            women.append(col['Women'])
        #convert lists to integers... Lists were being taken as strings.
        ay = list(map(int, ay))
        women = list(map(int, women))
    #return variables
    return ay, women

#def getYears function passed the years list. Runs series of checks to ensure input is valid.
def getYears(ay):
    #While loop that'll repeat until it hits break.
    while True:
        #user input
        getyear2 = input("Enter a year: ")
        #try user input as integer
        try:
            year2 = int(getyear2)
            #if user input is not in ay list. Error and repeat from top of While.
            if year2 not in ay:
                print("Year not in range, try again...")
            elif year2 == 1971:
                print("Year not in range, try again... ")
            #else break from while loop, go to next line.
            else:
                break
        #catch any ValueError (i.e. entered a string), send error message, returns to top of while.
        except ValueError:
            print("Invalid entry, try again...")

    #Year 1 for later calculations. Simply 1 less than year2, as it's previous year.
    year1 = year2 - 1
    #returns values of year 1 and 2
    return year1, year2

#Def percentchange function; passed year values, women/years lists.
def computePercentChange(year1, year2, women, ay):
    #if year1 is not in the years list or year 2 isn't in the list. Raises a valueerror and outputs appropriate message.
    if year1 not in ay or year2 not in ay:
        raise ValueError("year1 or year2 not found in ay")
    #define new list for pass to future function.
    womenGROWTH = []
    #defines two index values based off of the year's positions within the ay list. (year list)
    year2INDEX = ay.index(year2)
    year1INDEX = ay.index(year1)

    #whlie i is less than the length of year list - the year 2 index (this allows the length to reflect only the indicies from year2 and on.)
    i = 0
    while (i < len(ay) - year2INDEX):
        #append a calculation based off the indicies + the current iteration to finish cycling through the list.
        womenGROWTH.append((women[year2INDEX + i] - women[year1INDEX + i]) / women[year1INDEX + i])
        i += 1
    #returns new list for output
    return womenGROWTH

#defines functoin to write two lists into a new csv file. Passed year list, new list from above, and year2 value.
def writetoCSV(ay, womenGROWTH, year2):
    #define file name with related  year tag as per requirements.
    filename = 'womenGradChangeFrom' + str(year2) + '.csv'
    #define variable for the year difference between the original years list and the new womenGROWTH list. (since womenGROWTH is shorter than ay)
    yeardif = ay.index(year2)
    #opens the filename defined above (Creating a new file)
    with open(filename, 'w', newline='') as file:
        #initialize csv writer functionality
        writer = csv.writer(file)
        #for i in range of the length of womenGROWTH
        for i in range(len(womenGROWTH)):
            ##write the values for ay + the year difference (keeps indicies in line with womenGROWTH) and add women value. Until end of lists.
            writer.writerow((ay[i+yeardif], womenGROWTH[i]))
    #print as per requirements with file name.
    print("Your data has been written to the file " , filename)

#main function calling and defining the above functions.
def main():
    #returns ay, and women.
    ay, women = getData()
    #returns year values.
    year1, year2 = getYears(ay)
    #returns womenGROWTH list
    womenGROWTH = computePercentChange(year1, year2, women, ay)
    #utilizes year and womenGROWTH lists as well as the selected year value; to write a new CSV file.
    writetoCSV(ay, womenGROWTH, year2)
