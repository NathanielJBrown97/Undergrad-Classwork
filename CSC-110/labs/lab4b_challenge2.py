#euler problem 34

def fact(num):
    #if 0! return 1
    if num == 0:
        return 1
    else:
        return num * fact(num-1)

def reallyamazingfunctionname():
    #sum counter
    sumofallNEATnums = 0
    #While iterator is in range of 3 --> 100000 (1 and 2 dont count)
    for i in range(3, 100000):
        #value for the value of current factorial
        actualValue = 0
        #for each individual number in the current iteration (i.e. position)
        for individualNumber in str(i):
            #update actual value of factorial to be the fact() return value, of each individual digit.
            #which essentially runs the normal factorial formula... just slower for the sake of this problem.
            actualValue += fact(int(individualNumber))
        #if that actualValue of the factorial = the iteration number then it satisfies 
        # the objective of this reallyamazingfunction
        if actualValue == i:
            #update sum of the NEAT numbers
            sumofallNEATnums = sumofallNEATnums + i
        #return
    return sumofallNEATnums
    
def main():
    print(reallyamazingfunctionname())

main()