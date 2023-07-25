#Nathaniel Brown
#CSC 110
#4/3/2023
#Homework 8 - Digital Forensics 
###############################
###############################
def fletcher32(text_phrase):
    #define aList as a fucntion call as per requirements, passed our phrase.
    aList = strOrdList(text_phrase)
    #define bList as a function call as per requirements, passed aList
    bList = bSum(aList)
    #variables for our sum counter
    bList_sum = 0
    #for each number in bList, add to sum
    for number in bList:
        bList_sum = bList_sum + number

    # bitwise operations on sum of bList for gradescope
    checksum = (bList_sum << 16) | max(bList)
    print(checksum)
    return checksum

def strOrdList(text_phrase):
    #empty list to fill and return.
    aList =[]

    # for each character in text, append the ord( of each character)
    for char in text_phrase:
        aList.append(ord(char))

    #return aList
    return aList

def bSum(aList):
    #empty list to fill and return.
    bList =[0]

    # for each value in aList, append sum of aList + all values prior to it mod 65536
    for value in range(1,len(aList)+1):
        bList.append((bList[value-1] + aList[value-1]) % 65536)

    # return bList
    return bList
