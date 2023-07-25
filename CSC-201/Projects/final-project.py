# Nathaniel J Brown
# CSC 201: Programming with Data Science
# December 5, 2022
# Fall 2022
#### TITLE : THE FINAL PROJECT  DATA ANALYSIS PROGRAM #####
### DESCRIPTION: This final project will compile a variety of programs we have worked on throughout the semester
# into one master program that fully details a variety of aspects of our project topics, and our initial data-driven
# questions formulated at the start of the semester. Utilizing all of the skills we have developed thus far, we will 
# be able to thoroughly analyze, detail, and summarize all of the data we have investigated to this point.
### GENERAL SOLUTION: Since the project is primarily a rework of material that we have already completed. A lot of our
# code can be reused. AS such I will break the coding and pseudocode of this project into the respective 'user input choice'
# sections. Each section will essentially be its own program, with its own 'main' function that will later be called within,
# the final projects main function, in relation to if statements depending upon the users choice. (i.e. what question they want
# an answer to from 1-8.) As well as outputting respective errors, as needed. Then an additional section will be added to output,
# general information on the data driven questions, as well as the findings of the overall projects work. After all of these pieces
# are compiled together within a master main function. The program will be functional and meeting the requirements of the 
# final assignment.
###########################################################################################################
# START OF IMPORTS AND SETTINGS
###########################################################################################################

# import libraries needed for this program
import csv, numpy as np, pandas as pd, matplotlib.pyplot as plt
from scipy.stats import linregress

# adjust display settings for DataFrame to show more rows and columns from it
pd.set_option('display.max_rows', 10)
pd.set_option('display.max_columns', 500)
pd.set_option('display.width', 1000)

###########################################################################################################
# END OF IMPORTS AND SETTINGS
###########################################################################################################


###########################################################################################################
# START OF MENU OPTIONS 1 THRU. 8
###########################################################################################################  

# function name: overview
# arguments: none
# return: none
# description: outputs an overview of your topic and data set
def overview():
    print('\n####################################################################################################################')
    print('\t\t\t\t\tOriginal Survey on Monkeypox\n')
    print('This dataset is compromised of responses to our original data survey collected at the start of the semester, formulated around key initial data-driven questions.')
    print('')
    print('The columns in my data set are as follows: Age, a self-reported claim to knowledge / familiarity, a demonstration of knowledge metric, what the user thought the origin country for Monkeypox was, and finally an opinion as to the cause of spread of the virus.')
    print('\n####################################################################################################################\n')

###########################################################################################################
# END OF MENU OPTIONS 1 THRU. 8
###########################################################################################################    


###########################################################################################################
# START OF GETTING AND CHECKING USER INPUT CHOICE(S)
########################################################################################################### 

# function name: check_choice
# arguments: 2 integer values representing the minimum and maximum numbered options in the menu
# return: the valid input (i.e., a positive digit between the passed minimum and maximum arguments)
# description: asks the user for their choice and then checks that the user's input is a valid digit 
#              between the minimum and maximum arguments passed to it 
#              it keeps asking the for input until the user enters valid input (i.e., a positive digit 
#              between between the passed minimum and maximum arguments)
def check_choice(minimum, maximum):
    # define string variable that is empty to hold user's input
    some_input = ''
    
    # loop until the user's input is no longer empty
    while some_input == '':
        # ask the user to input their choice and store in a variable
        some_input = input('Choice: ')
        
        # check if the user's input does not contain only digits
        if some_input.isdigit() == False:
            # output an error message stating that the user did not enter input with only digits
            print('\nYou did not enter input with only digits! Try again.\n')
        
        # otherwise (i.e., the user's input contains only digits)
        else:
            # convert the user's input to an integer
            # "1" --> 1
            some_input = int(some_input)

            # check if the user's input is less than the minimum or greater than the maximum
            if some_input < minimum or some_input > maximum:
                # output an error message stating that the user did not enter input between 1 and 5
                print('\nYou did not enter a valid choice. Choose any option from ' + str(minimum) + ' to ' + str(maximum) + '.\n')
    
    # return the user's input 
    return some_input


# function name: get_choice
# arguments: none
# return: the valid input (i.e., a positive digit between 1 and 5)
# description: outputs the list of five choices for the main menu and calls the check_choice function 
#              passing it 1 as the minimum and 5 as the maximum to obtain a valid input from the user 
def get_choice():
    # output the list of options the user can choose from
    # choice 1 --> Overview of the [YOUR DATA SET NAME] Data Set
    # choice 2 --> Data-Driven Questions and Predictions
    # choice 3 --> Basic Statistics on [YOUR DATA SET NAME]
    # choice 4 --> Simple Data Visualizations on [YOUR DATA SET NAME]
    # choice 5 --> Survey Analysis
    # choice 6 --> Data Set Analysis
    # choice 7 --> Findings and Observations
    # choice 8 --> Quit
    print('Choose one of the options below to view the data analysis for this data set and its data-driven question.\n')    
    
    print('1. Overview of the Original Survey on Monkeypox Data Set')
    print('2. Data-Driven Questions and Predictions')
    print('3. Basic Statistics on Original Survey Data on Monkeypox')
    print('4. Simple Data Visualizations on Original Survey Data on Monkeypox')
    print('5. Survey Analysis')
    print('6. Data Set Analysis')
    print('7. Findings and Observations')
    print('8. Quit.\n')
    
    
    # call the check_choice function passing it 1 as the minimum and 8 as the maximum
    #      store the returned value in a variable
    choice = check_choice(1, 8)
     
        
    # return the user's input that was stored in the variable above
    return choice

###########################################################################################################
# END OF GETTING AND CHECKING USER INPUT CHOICE(S)
########################################################################################################### 

