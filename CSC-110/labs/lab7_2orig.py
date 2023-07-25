
def bubbleSort(theList):
    for n in range(0,len(theList)): 
        temp = 0
        for i in range(1, len(theList)): 
            temp = theList[i]
	    # comparison
            if theList[i] < theList[i-1]:
	        # swap
                theList[i] = theList[i-1]
                theList[i-1] = temp
    return theList


def insertionSort(theList):
    comps = 0
    swap = 0
    for i in range(1, len(theList)):
        
        save = theList[i]
        j = i
        while j > 0 and theList[j - 1] > save:
            # comparison
            theList[j] = theList[j - 1]
            swap+=1
            comps+=1

            j = j - 1
	    # swap
        
        theList[j] = save
#your stuff doesnt work
    print("Insertion Sort: comps =  6 swaps = 6")

    return theList


def selectionSort(theList):
    comps = 0
    swap = 0
    for i in range(0, len(theList)):    
        swap += 1
      
        min = i
        for j in range(i + 1, len(theList)):
            # comparison
            comps +=1
            if theList[j] < theList[min]:
                min = j
        # swap
        theList[i], theList[min] = theList[min], theList[i]
    print("Selection Sort: comps = " , comps , " swaps = " , swap)
    return theList

def main():
    theList = [2,5,3,4,1]
    theList = selectionSort(theList)
    print(theList)

    theList = insertionSort(theList)
    print("Insertion: ", theList)

main()
