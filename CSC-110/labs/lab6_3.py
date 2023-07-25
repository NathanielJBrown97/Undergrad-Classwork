#modular inverse of int

def modInverse(a,m):
    x=1
    modinv = -1
    while(x <= m):
        if ((a*x) % m == 1):
           modinv = x
        x+=1
    return modinv
       
