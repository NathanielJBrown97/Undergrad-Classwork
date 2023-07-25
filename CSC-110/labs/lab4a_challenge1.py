def Fibonacci(cap):
    i = 0
    EvenSum = 2
    SecondPos = 1
    CurrentPos = 2
    while(i < cap):
        CurrentPos =  CurrentPos + SecondPos
        SecondPos = CurrentPos - SecondPos
        if(CurrentPos % 2 == 0):
            EvenSum = EvenSum + CurrentPos
        
            if(EvenSum >= 4000000):
                print(EvenSum)
                break
        i+=1
    
    return EvenSum
Fibonacci(50)

