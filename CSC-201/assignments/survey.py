# Nathaniel Brown
# CSC 201
# Assignment 6
# Fall 22'   October 13, 2022
#
#
#
# [Working Title] 
# Description:
# Design a program that will ask users to respond to the same questions in the
# google form survey that we asked in an earlier assignment. 
#
# Solution:
# Similiar to our lab this week; we will be establishing variables that are
# dependant upon the users responses to the variable-linked prompts. Additionally,
# we want to avoid invalid data, so we add conditional statements to our variables.
# Forcing the user to reanswer the question in a format that meets conditions for
# our variables.
#   --------              ------------
#   -------- Script Start ------------
#   --------              ------------
###    Date Time Import Requirement   ### 
from datetime import datetime
now = datetime.now()
### Timestamp for Later               ###
ts = datetime.timestamp(now)
###  Current date time                ###      
current_year = now.year
current_month = now.month
current_day = now.day   
###
# -----------------------------------   #
###                                   ###
#           QUESTION 1 - AGE            #
###                                   ###
# ---------------------------------------
#define variable of boolean type to track if rules are violated
#set to be true if any rules above are violated, then
valid = True
#
# ask user for age as an input
q1 = input("Enter your age:")
#
# Saves timestamp for later report #
q1t = datetime.now()
#
#check if the user's input is less than 2 characters long
#if true, reassign variable of boolean type to state that
#has been violated
if(len(q1) < 2):
    valid = False
#
#define variable for the first two characters of the user's input
#this should represent the user's age that was entered
age = q1 [0:2]
#
#check if any characters in age are not digits
#if true, then reassign variable of boolean type to state that rules have been violated
if age.isdigit() == False:
    valid = False
#
#check if user's input is more than two characters long and if the character is
#a digit (i.e. something like 917) if true, reassign variable of boolean type to state 
#that it has been violated
if(len(q1) > 2) and q1[2].isdigit():
    valid = False
#
#if variable of boolean type determines that no rules were violated then print
#the cleaned data value. if otherwise print that it is invalid
if (valid):
    print("The age value is" + age + ".")
else:
    print("The age is invalid. Please use integers. Plausible age only.")
    valid = False
###
#
#
#
###                                   ###
#       QUESTION 2 - Familiarity        #
#              Linear Scale             #
###                                   ###
# ------------------------------------  #
#establishes variable for 2nd question that requires input
q2 = input("Please enter 1, 2, or 3. Where 1 is unfamiliar, and 3 is familiar.")
# Saves timestamp for later report #
q2t = datetime.now()
#if the above variable is a digit between 1 and 3 (including) then it will mark then it will accept the answer. 
#Otherwise it will inform you of an invalid response and change the valid value to false.
if(q2.isdigit() == True):
        q2 = int(q2)
        if(q2 >= 1 and q2 <= 3):
            print("Your choice is valid. Thank you.")
        else:
            print("Was that 1, 2, or 3? Seriously. Read the prompt.")
else:
    print("Doesn't only contain digits. Read the question. Input 1, 2, or 3.")
    valid = False
#
###                                   ###
#       QUESTION 3 - Symptoms Q1        #
#              Multiple Choice          #
###                                   ###
# ------------------------------------  #
# variable for 3rd question established with input of response to question listed.
q3 = input("""What are the symptoms of Monkeypox?
Please type in your letter choice from the list. JUST THE LETTER.
A: Brain Lesions
B: Dementia
C: Respitory Complicatoins and Flu-Like Symptoms
D: Swollen Lymph Nodes, Flue-Like Symptoms, and a rash that forms blisters. """)
# Saves timestamp for later report #
q3t = datetime.now()
#sets answer to lowercase to better identify if response is valid.
q3 = q3.lower()
#if the user input is one of the below options, marked as valid and will print the result.
if(q3 == "a") or (q3 == "b") or (q3 == "c") or (q3 == "d"):
    print(q3)
#otherwise the program will remind you of the rules and switch the valid variable to false.
else:
    print("My man. Holy moly. Not valid. Just the letter of your choice.")
    valid = False
