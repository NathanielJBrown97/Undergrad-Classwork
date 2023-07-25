#CHALLENGE PROBLEM SUM OF MULTIPLES (Pulled from First Lab Challenge and turned into a function with reusable variables.)
import math

#a is base, b is first multiple, c is third.
def sumOfMultiples(a, b, c):
    bees = b*math.floor((a - 1)/b)*(math.floor((a - 1)/b)+1)/2
    seas = c*math.floor((a-1)/c)*(math.floor((a-1)/c)+1)/2

    seabees = (b*c)*math.floor((a-1)/(b*c))*(math.floor((a-1)/(b*c))+1)/2

    answer = bees + seas - seabees
    print(answer)
    return answer

sumOfMultiples(1000, 3, 5)