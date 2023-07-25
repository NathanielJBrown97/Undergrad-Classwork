#Nathaniel Brown
#Homework 3.2
#February 7, 2023
#CSC 110
###
### Problem 2
playerAge = [] #empty list that will be filled by while loop.
totalPlayer = int(input("How many ages have been collected? ")) #value to identify how many ages to collect
i = 0 #basic counter starting at 0
while i < totalPlayer:  # while counter is < the amount of ages we want to colelct, run loop
    playerAge.append(int(input("Enter age: "))) #append empty list with input of age
    i += 1 #adds one to the counter, runs until it hits the desired amount set by totalPlayer

print("The sampled list is:\n\n" , playerAge[0::3]) #print the text required, and the list filtered to every third position.

