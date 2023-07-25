#Nathaniel Brown
#February 14, 2023
#CSC 110
# Homework 4.2
# Python Functions
###################

def sumDigits(num):
    #defines i as zero for loop, an empty list, and converts our int input to a string.
    i = 0
    values = []
    num = str(num)
    #while i is less then the length of the characters of the string.
    while(i < len(num)):
        #append the index value of the character of the string, add 1 to i and repeat until i = the length of string. Ending loop.
        values.append(num[i])
        i+=1
    
    #define a new list in which i is evaluated for each i in the original values list.
    valsasInt = [eval(i) for i in values]
    #i and total = 0 for the while loop and counter.
    i=0
    total = 0
    #while i is less then the length of the string number. Redefine total to equal the total + the current evaluated i value.
    #i.e. this essentially checks the INT value of a the current STR character in valasInt(from values).     Then add 1 to i, to have an end to loop.
    while(i < len(num)):
        total = total + valsasInt[i]
        i+=1
    #print and return totals.
    print(total)
    return total