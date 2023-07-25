#Affine Cipher
alphabet=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'] 

def relativelyPrime(a, m):
    i = 2
    isit = True
    while(i <= m):
        if(m % i == 0 and a % i == 0):
            return False
            
        i+=1
    return isit

def affine(a,b,m,plaintext):     
    isit = relativelyPrime(a,m)
    if isit == False:
        ciphertext = ""
    else:    
        # initialize ciphertext as blank string
        ciphertext = ""
        # loop through the length of the plaintext
        for i in range(len(plaintext)):         
            # get the ith letter from the plaintext
            letter = plaintext[i] 
            # find the number position of the ith letter
            num_in_alphabet = alphabet.index(letter) 
            # find the number position of the cipher by adding the shift 
            cipher_num = (a*num_in_alphabet + b) % m
            # find the cipher letter for the cipher number you computed
            cipher_letter = alphabet[cipher_num] 
            # add the cipher letter to the ciphertext
            ciphertext = ciphertext + cipher_letter 
    
        # return the computed ciphertext
    return ciphertext


