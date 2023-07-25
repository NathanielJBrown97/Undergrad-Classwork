# Nathaniel Brown
# CSC 201
# Assignment 7
# Fall 22'   October 27, 2022
#
#
#
# [Functions] 
# Description:
# Design a program that will ask users to respond to the questions used in our
# original data survey, using functions
#
# Solution:
# Using the code from last week; I will organize several functions that will 
# allow the program to prompt the questions simply without writing as much code.
#   --------              ------------
#   -------- Script Start ------------
#   --------              ------------
########################################################################
#Variable List For Calculations in Functions #
GC = 72922          #Global Cases of Monkeypox (MP)
GCD = 22            #Global deaths by MP

MPUS = 27558        #US Cases of MP
MPUSD = 3           #US Deaths by MP

MPBZ = 8652         # Brazil Cases of MP
MPBZD = 7            # Brazil deaths by mp

MPSP = 7239         # Spain Cases
MPSPD = 2           # Spain Deaths

MPF = 4064          # France C
MPFD = 0            # France D

MPG = 3656          # Germany C
MPGD = 0            # Germany D

MPUK = 3673         # UK C
MPUKD = 0           # UK D

######################################################################
###    Date Time Import Requirement   ### 
from datetime import datetime
now = datetime.now()
### Timestamp for Later               ###
ts = datetime.timestamp(now)
###  Current date time                ###      
current_year = now.year
current_month = now.month
current_day = now.day   

# ---------- Define Functions Main, Title, Get/Check, Questions ------------
def main():          #main function, runs and calls the below defined functions to satisfy program requirements
    title_msg()      #Title function, displays title and Source.
    check_choice(get_choice())  #Runs function to check choice validitiy for range, and digit status. Passed output of get_choice as a parameter to check_choice.  <===
def title_msg():     #Prints title and where data was collected.
    print("Assignment 7 - Programming With Functions. \nThis data was collected from the CDC heatmap of Monkeypox.")
def get_choice():    # Function to get choice integer value for use in check_choice function
    choice = int(input("""Which quick Monkeypox fact would you like the answer to?
    If you do not wish to continue please type '5'. Thank you.
    1.) What is the total cases amongst the most infected countries; US, UK, Brazil, Spain, Germany, and France?
    2.) What is the average amount of cases between the aforementioned most infected countries?
    3.) What is the average deaths of the aforementioned most infected cases?
    4.) How many cases are in the rest of the world?
    5.) Type '5' if you do not wish to continue... \n"""))
    return choice  #returns value of choice for later use.

def check_choice(check_val):   #Function that use checks_val parameter to Passing output of get_choice, using check_val, to check_choice for range validitty check.
    if check_val in list(range(1,6)):    # check if within range established in variables (i.e. 1-5)
            in_range = True              # if true, switch in range to true.
            
    else:
        in_range = False             # else, inrange remains false and print error.
        print("Invalid Input, not within valid range. 1-5 \n")
    if in_range:                     # continuing... if in range... redirect to run appropriate function for question.
        if check_val == 1:   # If check_val (i.e. choice) = x, run question x calc function
            q1()             # run function for question
            check_choice(get_choice()) # IN ORDER TO LOOP - TO ALLOW REPEAT QUESTIONS, Call check_choice funciton with parameter of get_choice.
        elif check_val == 2:
            q2()
            check_choice(get_choice())
        elif check_val == 3:
            q3()
            check_choice(get_choice())
        elif check_val == 4:
            q4()
            check_choice(get_choice())
        else:                        # Otherwise - (only other option being 5), end the program and notify.
            print("Your request to halt continuation of program is granted. \n")
    else:
        print("Input not a valid digit \n")   # output for error if initial digit check fails.
        check_choice(get_choice())
def q1(): # runs calculation for question and prints appropriate response.
    totallist = MPUS + MPSP + MPF + MPBZ + MPG + MPUK #calculates total of examined countries
    print("The total cases of Monkeypox in the following countries: US, UK, Brazil, Spain, Germany, and France is ..." , totallist , "\n")
def q2(): # runs calculation for question and prints appropriate response.
    avglistcases = MPUS + MPSP + MPF + MPBZ + MPG + MPUK // 7  #Calculates Average Cases between examined countries
    print("The average cases of Monkeypox within the countries: US, UK, Germany, Brazil, Spain, and France is ..." , avglistcases , "\n")
def q3(): # runs calculation for question and prints appropriate response.
    avglistdeaths = MPUSD + MPSPD + MPFD + MPBZD + MPGD + MPUKD // 7 #calculates average of deaths between examined countries
    print("The average deaths due to Monkeypox within the countries: US, UK, Germany, Brazil, Spain, and France is..." , avglistdeaths , "\n")
def q4(): # runs calculation for question and prints appropriate response.
    remainingMP = GC - totallist #Calculates remaining cases distributed throughout the rest of the world. (i.e. not including examined countries)
    print("If you factor out the cases within the countries: US, UK, Brazil, Germany, Spain, and France there are ..." , remainingMP , "cases distributed between the rest of the world. \n")

main()
