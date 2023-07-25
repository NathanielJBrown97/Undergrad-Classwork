#Nathaniel Brown
#February 14, 2023
#CSC 110
# Homework 4.3
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
#defines second function, with argument num
def sumDivisible(num):
    #defines variable to equal the returned total from sumDigits function.
    value = sumDigits(num)
    #set auth value to false
    auth = False
    #if the original number, mod the output of sumDigits = 0. Then it is divisible.
    if(num % value == 0):
        #and swap auth to True.
        auth = True
    #print and return auth value.
    print(auth)
    return(auth)