###########################################################################################################
# START OF CHOICE TWO: DATA DRIVEN QUESTIONS AND PREDICTIONS
########################################################################################################### 
# function will print a lot of text, that outputs the data driven questions, predictions, as well as relevant columns of the original data set collected way back at the start of the semester.
def dq():
    print('\n####################################################################################################################')
    print('\t\t\t\t\t DATA-DRIVEN QUESTIONS AND PREDICTIONS\n')
    print('Question 1: \n')
    print("What countries are currently (Fall 22') have the most cases of Monkeypox? \n")
    print('')
    print("The Country, Confirmed, and Suspected columns would be analyzed in reference to this question. The confirmed and suspected columns will inform me of the amount of infected cases, and the corresponding country will inform me which countries are the most affected by the virus. \n")
    print("Prediction: I believe, upon initial inspection, the United States, China or India will have the highest rates of infection. My rationality for this prediction is due to the overall country population of the two countries, and the nature of viral infections flourishing in dense populations. \n")

    print('Question 2: \n')
    print("Is there a relationship between Monkeypox cases and country's continent? \n")
    print('')
    print("The previously mentioned columns would also be involved in reference to this question. However, additionally once the most infected countries are identified an additional column could be added to the data. This new column would represent the continent that a country is located in, this continent column could have a related column that tallies the confirmed, and suspected cases of all countries that are within the continent. Thus, I can then come to a possible conclusion on any relationship between a countries cases and the country's corresponding continent. \n")
    print("Prediction: I believe there will be a correlation between highly-infected countries and their respective continents. As the nature of a virus spreads from person to person, an on the ground interaction is typically required for the virus to continue. Further, I'd be willing to predict that dependent on the level of international-relations between countries in a continent the correlation would shift either towards a stronger correlation or a weaker one. \n")

    print('Question 3: \n')
    print("Are infected patients found to have been travelling more frequently? \n")
    print('')
    print("By examining the confirmed cases, suspected cases, travel-yes, and travel-no columns I would be able to identify whether or not there is a increased rate of infection between infected patients and whether or not they have travelled. \n")
    print("Prediction: I believe there will be a relation, where increased travel-yes values will correlate to a higher overall confirmed and suspected cases within a country. My rational for this prediction is based in background knowledge, considering most countries during the viral covid19 crisis closed their borders and refused travel to and from their countries. \n")

    print('Question 4: \n')
    print("Where have the travelling infected-patients been traveling? \n")
    print('')
    print("Currently the data does not support the investigation of this question. Further data would need to be collected for the current data set to apply to the question. However, this does not take away from the relevance of the question related to the topic. \n")
    print("Prediction: Without a current means of investigating the question, a purely speculative prediction from me is that; provided country infection rates are correlated to the number of confirmed and suspected cases, I believe the infected-patients would have recently travelled to or from either areas surrounding Nigeria or the United Kingdoms. My rationality for that is based solely on the current evidence linking Nigeria and the United Kingdoms as plausible origin points. \n")
    
    print('Question 5: \n')
    print("How knowledgeable are people on the Monkeypox virus? \n")
    print('')
    print("The current dataset found, does not include data that can correlate to this questions. The dataset utilized answers most of the questions above. Perhaps this question could be addressed through the Original Data Survey. \n")
    print("Prediction: I believe people will be fairly knowledgeable as to what Monkeypox does to the infected, but less knowledgeable on transmission and severity (or lack-there-of) of the virus. \n")

    print('\n####################################################################################################################\n')
###########################################################################################################
# END OF CHOICE TWO: DATA DRIVEN QUESTIONS AND PREDICTIONS
########################################################################################################### 

###########################################################################################################
# START OF CHOICE THREE: BASIC STATISTICS. --- A.K.A ASSIGNMENT 8: PROGRAMMING WITH DATA USING FUNCTIONS
########################################################################################################### 

# ---------- Define Functions Main, Title, Get/Check, Questions ------------
def mainASS1():          #main function, runs and calls the below defined functions to satisfy program requirements
    title_msgASS1()      #Title function, displays title and Source.
    check_choiceASS1(get_choiceASS1())  #Runs function to check choice validitiy for range, and digit status. Passed output of get_choice as a parameter to check_choice.  <===
def title_msgASS1():     #Prints title and where data was collected.
    print("\nAssignment 8 - Programming With Functions. \nThis data was collected from the CDC heatmap of Monkeypox.\n")
def get_choiceASS1():    #\n Function to get choice integer value for use in check_choice function
    choice = int(input("""\nWhich quick Monkeypox fact would you like the answer to?
    If you do not wish to continue please type '5'. Thank you.
    1.) What is the total cases amongst the most infected countries; US, UK, Brazil, Spain, Germany, and France?
    2.) What is the average amount of cases between the aforementioned most infected countries?
    3.) What is the average deaths of the aforementioned most infected cases?
    4.) How many cases are in the rest of the world?
    5.) Type '5' if you do not wish to continue... \n"""))
    return choice  #returns value of choice for later use.

def check_choiceASS1(check_valASS1):   #Function that use checks_val parameter to Passing output of get_choice, using check_val, to check_choice for range validitty check.
    if check_valASS1 in list(range(1,6)):    # check if within range established in variables (i.e. 1-5)
            in_rangeASS1 = True              # if true, switch in range to true.
            
    else:
        in_rangeASS1 = False             # else, inrange remains false and print error.
        print("\nInvalid Input, not within valid range. 1-5 \n")
    if in_rangeASS1:                     # continuing... if in range... redirect to run appropriate function for question.
        if check_valASS1 == 1:   # If check_val (i.e. choice) = x, run question x calc function
            q1ASS1()             # run function for question
            check_choiceASS1(get_choiceASS1()) # IN ORDER TO LOOP - TO ALLOW REPEAT QUESTIONS, Call check_choice funciton with parameter of get_choice.
        elif check_valASS1 == 2:
            q2ASS1()
            check_choiceASS1(get_choiceASS1())
        elif check_valASS1 == 3:
            q3ASS1()
            check_choiceASS1(get_choiceASS1())
        elif check_valASS1 == 4:
            q4ASS1()
            check_choiceASS1(get_choiceASS1())
        else:                        # Otherwise - (only other option being 5), end the program and notify.
            print("\nYour request to halt continuation of program is granted. \n")
    else:
        print("\nInput not a valid digit \n")   # output for error if initial digit check fails.
        check_choiceASS1(get_choiceASS1())
