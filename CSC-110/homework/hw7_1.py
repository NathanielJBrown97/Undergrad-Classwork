#Nathaniel Brown
#CSC 110
#Homeowrk 7.1
#March 29/23
#################
def caesarPlus(plaintext, shift):
    #empty string to build our encrypted return
    ciphertext = ''
    #iterate through each character and its corresponding index in the plaintext variable
    for i, c in enumerate(plaintext):
        #calculate the shifted index by subtracting the ascii value of a, from the current character's ascii value.
        #then adding shift value passed to the function and the current index(or iteration). Mod by 26 to make sure it stays within
        #range of the alphabet. 
        shifted_index = (ord(c) - ord('a') + shift + i) % 26
        #take the shifted_index established above: convert back to a character by adding the ascii value of A.
        #converts the shifted index back into a letter of the alphabet
        shifted_char = chr(shifted_index + ord('a'))
        #at the end of every iteration add the finalized shfited_char to the return string.
        ciphertext += shifted_char
    #return the output
    return ciphertext

def uncaesarPlus(ciphertext, shift):
    #empty string to build our decrypted return
    plaintext = ''
    #iterate through the characters of the cipher text passed to the function.
    for i, c in enumerate(ciphertext):
        #same as previous function; but in reverse. -a, -shift - i mod 26. 
        unshifted_index = (ord(c) - ord('a') - shift - i) % 26
        #you still need to add the ascii value of a at the end to convert it back into a character
        unshifted_char = chr(unshifted_index + ord('a'))
        #add this unshifted character to the plaintext return.
        plaintext += unshifted_char
    #return the output
    return plaintext