#project euler 6
def sumSquare(num):
    # sum of the square of each iteration from a range of 1 --> given num val
    sum = 0
    for i in range(1, num+1):
        sum+= i*i
    return sum
def squareSum(num):
    # sum of numbers from a range of 1 ---> given num val, then square the value in return.
    sum = 0
    for i in range(1, num+1):
        sum+= i
    return sum*sum

def main():
    #prints the difference of the two functions
    print(squareSum(100) - sumSquare(100))

main()