def q1ASS1(): # runs calculation for question and prints appropriate response.
    MPUS = 27558        #US Cases of MP
    MPBZ = 8652         # Brazil Cases of MP
    MPSP = 7239         # Spain Cases
    MPF = 4064          # France C
    MPUK = 3673         # UK C
    MPG = 3656          # Germany C
    totallist = MPUS + MPSP + MPF + MPBZ + MPG + MPUK #calculates total of examined countries
    print("\nThe total cases of Monkeypox in the following countries: US, UK, Brazil, Spain, Germany, and France is ..." , totallist , "\n")
def q2ASS1(): # runs calculation for question and prints appropriate response.
    MPUS = 27558        #US Cases of MP
    MPBZ = 8652         # Brazil Cases of MP
    MPSP = 7239         # Spain Cases
    MPF = 4064          # France C
    MPUK = 3673         # UK C
    MPG = 3656          # Germany C
    avglistcases = MPUS + MPSP + MPF + MPBZ + MPG + MPUK // 6  #Calculates Average Cases between examined countries
    print("\nThe average cases of Monkeypox within the countries: US, UK, Germany, Brazil, Spain, and France is ..." , avglistcases , "\n")
def q3ASS1(): # runs calculation for question and prints appropriate response.
    MPUSD = 3           #US Deaths by MP
    MPBZD = 7            # Brazil deaths by mp
    MPSPD = 2           # Spain Deaths
    MPFD = 0            # France D
    MPGD = 0            # Germany D
    MPUKD = 0           # UK D
    avglistdeaths = MPUSD + MPSPD + MPFD + MPBZD + MPGD + MPUKD // 6 #calculates average of deaths between examined countries
    print("\nThe average deaths due to Monkeypox within the countries: US, UK, Germany, Brazil, Spain, and France is..." , avglistdeaths , "\n")
def q4ASS1(): # runs calculation for question and prints appropriate response.
    MPUS = 27558        #US Cases of MP
    MPBZ = 8652         # Brazil Cases of MP
    MPSP = 7239         # Spain Cases
    MPF = 4064          # France C
    MPUK = 3673         # UK C
    MPG = 3656          # Germany C
    GC = 72922          #Global Cases of Monkeypox (MP)
    totallist = MPUS + MPSP + MPF + MPBZ + MPG + MPUK #calculates total of examined countries
    remainingMP = GC - totallist #Calculates remaining cases distributed throughout the rest of the world. (i.e. not including examined countries)
    print("\nIf you factor out the cases within the countries: US, UK, Brazil, Germany, Spain, and France there are ..." , remainingMP , "cases distributed between the rest of the world. \n")
###########################################################################################################
# END OF CHOICE THREE: BASIC STATISTICS. --- A.K.A ASSIGNMENT 8: PROGRAMMING WITH DATA USING FUNCTIONS
########################################################################################################### 

###########################################################################################################
# START OF CHOICE FOUR: SIMPLE DATA VISUALIZATIONS. --- A.K.A ASSIGNMENT 9: PROGRAMMING WITH DATA USING LISTS
########################################################################################################### 
################# SCATTER VISUAL F #################
# This function creates and outputs a scatter chart based on the lists of x
# and y coordinates it recieves as arguments.
################# Scatter Start #################
def scatter_visASS2(scatx_coordsASS2, scaty_coordsASS2):       #def scat function, with x/y coords as parameters, defined in main()
    
    plt.scatter(scatx_coordsASS2, scaty_coordsASS2)        #plots scatter with afforementioned lists.
    
    plt.title("Confirmed Cases by Traveler Patients")      #Sets Scat Title
    plt.xlabel("Number of Traveler Patients")              #Sets x axis label
    plt.ylabel("Confirmed Cases")                          #Sets y axis label
    
    plt.xticks(scatx_coordsASS2)                       #plots ticks with x coords def in main() Below does same, but adds string replacement.
    plt.yticks(scaty_coordsASS2 , ['Brazil' , 'France' , 'Germany' , 'England' , 'Italy' , 'Argentina' , 'Denmark' , 'Bolivia'])
    
    plt.show()                                             #Shows plot
################# LINE VISUAL F #################
# This function creates and outputs a line chart based on the lists of x and y
# coordinates it receives as arguments.
################# Line Start #################
def line_visASS2(linex_coordsASS2 , liney_coordsASS2):         #def line func using x/y line coord lists as parameters defined in main()

    plt.title('United States Monthly Confirmed Cases')  #plots line title
    plt.plot(linex_coordsASS2, liney_coordsASS2)           #plots line with afforementioned list
    plt.show()                                     #shows line
    
################# BAR VISUAL F #################
# This function creates and outputs a bar chart based on the lists of x-coords
# of each bar's left edge and heights of each bar along the y-axis it recieves
# as arguments.
################# Bar Start #################
def bar_visASS2(left_edgesASS2, heightsASS2):                 #def bar func using lists as parameters that are def in main()

    plt.bar(left_edgesASS2, heightsASS2, color = {'r' , 'g' , 'b'})   # plots bar using afforementioned list and sets color of bars
    
    plt.title('Total Monkeypox by Continent')                 #Sets bar title
    plt.xlabel(' Continent ')                                 #sets x label
    plt.ylabel(' Confirmed Cases ')                           # sets y label

    plt.show()                                                #shows bar
