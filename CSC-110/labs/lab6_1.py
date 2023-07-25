#Affine Cipher

def relativelyPrime(a, m):
    i = 2
    isit = True
    while(i <= m):
        if(m % i == 0 and a % i == 0):
            return False
            
        i+=1
    return isit

