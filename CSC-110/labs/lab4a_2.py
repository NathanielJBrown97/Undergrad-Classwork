import math

def fact(num):
    i = num
    n = 1

    while(i > 0):
        n = n * i
        i = i -1
    
    return n

def comb(n, k=2):
    
    NchooseK = (math.comb(n, k))
    
    return NchooseK