################# PIE VISUAL F #################
# This function creates and outputs a pie chart based on the lists of values and
# slice labels it receives as an argument. 
################# PIE Start #################
def pie_visASS2(casesbycountryASS2 , slice_labelsASS2):       #def pie func using lists as parameters that are defined in main()
    plt.pie(casesbycountryASS2, labels = slice_labelsASS2, colors = {'b' , 'r' , 'm' , 'g' , 'k'})  #plots pie with aforementioned lists, sets colors.
    plt.title('Cases by Country')            # sets plot title
    
    plt.show()                               # show plot
################# MINIMUM VAL #################
# This function fidns the minimum value in a list that it receives as an argument.
################# Min Calc Start #################
def find_minASS2(some_listASS2):       #def func to detect minimum
    firstASS2 = some_listASS2[0]      # sets variable to equal first pos in a passed list
    
    for i in some_listASS2:       # for each i in afforementioned list
        if i < firstASS2:         # if less than defined variable
            firstASS2 = i         # redefine varible to = the index that met the if check
    return firstASS2              # return variable value for reuse and print functionality
    
################# MAXIMUM VAL #################
# This function fidns the maxium value in a list that it receives as an argument.
################# Max Calc Start #################
def find_maxASS2(some_listASS2):         #def function to detect max of passed list
    firstASS2 = some_listASS2[0]         #sets variable to equal first pos in afformentioned list
    
    for i in some_listASS2 :         #for each index in afformentioned list
        if i > firstASS2:            #if index is greater than variable
            firstASS2 = i            #redefine variable to equal the index
    return firstASS2                 # return variable for reuse and print functionality
################# Average Val #################
# This function finds the average value of a list that it receives as an argument.
################# Avg Calc Start #################
def find_avgASS2(some_listASS2):       #def function to detect average
    averageASS2 = 0                # sets a variable to equal 0
    for i in (some_listASS2):      # for each index within a passed list
        averageASS2 = sum(some_listASS2) / len(some_listASS2)       #calculate sum of afformentioned list, divided by the length of afforementioned list pos.
    return averageASS2             # return variable for reuse and print functionality
#
#
#
################# MAIN FUNCTION #################
# This function setups the program and manages calls to functions defined for
# creating the visualization and computing simple calculations
#
################# Main Start #################
def mainASS2():                                 #def main function to call all of afforelisted functions.
#The List-List of Variables  - passed to respective functions as per requirements of assignement.
#Scatter
    scatx_coordsASS2 = [20 , 2 , 19 ,  2 , 19 , 11 , 3 , 2]
    scaty_coordsASS2 = [6246 , 3824 , 3547 , 3383 , 813 , 221 , 183 , 125]
#Line
    linex_coordsASS2 = ['May', 'June', 'July', 'August', 'September']
    liney_coordsASS2 = [21, 408, 4057, 10338, 3129]
#Bar
    left_edgesASS2 = [ 'NA' ,'SA'  , 'EU']
    heightsASS2 = [ 25269 , 10501 , 23627 ]
#Pie
    casesbycountryASS2 = [28377 , 3689 , 9813 , 3662, 4092]
    slice_labelsASS2 = ['United States' , 'United Kingdoms' , 'Brazil' , 'Germany' , 'France']
#Max/Min/Avg Variables   - all used for print statements later in the main() to display info required for assignment.
#    
    miniASS2 = "The minimum value is... "  # strings so i dont have to type
    maxiASS2 = "The maximum value is... "  #     ^   ^
    avgASS2 = "The average value is... "   #    ________
#
    scatmaxASS2 = find_maxASS2(scaty_coordsASS2)
    scatminASS2 = find_minASS2(scaty_coordsASS2)
    scatavgASS2 = find_avgASS2(scaty_coordsASS2)
    linemaxASS2 = find_maxASS2(liney_coordsASS2)
    lineminASS2 = find_minASS2(liney_coordsASS2)
    lineavgASS2 = find_avgASS2(liney_coordsASS2)
    barmaxASS2 = find_maxASS2(heightsASS2)
    barminASS2 = find_minASS2(heightsASS2)
    baravgASS2 = find_avgASS2(heightsASS2)
    piemaxASS2 = find_maxASS2(casesbycountryASS2)
    pieminASS2 = find_minASS2(casesbycountryASS2)
    pieavgASS2 = find_avgASS2(casesbycountryASS2)
#
#### Call Chart functions ####
## Max / Min / Avg Functions after ##
    scatter_visASS2(scatx_coordsASS2, scaty_coordsASS2)      # calls scatter visual to print
    print(maxiASS2 , scatmaxASS2)                        # prints max, min, avg.
    print(miniASS2 , scatminASS2)
    print(avgASS2 , scatavgASS2)
    line_visASS2(linex_coordsASS2 , liney_coordsASS2)        # calls line visual to print
    print(maxiASS2 , linemaxASS2)                        # prints max, min, avg
    print(miniASS2 , lineminASS2)
    print(avgASS2 , lineavgASS2)
    bar_visASS2(left_edgesASS2 , heightsASS2)                #calls bar visual to print
    print(maxiASS2 , barmaxASS2)                         # prints max, min, avg
    print(miniASS2 , barminASS2)
    print(avgASS2 , baravgASS2)
    pie_visASS2(casesbycountryASS2 , slice_labelsASS2)       # calls pie visual to print
    print(maxiASS2 , piemaxASS2)                         # prints max, min, avg
    print(miniASS2 , pieminASS2)
    print(avgASS2 , pieavgASS2)
###########################################################################################################
# END OF CHOICE FOUR: SIMPLE DATA VISUALIZATIONS. --- A.K.A ASSIGNMENT 9: PROGRAMMING WITH DATA USING LISTS
########################################################################################################### 

