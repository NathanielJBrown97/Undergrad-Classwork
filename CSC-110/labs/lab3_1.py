#Nathaniel Brown, Kai 
#CSC 110
#Lab 2 Algorithms using Lists
#####
# Three List Values # 
safeList = []
warningList = []
dangerList = []
vibList = []
# Get Sensor Values, until type -1
vibrationVal= 0
while (vibrationVal != -1):
    vibrationVal = float(input("Enter vibration value (-1 to quit): "))
    if(vibrationVal != -1):
        vibList.append(vibrationVal)
# Define Thresholds
warning = float(input("Enter threshold for warning values: "))
danger = float(input("Enter threshold for danger values: "))

i = 0 
lenvibList = len(vibList)

while(i < lenvibList):
    if(vibList[i] > danger):
        dangerList.append(vibList[i])
    elif(vibList[i] < warning):
        safeList.append(vibList[i])
    else:
        warningList.append(vibList[i])
    i += 1
# prints for gradescope
print("There are " , len(safeList) , " safe readings: ")
print(safeList)
print("There are " , len(warningList) , " warning readings: ")
print(warningList)
print("There are " , len(dangerList) , " danger readings: ")
print(dangerList)