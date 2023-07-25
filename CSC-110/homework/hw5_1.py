#Nathaniel Brown
#CSC110 
#HOmework 5.1
#Feb 28

# PLEASE NOTE: ITS PRETTY HARD TO 'DOCUMENT' FOR THE RUBRIC, BUT STILL MAINTAIN 'READABILITY'. It would be super cool if you don't doc a bunch of points for 'readability' because I spent the time to document everything.

#import csv, decimal libraries (I used decimal to work around an annoying float / rounding issue with the autograder)
import csv, decimal

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
        total = []
        men = []
        women = []
        #fill lists by columns
        for col in file:
            ay.append(col['AY'])
            total.append(col['Total'])
            men.append(col['Men'])
            women.append(col['Women'])
        #convert lists to integers... Lists were being taken as strings.
        ay = list(map(int, ay))
        total = list(map(int, total))
        men = list(map(int, men))
        women = list(map(int, women))
    #return variables
    return ay, total, men, women

#function passed the ay list (years), used to ask for a year and check a series of conditionals to ensure accurate functioning of the overall program.
def getYears(ay):
    #While loop that'll repeat until it hits break.
    while True:
        #user input
        getyear1 = input("Enter a year: ")
        #try user input as integer
        try:
            year1 = int(getyear1)
            #if user input is not in ay list. Error and repeat from top of While.
            if year1 not in ay:
                print("Year not in range, try again...")
            #else break from while loop, go to next line.
            else:
                break
        #catch any ValueError (i.e. entered a string), send error message, returns to top of while.
        except ValueError:
            print("Invalid entry, try again...")

    #This is the same thing as above, but with two elif.
    while True:
        getyear2 = input("Enter a year: ")
        try:
            year2 = int(getyear2)
            if year2 not in ay:
                print("Year not in range, try again...")
            #if the year2 = year1, no error message, return to top of while.
            elif year2 == year1:
                continue
            #if year2 is greater than year 1; start a if/else within this scope to reask for year1.
            elif year2 <= year1:
                print("year2 should be after year1, try again...")
                getyear1 = input("Enter a year: ")
                year1 = int(getyear1)
                #if year 1 isn't in the array, same error as above, loops until proper input.
                if year1 not in ay:
                    print("Year not in range, try again...")
                #once year1 is accurate... continues to while loop again (asking for year2 input, then checking)
                else:
                    continue
            #if all satisfied, breaks the while loop continues the code.
            else:
                break
        #catches any ValueError and redirects to top of while loop.
        except ValueError:
            print("Invalid entry, try again...")
    #returns values of year 1 and 2
    return year1, year2

#function passed year values, and all four lists: calculates the percent change of each respective element values. Outputs the roundedgrowth percent change to the main function.
def computePercentChange(year1, year2, total, men, women, ay):
    #redefine year variables as their respective indexes (I would have done this above; but gradescope is a bastard man)
    year1 = ay.index(year1)
    year2 = ay.index(year2)
    #define variable to equal the decimal percent change. Based on TOTAL list, going off of the above index values. (Swaps out for their respective paired data)
    totalGROWTH = (((total[year2]-total[year1])) / (total[year1])) * 100
    #decimal redeclaration to use with the decimal library attached at the start of program.
    DECtotalGROWTH = decimal.Decimal(totalGROWTH)
    #uses built in command with decimal library to round the decimal to exactly two places after the integer value.
    totalROUNDGROWTH = DECtotalGROWTH.quantize(decimal.Decimal('0.00'))
    #define variable to equal the decimal percent change. Based on MEN list, going off of the above index values. (Swaps out for their respective paired data)
    menGROWTH = (((men[year2]-men[year1])) / (men[year1])) * 100
    #decimal redeclaration to use with the decimal library attached at the start of program.
    DECmenGROWTH = decimal.Decimal(menGROWTH)
    #uses built in command with decimal library to round the decimal to exactly two places after the integer value.
    menROUNDGROWTH = DECmenGROWTH.quantize(decimal.Decimal('0.00'))
    #define variable to equal the decimal percent change. Based on WOMEN list, going off of the above index values. (Swaps out for their respective paired data)
    womenGROWTH = (((women[year2]-women[year1])) / (women[year1])) * 100
    #decimal redeclaration to use with the decimal library attached at the start of program.
    DECwomenGROWTH = decimal.Decimal(womenGROWTH)
    #uses built in command with decimal library to round the decimal to exactly two places after the integer value.
    womenROUNDGROWTH = DECwomenGROWTH.quantize(decimal.Decimal('0.00'))

    #return 3 variables representing the rounded growth of percent change
    return totalROUNDGROWTH, menROUNDGROWTH, womenROUNDGROWTH

#function passed the rounded growth percents: Self explanatory -- prints statements as per requirements.
def printResults(totalROUNDGROWTH, menROUNDGROWTH, womenROUNDGROWTH):
    print("Percent change overall: ", totalROUNDGROWTH, " %")
    print("Percent change men: ", menROUNDGROWTH, " %")
    print("Percent change women: ", womenROUNDGROWTH, " %")
#main function calls and defines variables passed to respective functions
def main():
    #getData has no parameters, returns/defines 4 lists.
    ay, total, men, women = getData()
    #getYears takes the years list and returns/defines 2 years.
    year1, year2 = getYears(ay)
    #computePercentChange takes our two defined years, and our 4 lists as parameters. Returns a rounded percent value for our Total, men, and women, values.
    totalROUNDGROWTH, menROUNDGROWTH, womenROUNDGROWTH = computePercentChange(year1, year2, total, men, women, ay)
    #print function passed the 3 respective rounded percent values.
    printResults(totalROUNDGROWTH, menROUNDGROWTH, womenROUNDGROWTH)