###########################################################################################################
# START OF CHOICE FIVE: SURVEY ANALYSIS. --- A.K.A ASSIGNMENT 10: PROGRAMMING WITH NUMPY AND DICTIONARIES
########################################################################################################### 
##### Check Age Function #####
# This function checks if the age contains only digits, OR that the first two characters contain
# only digits. (i.e. 21yrs, becomes 21) AND if the age is between 0 and 150
# arguments - 1 string representing the age of respondent
# return - 1 boolean (i.e. true or false) if the age is valid.
def chk_ageASS3(some_ageASS3):                                    #def function to check age
    val_ageASS3 = True                                        #start with a true value
    if some_ageASS3.isdigit() or some_ageASS3[0:2].isdigit():     #if age is a digit, or first two positions are digits stay true
        if len(some_ageASS3) > 2 and some_ageASS3[2].isdigit():   #if above, check if length greater than 2 and first two positions are true
            ageASS3 = int(some_ageASS3[0:3])                         #make a variable for the age saved as an integer
        else:
            ageASS3 = int(some_ageASS3[0:2])                      # else, use two position integer
        if ageASS3 < 0 or ageASS3 > 150:                          # check if age is outside of reasonable bounds 0-150. 
            val_ageASS3 = False                               # make false if outside
    else:
        val_ageASS3 = False                                   #otherwise make false
    return val_ageASS3                                        #return validity value for future use.
##############################
##### Check Linear Scale #####
# This function checks if rating contains only digits and if the rating is between the specified
# scale (i.e. 1 to 5, 1 to 10 etc.)
# arguments - 1 string representing the rating given for a linear scale question.
# returns - 1 boolean (i.e. true or false) if the rating is valid.
def chk_linscaleASS3(some_linASS3):                               #def function to check linescale validity
    val_linscaleASS3 = True                                   #start with true value
    if some_linASS3.isdigit():                                #if passed parameter is digit
        ratingASS3 = int(some_linASS3)                            #define variable with integer of above.
        if ratingASS3< 0 or ratingASS3 > 3:                      #check to see if its within 0-3
            val_linscaleASS3 = False                          #if not false
    else:
        val_linscaleASS3 = False                              #anything else, change to false.
    return val_linscaleASS3                                   #return validity variable for future use.
##############################
##### Check Multiple Choice #####
# Thsi function checks if the choice for the multiple choice question is not empty and is one of the
# provided choices for the question.
# arguments - 1 string representing the choice given for a multiple choice question
# return - 1 boolean (i.e. either true or false) if the choice is valid.
def chk_mpchoiceASS3(some_choiceASS3):                           #def function to check multiple choice validitiy
    val_mpchoiceASS3 = True                                  #start with true
    if (some_choiceASS3 == "Swollen Lymph Nodes, Flu-like Symptoms, and a rash that forms blisters.") or (some_choiceASS3 == "Dementia" ) or (some_choiceASS3 == "Respiratory Complications and Flu-like Symptoms") or (some_choiceASS3 == "Brain Lesions") :
        val_mpchoiceASS3 = True                              # if passed argument (some_choice) is one of the 4 options, maintain true.
    else:                                                # otherwise, change to false.
        val_mpchoiceASS3 = False
    return val_mpchoiceASS3                                  #return validity variable for future use.
    
##############################
##### Read CSV #####
# This function opens and reads the survey CSV responses and checks/cleans invalid data entries in
# each row of the file.
# arguments - 1 string representing the name of hte survey responses csv file
# return - at least 1 list containing valid/cleaned responses for your linear rating scale question
#and at least 2 integer variables containing counts for your provided choices in your multiple choice
# questions.
def read_csvASS3(fileASS3):                               #def function to read csv file
    lineratingsASS3 = []                              #establish array for linerattings, and counts for ans 1 - 4
    ans1ASS3 = 0
    ans2ASS3 = 0
    ans3ASS3 = 0
    ans4ASS3 = 0
    
    with open(fileASS3) as csv_infile:                 #with the file open
        reader = csv.DictReader(csv_infile)        # define variable for csv.dictreader
        for row in reader:                         # for each row in afforementioned variable
            if chk_ageASS3(row["What is your age?"]) == False:      #check if row for age triggered false in previous check. Inform what is wrong.
                print("Error on line" , str(reader.line_num) , ":" , row["What is your age?"] , " not integer or out of range.")
            if chk_linscaleASS3(row["How familiar are you with the monkeypox outbreak? (2 being, you have just heard of it.)"]) == False:  #check if row for linear triggered false in previous check. Inform what is wrong.
                print("Error on line" , str(reader.line_num) , ":" , row["How familiar are you with the monkeypox outbreak? (2 being, you have just heard of it.)"] , " not integer or out of range. ")
            if chk_mpchoiceASS3(row["What are the symptoms of Monkeypox?"]) == False:  #check if row for multiplechoice triggered false in previous check. Inform what is wrong.
                print("Error on line" , str(reader.line_num) , ":" , row["What are the symptoms of Monkeypox?"] , " multiple choice response was left blank.")
            else:                                 #otherwise, add to array or respective count... respectively?
                lineratingsASS3.append(int(row["How familiar are you with the monkeypox outbreak? (2 being, you have just heard of it.)"]))
                ans1ASS3 += row["What are the symptoms of Monkeypox?"].count("Swollen Lymph Nodes, Flu-like Symptoms, and a rash that forms blisters.")
                ans2ASS3 += row["What are the symptoms of Monkeypox?"].count("Dementia")
                ans3ASS3 += row["What are the symptoms of Monkeypox?"].count("Respiratory Complications and Flu-like Symptoms")
                ans4ASS3 += row["What are the symptoms of Monkeypox?"].count("Brain Lesions")
    return lineratingsASS3 , ans1ASS3 , ans2ASS3 , ans3ASS3 , ans4ASS3               #return newly defined variables that have been cleaned, for future plotting.
            
