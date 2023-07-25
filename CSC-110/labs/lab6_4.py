#Affine Cipher
alphabet=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'] 
#Affine Cipher


def modInverse(a,m):
    x=1
    modinv = -1
    while(x <= m):
        if ((a*x) % m == 1):
           modinv = x
        x+=1
    return modinv

def unAffine(a,b,m,plaintext ):

    modInv = modInverse(a,m)
    if (modInv == -1):
        ciphertext = ""
    else:
        # initialize ciphertext as blank string
        ciphertext = ""
        # loop through the length of the plaintext
        for i in range(len(plaintext)):         
            # get the ith letter from the plaintext
            letter = plaintext[i] 
            # find the number position of the ith letter
            c = alphabet.index(letter) 
            # find the number position of the cipher by adding the shift 
            cipher_num = (modInv*(c-b)) % m
            # find the cipher letter for the cipher number you computed
            cipher_letter = alphabet[cipher_num] 
            # add the cipher letter to the ciphertext
            ciphertext = ciphertext + cipher_letter 
    
        # return the computed ciphertext
    return ciphertext



print(unAffine(11,6,26,'oqthylqwceiqtu'))
print(unAffine(11,6,26,'rlygmhfyceny'))
print(unAffine(12,6,26,'rlygmhfyceny'))