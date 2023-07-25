
def Prime_Factors(num):
    i = 2
    while(i*i < num):
        while(num % i) == 0:
            num = num / i
        i += 1
    print(num)
    return num
    
Prime_Factors(600851475143)