##############################
##### plot linear rating #####
# this function plots a histogram with the ratings for your linear scale question
# arguments 1 list containing integer ratings to your linear scale question
def plt_linearASS3(some_listASS3):   #def function to plot linear scale using passed list.
    plt.hist(some_listASS3, bins=5)   #plots histogram, with list and 5 bins.
    plt.title("Self Reported Linear Scale of Knowledge")       #plots title for histogram
    plt.ylabel("1 = No Knonwleldge  ||  2 = Some Knowledge  ||  3 = Informed")   #plots labels for scale definitions
    plt.xticks(some_listASS3)       #plots x ticks using the list
    
    computeASS3(some_listASS3)          #run computaion to uncover mean of somelist.
    
    plt.show()                 # plot the chart.
##############################
##### plot counts #####
# This function plots a pie chart based on the counts for each choice in the multiple choice question.
# arguments at least 2 integer variables storing the counts for each choice in your multiple choice question.
def plt_countsASS3(ans1ASS3 , ans2ASS3 , ans3ASS3 , ans4ASS3):         #def function to plot counts using ans variables from multiple choice csv_read() and mpcheck.
    countsASS3 = [ ans1ASS3 , ans2ASS3 , ans3ASS3 , ans4ASS3]          #def the counts as a singular variable array.
    countlabelsASS3 = ['Swollen Lymph Nodes, Flu-like Symptoms, and a rash that forms blisters.' , 'Dementia' , 'Respiratory Complications and Flue-Like Symptoms' , 'Brain Lesions']
    plt.pie(countsASS3 , labels = countlabelsASS3 , colors = {'b' , 'r' , 'm' , 'g'})    #above provides labels, then plot pie using two new variables. And sets chart colors.
    plt.title('What are the symptoms of Monkeypox?')  #sets plot title
    plt.show()                             #prints the plot
##############################
##### compute #####
# this function computes a data statistic using the numpy module(i.e mean, median, standard deviation)
#with the ratings for your linear scale question
# arguments - 1 list containing ratings to your linear scale questoin
# return - 1 float containing the computed data statistic on the lsit of ratings passed to it
def computeASS3(line_ratingsASS3):               #def function to compute line_ratings array from earlier.
    computelineASS3 = np.mean(line_ratingsASS3)    #establish variable that equals numpy mean of afforementioned passed list.
    print("The mean of the Self Reported Linear Scale of Knowledge:" , computelineASS3)    #print the calculation with words to give reference.
##############################
##### MAIN FUNCTION #####
# This function setups the program and manages call functions defined for specified processing,
# calculations, visualizations and output.
def mainASS3():            #defines main function used to execute the entire program.
    masterfileASS3 = "brown_survey.csv"              #establishes variable for csv file used throughout the cleaning section of program
    lineratingsASS3 , ans1ASS3 , ans2ASS3 , ans3ASS3 , ans4ASS3 = read_csvASS3(masterfileASS3)     #establishes variables for the cleaned data within the csv file.
    plt_linearASS3(lineratingsASS3)          #runs plot linear function using lineratings
    plt_countsASS3(ans1ASS3 , ans2ASS3 , ans3ASS3 , ans4ASS3)    #runs plot pie function using the counts
###########################################################################################################
# END OF CHOICE FIVE: SURVEY ANALYSIS. --- A.K.A ASSIGNMENT 10: PROGRAMMING WITH NUMPY AND DICTIONARIES
########################################################################################################### 

###########################################################################################################
# START OF CHOICE SIX: DATASET ANALYSIS. --- A.K.A ASSIGNMENT 12: CLEANING, SUMMARIZING AND VISUALIZING DATAFRAMES
########################################################################################################### 
##### READ AS DATAFRAME #####
#this function converts the data in a CSV file to a pandas data frame. 
# Arguments - 1 
# Returns - 1
def read_as_dataframeASS4(masterfileASS4):    #defines function to read csv file and make dataframe for use throughout the assignment. Pushes masterfile for csv reading.
    df = pd.read_csv(masterfileASS4)      # sets variable definition to be returned, dataframe.
    #df = og.astype({"Age":"int"})     
    return df                         #returns df variable, for usage later in the main()

##############################
#### VISUAL INSPECT ####
#This function visually inspects the dataframes to diagnose it for common data errors.
#Arguments - 1 Pandas DataFrame
#Return - None
def visual_inspectASS4(wholeASS4):
#info section
    print(" --- Below is the Info() --- \n\n")   #below prints the info of each column, displaying the Non-Null Count and Data Type of each column.
    wholeASS4.info()
    print("\n\n")
    print(" --- Below is the Head() --- \n\n") #below prints the first 5 rows of the csv file.
    print(wholeASS4.head() , "\n\n")
    print(" --- Below is the Tail() --- \n\n") #below prints the last 5 rows of the csv file.
    print(wholeASS4.tail() , "\n\n")
    
    print(" --- Below is a list of Columns() --- \n\n") #below prints a list of each column in the csv file, to manually scan for errors.
    print(wholeASS4.columns , "\n\n")
    print(" --- Below is the Shape() --- \n\n")   #Below lists an ordered pair where x = the number of rows, and y = the number of columns in the csv file.
    print(wholeASS4.shape , "\n\n")
#value counts section
    print(" --- Below is a Value Count of Opinion: Belief of Spread Column \n\n") #below prints the value counts of 'Belief of Spread' column, displaying a count for each response and identifying blank responses.
    print(wholeASS4['Opinion: Belief of Spread'].value_counts(dropna = False) , "\n\n")
