#nathaniel brown
#CSC 110
#Homework 7.2
#March 29/23
#######################
def polyCaesar(plaintext, keyword, shift):
    #empty string to build our encrypted return
    ciphertext = ''
    #iterate through each character and its corresponding index in the plaintext variable
    for i, c in enumerate(plaintext):
        #index of current keyword character acii value - a. This will be used instead of generic iteration value. In next line
        keyword_shift = ord(keyword[i % len(keyword)]) - ord('a')
        #calculate the shifted index by subtracting the ascii value of a, from the current character's ascii value.
        #then adding shift value passed to the function and the keyword_shift value defiend above. Mod by 26 to make sure it stays within
        #range of the alphabet. 
        shifted_index = (ord(c) - ord('a') + keyword_shift + shift) % 26
        #converts the shifted index back into a letter of the alphabet
        shifted_char = chr(shifted_index + ord('a'))
        #at the end of every iteration add the finalized shifted_char to the return string.
        ciphertext += shifted_char
    #return the output
    return ciphertext

def unPolyCaesar(ciphertext, keyword, shift):
    #empty string to build our decrypted return
    plaintext = ''
    #iterate through the characters of the cipher text passed to the function.
    for i, c in enumerate(ciphertext):
        #index of current keyword character acii value - a. This will be used instead of generic iteration value. In next line
        keyword_shift = ord(keyword[i % len(keyword)]) - ord('a')
        #calculate the shifted index by subtracting the ascii value of a, from the current character's ascii value.
        #then subtracting shift value passed to the function and the keyword_shift value defiend above. Mod by 26 to make sure it stays within
        #range of the alphabet. 
        unshifted_index = (ord(c) - ord('a') - keyword_shift - shift) % 26
        #you still need to add the ascii value of a at the end to convert it back into a character
        unshifted_char = chr(unshifted_index + ord('a'))
        #add the unshifted character iteration into the plaintext string.
        plaintext += unshifted_char
    #return the output
    return plaintext