#
###                                   ###
#       QUESTION 4 - Country Cases Q3   #
#             Multiple Choice           #
###                                   ###
# ------------------------------------  #
# variable for 4th question established with input of response to question listed.
q4 = input("""What country do you think has the most cases of Monkeypox?
Please type in your letter choice from the list. JUST THE LETTER.
A: United States
B: China
C: India
D: Russia
E: United Kingdoms
F: Other""")
# Saves timestamp for later report #
q4t = datetime.now()
#sets answer to lowercase to better identify if response is valid.
q4 = q4.lower()
#if the user input is one of the below options, marked as valid and will print the results.
if(q4 == "a") or (q4 == "b") or (q4 == "c") or (q4 == "d") or (q4 == "e") or (q4 == "f"):
    print(q4)
#otherwise the program will remind you of the rules and switch the valid variable to false.
else:
    print("My man. Holy moly. Not valid. Just the letter of your choice.")
    valid = False
#
###                                   ###
#       QUESTION 5    Family/Friends    #
#             Yes or not                #
###                                   ###
# ------------------------------------  #
#variable for the 5th established with the input of response to question listed below
q5 = input("Do you know anyone (friends or family), who have been diagnosed with Monkeypox?")
# Saves timestamp for later report #
q5t = datetime.now()
#sets answer to lowercase to better identify if response is valid.
q5 = q5.lower()
#if the answer is either yes or no, marked as correct and will print the answer typed.
if(q5 == "yes") or (q5 == "no"):
    print(q5)
#otherwise the program will remind you the rules and switch the valid variable to false.
else:
    print("My man. Holy moly. Not valid. Type exactly 'yes' or 'no'. It's not that complicated.")
    valid = False
#
###                                   ###
#       QUESTION 6 - Concern            #
#             Yes or no response        #
###                                   ###
# ------------------------------------  #
#variable for 6th question is established with input of response to question listed below
q6 = input("""Are you concerned about Monkeypox?
Type either yes, or no.""")
# Saves timestamp for later report #
q6t = datetime.now()
#sets answer to lowercase to better identify if response is valid.
q6 = q6.lower()
#if the answer is either yes or no, marked as correct and will print the answer typed.
if(q6 == "yes") or (q6 == "no"):
    print(q6)
#otherwise the program will inform you the rules and switch the valid variable to false.
else:
    print("My man. Holy moly. Not valid. Type exactly 'yes' or 'no'. It's not that complicated.")
    valid = False
#
#
#       None Conditional Responses        #
# Question 7                              #
### ---===== READ THIS PLEASE ====----  ###
###  ---===== READ THIS PLEASE ====---- ###
###  ---===== READ THIS PLEASE ====---- ###
# please dont dock points
# this question was open ended and can not be parsed with conditional statements to ensure validity (At least not at this level yet).
#
#
# Sets variable for the 7th question of the survey and prints
q7 = input("What do you believe contributes to the spread of contagious viruses like monkeypox?")
# Saves timestamp for later report #
q7t = datetime.now()
print(q7)
#
#
#
## ----------- End Questionarre Section -------------- ##
##
##
##
## ------------- Start Output of Responses -----------##

### If/else to print survey results w/ timestamps or direct you to retake the survey again.###
if(valid==True):
 ### output survey title / description ###
    print("""The Monkeypox Original Data Survey
Description: A series of questions to collect your age, familiarity level, and general knowledge of monkeypox, as well as a short opinion, and direct impact on your life.""")
#if true it will print the survey data with responses and time stamps, line broke for ease of reading.
#calls q1-7 variables to post response, and q1t-q7t to post timestamps of questions
    print("Below is your survey results:" , " \nQuestion 1:" , q1 , ". Submitted at: ", q1t , " \nQuestion 2:" , q2 , ". Submitted at:", q2t , "\nQuestion 3:" , q3 , ". Submitted at: ", q3t , " \nQuestion 4:" , q4 , ". Submitted at: ", q4t , " \nQuestion 5:" , q5 , ". Submitted at: ", q5t , " \nQuestion 6:" , q6 , ". Submitted at: ", q6t , " \nQuestion 7:" , q7 , ". Submitted at: " , q7t)
#otherwise if any answers were flagged as invalid, then the program will instead tell you didn't answer all questions right and prompt you to fill it out again.
else:
    print("You didn't answer a question correctly; please run the script again.")         