#describe section
    print(" --- Below is Description of Age Column \n\n") #Below we describe the age numerical column to identify key statistics relating to the column.
    print(wholeASS4['Age'].describe() , "\n\n")
##############################
#### CLEAN DATAFRAME ####
# after visually ispecting, this function will resolve data errors that you found in your inspection.
# You can use any of the techniques to clean data discussed in the lecture such as dropping missing
# values or filling values. Dropping duplicate rows, replacing erroneous data, formatting vlaues, and 
# converting columns to their proper type.
#arguements 1 - Panda Dataframe that is NOT CLEAN
#returns 1 - Panda Dataframe that is cleaned.
def cleaned_dataframeASS4(wholeASS4):
    wholeASS4["Opinion: Belief of Spread"] = wholeASS4["Opinion: Belief of Spread"].str.replace('None' , 'Monkey') # replaces strings of 'none' wtih string of 'monkey'
  #  whole["Age"] = whole["Age"].astype(int) #not necessary, but no column meets this requirement of hte rubric. So here is a demonstration of it.
  #  whole['Familiarity Level'] = whole['Familiarity Level'].astype(int)
    wholeASS4['Opinion: Belief of Spread'] = wholeASS4['Opinion: Belief of Spread'].astype('category')
    wholeASS4['Opinion: Most Infected'] = wholeASS4['Opinion: Most Infected'].astype(str)
    print(" --- Below is a print of the cleaned Data Types --- \n\n" , wholeASS4.dtypes , "\n\n")
    return wholeASS4
##############################
##### GET SUBSET #####
# Using the cleaned pandas dataframe, create filtered subset to narrow down and perform computations
# on particular information that will serve as supporting evidence to some of the questions posed on the topic.
# Arguements 1 - Dataframe that has been CLEANEd
# Returns 1 - subset of cleaned dataframe.
def get_subsetASS4(cleanASS4): # defines the functoin to establish a subset, by passing the cleaned csv
    knowledge_subASS4 = cleanASS4[cleanASS4['Opinion: Belief of Spread'] == 'Skin to Skin']   # establishes a variable that filters the cleaned data frame, by column 'Belief of Spread, filtering only responses that contain the answer ' Skin to Skin' for future computations.
    return knowledge_subASS4  #returns this variable, for future use.
##############################
#### GROUP BY SUMMARY TABLE ####
# Passing cleaned subset dataframe; creates summary table of data.
# Arguments 1 - Cleaned data subset.... i.e. clean_subset
# returns 1 - Groupby Summary table
def groupby_sum_tableASS4(clean_subsetASS4): #this function creates a group by summary table, using the cleaned subset data. Filtered by age. Displaying Median ratings for numerical columns.
    groupby_tableASS4 = clean_subsetASS4.groupby('Age' , as_index = False).median() # sets to group by age, and runs median computation as per requirements.
    print(groupby_tableASS4) #prints previously defined function for ease of confirmation.
    clean_subsetASS4.reset_index() #resets the index of the passed argument for future use.
    return groupby_tableASS4   #returns the pivot table variable, for future use.
##############################
#### PIVOT TABLE FUNCTION ####
# Passing the cleaned data, create a piv table, that relates to questions posed earlier in the semester. NOTE === NOT THE FILTERED SET; for better storytelling.
# Arguments 1 - Cleaned data subset passed.
# Returns 1 - Piv Summary Table
def piv_sum_tableASS4(cleanASS4): # This function creates pivot table.
    pivot_tableASS4 = cleanASS4.pivot_table('Age' , index = 'Demonstrate Knowledge' , aggfunc = [np.average] , margins = False) #establishes pivot table variable, with age and demonstrate knowledge columns, then runs an average calculation, and does NOT print a total section.
    print(pivot_tableASS4) #prints table for confirmation.
    cleanASS4.reset_index() # reset index as per requirements; and for efficiency.
    return pivot_tableASS4 #returns the previously defined variable for future use.
################# SCATTER VISUAL #################
# this is using cleaned whole dataframe.
def scat_visASS4(cleanASS4):         #def scatter func using cleaned dataframe as parameters defined in main()
    xASS4 = cleanASS4['Age']    #defines x as the age column of the cleaned csv
    yASS4 = cleanASS4['Familiarity Level']  #defines y as the familiarity level column of the cleaned csv
    plt.scatter(xASS4 , yASS4)            # plots a scatter using the afforementioend defined x, y.
    
    plt.title("Scatter of Familiarity of Monkeypox by Age")  #scatter relevant title
    plt.xlabel("Age") #label for x
    plt.ylabel("Self-Reported Familiarity Level") #label for y
    plt.show() #prints the scatter plot
################# LINE VISUAL #################
# this is used using cleaned whole dataframe
def line_visASS4(cleanASS4): #defines line visual using the cleaned data frame as a parameter defiend in main()
    xASS4 = cleanASS4['Age']  #defines x as being the age column of the cleaned dataframe
    yASS4 = cleanASS4['Familiarity Level'] #defines y as familiarity level of the cleaned dataframe
    plt.plot(xASS4 , yASS4) #plots the line plot using the afforementioned x and y variables.
    
    plt.title("Line of Familiarity of Monkeypox by Age") #relevant title
    plt.xlabel("Age") # x axis label
    plt.ylabel("Self-Reported Familiarity Level") #y axis label
    plt.show()
################# Bar VISUAL ################# 
#this is used using cleaned whole dataframe
def bar_visASS4(cleanASS4):  #defines a bar visual function using the cleaned data set variable as a parameter, passed from the main()
    xASS4 = cleanASS4['Age'] #defines x as the age column of the cleaned csv
    heightsASS4 = cleanASS4['Familiarity Level'] #defines heights of the bars to be the familiarity level of the cleaned csv
    plt.bar(xASS4 , heightsASS4) #plots a bar chart using the afforementioned x and heights variable
    
    plt.title("Bar of Familiarity of Monkeypox by Age") # Relevant title
    plt.xlabel("Age") #x label
    plt.ylabel("Self-Reported Familiarity Level") #y label
    plt.show() #prints the plot
