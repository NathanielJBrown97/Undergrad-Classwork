# Nathaniel Brown
# CSC 201
# October 19, 2022
# Fall 2022
#
# ASSIGNMENT 7
#
#
#
####################################################################
############ TITLE: PROGRAMMING WITH DATA USING LOOPS ##############
#######                 Description                         ########
####################################################################
## The program will prompt the user to input which question they would
## like an answer to. Then the program will check to ensure their input
## is both a valid digit and within our set range. It will output errors
## if neccessary and will loop/end as instructed on the assignment page.
#####################################################################
####################    SOLUTION                        #############
## First variables will be established for the data collected online, as
## well as setting the range limits, choice (input) and inrange boolean.
## Then variables will be used to run calculations, before starting the while loop
## within the while loop we will prompt the user for their input on choice of question.
## then we will use isdigit to confirm the response is valid, if not inform user of error
## lastly we will use the inrange boolean value and our set range to determine if the digit is applicable
## if it is appliciable the program will follow its if/elif statements to output the appropriate 
## requested response or end the program if 5 is selected.
########################################################################
#Variable List
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

range1 = range(1, 6) # Establishes range of possible int answers to later prompt.
choice = '' #defines variable to be defined by user input
in_range = False     # starts inrange variable to false for later use.

######################################################################
#Calculations <--- <---- <---- listed here so they do not need to be ran within the loop. <---- <--- <---
MPNUS = GC - MPUS     #MP Cases in the rest of the world (excluding US)
MPNUSD = GCD - MPUSD  #Number of deaths in the rest of the world (excluding US)
avglistcases = MPUS + MPSP + MPF + MPBZ + MPG + MPUK // 7  #Calculates Average Cases between examined countries
avglistdeaths = MPUSD + MPSPD + MPFD + MPBZD + MPGD + MPUKD // 7 #calculates average of deaths between examined countries
totallist = MPUS + MPSP + MPF + MPBZ + MPG + MPUK #calculates total of examined countries
remainingMP = GC - totallist #Calculates remaining cases distributed throughout the rest of the world. (i.e. not including examined countries)
######################################################################
# Start of Program
#variables for while

while choice!= '5': #establishes rules, for if input is not 'n' i.e. user DOES want to proceed.
    choice = input("""Which quick Monkeypox fact would you like the answer to?
    If you do not wish to continue please type '5'. Thank you.
    1.) What is the total cases amongst the most infected countries; US, UK, Brazil, Spain, Germany, and France?
    2.) What is the average amount of cases between the aforementioned most infected countries?
    3.) What is the average deaths of the aforementioned most infected cases?
    4.) How many cases are in the rest of the world?
    5.) Type '5' if you do not wish to continue...""")

### CHECK IF DIGIT  ####
    if choice.isdigit():        # if input is a digit change choice to an int variable
        choice = int(choice)
 #### CHECK IF IN RANGE #### 
        if choice in list(range(1,6)):       # check if within range established in variables (i.e. 1-5)
            in_range = True              # if true, switch in range to true.
            
        else:
            in_range = False             # else, inrange remains false and print error.
            print("Invalid Input, not within valid range. 1-5 \n")
        if in_range:                     # continuing... if in range... print the corresponding answer to the questions prompted in initial choice input function.
            if choice == 1:
                print("The total cases of Monkeypox in the following countries: US, UK, Brazil, Spain, Germany, and France is ..." , totallist , "\n")
            elif choice == 2:
                print("The average cases of Monkeypox within the countries: US, UK, Germany, Brazil, Spain, and France is ..." , avglistcases , "\n")
            elif choice == 3:
                print("The average deaths due to Monkeypox within the countries: US, UK, Germany, Brazil, Spain, and France is..." , avglistdeaths , "\n")
            elif choice == 4:
                print("If you factor out the cases within the countries: US, UK, Brazil, Germany, Spain, and France there are ..." , remainingMP , "cases distributed between the rest of the world. \n")
            else:                        # Otherwise - (only other option being 5), end the program and notify.
                print("Your request to halt continuation of program is granted. \n")
                break
    else:
        print("Input not a valid digit \n")   # output for error if initial digit check fails.
    