############### SUM TABLE VISUAL ################
# THIS ONE IS USING THE SUM TABLE AS PER REQUIREMENTS # <<<<<<<<<<<
def sum_table_visASS4(group_tableASS4): # defines a summary table visual, in the form of a pie chart. Using the groupby summary table established previously, passed as a parameter through the main()
    group_tableASS4.plot.pie(x = "Age" , y = "Demonstrate Knowledge") #link's the group_table variable to the pie plot, in a succinct quick manner. Defining x as the age column and y as the demonstrates knowledge column.
    
    plt.title("Summary Table Pie: Demonstrated Knowledge") #relevant title for the plot.
    
##### MAIN FUNCTION #####
# This function sets up the program and manages calls to functions defined for reading the csv
# file into a pandas dataframe, visually inspects and cleans the dataframe of common data errors,
# and creates summary tables and visualizations from the cleaned dataframe and its filtered subsets.
def mainASS4():            #defines main function used to execute the entire program.
    masterfileASS4 = "dataframes.csv"      #variable name of csv file used throughout.
    wholeASS4 = read_as_dataframeASS4(masterfileASS4) #dataframe variable name, equating to the read_as() with passed parameter of the csv file variable.
    visual_inspectASS4(wholeASS4)             #calls the visual inspect functoin, passed the 'whole' dataframe file established in the above line.
    cleanASS4 = cleaned_dataframeASS4(wholeASS4)    #calls the clean dataframe function, passing the whole (original csv) into it.
    #print(clean.info() , clean['Age'].info() , clean['Opinion: Belief of Spread'].value_counts(dropna = False))
    clean_subsetASS4 = get_subsetASS4(cleanASS4) #establishes variable, that represents the get_subset() function with the passed cleaned dataframe... For use in the filtered data summary table below.
    group_tableASS4 = groupby_sum_tableASS4(clean_subsetASS4) #establishes a variable that can be called to create the groupby sum table. (of median numerical data columns)
    pivot_tableASS4 = piv_sum_tableASS4(cleanASS4) #establishes pivot table variable as the piv_sum+table function with a passed parameter of hte clean variable defined above.
    scat_visASS4(cleanASS4) #scatter function, passed cleaned dataframe
    bar_visASS4(cleanASS4) # bar, same as above
    line_visASS4(cleanASS4) #line, same as above.
    sum_table_visASS4(group_tableASS4) # Visual passed the groupby_sum_table variable, which is a main requierment of the visual aspect of the assignment.
###########################################################################################################
# END OF CHOICE SIX: DATASET ANALYSIS. --- A.K.A ASSIGNMENT 12: CLEANING, SUMMARIZING AND VISUALIZING DATAFRAMES
########################################################################################################### 

###########################################################################################################
# START OF CHOICE SEVEN: FINDINGS AND OBSERVATIONS
########################################################################################################### 
def findings():
    mainASS4()
    mainASS3()
###########################################################################################################
# END OF CHOICE SEVEN: FINDINGS AND OBSERVATIONS
########################################################################################################### 

###########################################################################################################
# START OF SETUP --> WELCOME MESSAGE AND MAIN FUNCTION
###########################################################################################################

# function name: welcome_msg
# arguments: none
# return: none
# description: outputs the title of the program and where the data was collected from (i.e., website, data set)
def welcome_msg():
    dq = 'How knowledgeable are people on the Monkeypox virus?'
    
    print('\t\t\t\t\tOriginal Survey on Monkeypox: ')
    print('\t\t\t\t' + dq.upper())
    print('\n')
    print('\t\t\tWelcome to the Original Survey on Monkeypox data set analysis program!\n')


# function name: main
# arguments: none
# return: none
# description: setups the program and manages calls to other functions defined to handle the eight options
#              it repeats the eight options until the user chooses the option to quit
def main():
    # call welcome_msg function to output the title of the program and where the data was collected from
    welcome_msg()
    
    
    # flag variable keeping track of if the survey data has already been processed/cleaned
    #      assume at the beginning of program that survey data has NOT been processed/cleaned
    #      update this flag variable when the 5th or 7th option have been chosen for the first time
    survey_processed = False
    
    
    # flag variable keeping track of if the DataFrame containing the data from your data set you found online 
    #      has already been processed/cleaned
    #      assume at the beginning of program that DataFrame has NOT been processed/cleaned
    #      update this flag variable when the 6th or 7th option have been chosen for the first time
    data_processed = False
    
    
    # define string variable that is empty to hold user's input
    choice = ''
    
    
    # loop until the user chooses the choice to quit the program
    while choice != 8:
        
        # call the get_choice function to get the choice from the user and store in variable
        choice = get_choice()
        
        # check if the user chose the first option
        if choice == 1:
            # call overview function to output an overview of your topic and data set
            overview()
        # check if the user chose the second option
        if choice == 2:
            dq()
        # check if the user chose the third option
        if choice == 3:
            #call the main assignment 8 function.
            mainASS1()
        # check if the user choice is the fourth option
        if choice == 4:
            #call the main assignment 9 function.
            mainASS2()
        # check if user choice is the fifth option
        if choice == 5:
            #call the main assignment 10 function
            mainASS3()
        # check if the user choice is the sixth option.
        if choice == 6:
            #call the main assignment 12 function
            mainASS4()
        # check if the user choice is the seventh option.
        if choice == 7:
            # call the findigns function...
            findings()
        
###########################################################################################################
# END OF SETUP --> WELCOME MESSAGE AND MAIN FUNCTION
###########################################################################################################



# call the main function to run your program  
main()
