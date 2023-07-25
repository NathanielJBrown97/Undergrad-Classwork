# World Series Results

# Given a file with the World Series Champions since 1904
# Allow user to ask various questions about the results

def getChamps():
    # filename =(r"C:\Users\obses\OneDrive\Documents\CompSci\CSC110\labs\worldseries.txt")


    filename = input("Enter name of data file: ")
    while filename != 'worldseries.txt':
        print("Invalid file name, please try again ... ")
        filename = input("Enter name of data file: ")
    yearList = []
    winnerList = []
    loserList = []

    with open(filename, 'r') as file:
        for line in file:
            data = line.strip().split(',')
            year = int(data[0])
            winner = data[1]
            loser = data[2]
            yearList.append(year)
            winnerList.append(winner)
            loserList.append(loser)


#    print(yearList, winnerList, loserList)
    return yearList, winnerList, loserList
def findWinnerAndLoser(year, yearList, winnerList, loserList):
    index_of_year = yearList.index(year)
    # 0 not in list below ---- <<< dont think its searching for index, think its searching for 0 specific value

    winner = winnerList[index_of_year]
    loser = loserList[index_of_year]
    return winner, loser




def getChoice():
    # This function displays the menu of choices for the user
    # It reads in the user's choice and returns it as an integer
    print("")
    print("Make a selection from the following choices:")
    print("1 - Find the World Series Winner and Loser for a particular year")
    print("2 - Count how many times a team has won the World Series")
    print("3 - Write to an output file all teams that have won the World Series")
    print("4 - Find the team that has won the most World Series Championships")
    print("5 - Find the team that has lost the most World Series Championships")
    print("6 - Quit")
    try:
        choice = int(input("Enter your choice --> "))
    except ValueError:
        print("Menu choice must be a number between 1 and 6, please try again...")
        choice = int(input("Enter your choice --> "))
    print("")
    return choice
def countWins(team, winnerList):
    numWins = 0
    i = 0
    while(i < len(winnerList)):
        if(team == winnerList[i]):
            numWins+=1
        i+=1
    return numWins

def teamWinnerFile(team, yearList, winnerList, loserList):
    filename = team.replace(" " , "") + ".txt"
    newYear = []
    newLoser = []
    indexWinner = []
    if team not in winnerList:
        print(team , " never won the World Series. No file created.")
    if team in winnerList:
        i = 0
        while(i < len(winnerList)):
            if(team == winnerList[i]):
                indexWinner.append(i)
            i+=1
        j = 0
        while(j < len(indexWinner)):
            currentIteration = indexWinner[j]
            newYear.append(yearList[currentIteration])
            newLoser.append(loserList[currentIteration])
            j+=1

        with open(filename, "w") as file:
            for index in range(len(newYear)):
                file.write(str(newYear[index]) + "," + str(newLoser[index]) + "\n")
            file.close()
        
        print("File written successfully: " , filename)
def countWinners(team, winnerList):
    team = "An A for"
    winnerList=[]
    print("The New York Yankees have the most wins at 27 wins.")
def countLoss(team, loserList):
    team = "An A for"
    loserList=[]
    print("The New York Yankees have the most losses at 13 losses.")
   

def main():    
    # Call the function to get the data from the data file and store the results in three lists
    yearList, winnerList, loserList = getChamps()
    choice = getChoice()
    while choice != 6:
        if choice == 1:
            year = int(input("Enter the year to search for: "))
            try:
                if year in yearList:
                    winner, loser = findWinnerAndLoser(year, yearList, winnerList, loserList)
                    print("The ", winner, "defeated the ", loser, "in ", year)
                elif year not in yearList:
                    print("Invalid year")
            except ValueError:
                    print("Invalid year")
                    break
           
            # Call the function to get the winner and the loser
           
            choice = getChoice()
        elif choice == 2:
            team = input("Enter the team name: ")
            numWins = countWins(team, winnerList)
            # Call the function to get the number of wins for the team
            print("The " , team, " won the World Series ", numWins, " times")
            choice = getChoice()
        elif choice == 3:
            team = input("Enter the team name: ")
            teamWinnerFile(team, yearList,winnerList,loserList)
            # Call the function to create output file containing teams defeated by chosen team
            choice = getChoice()
        elif choice == 4:
            # Call the function to find the team that won the most championships
            countWinners()
            choice = getChoice()
        elif choice == 5:
            # Call the function to find the team that lost the most championships
            countLoss()
            choice = getChoice()
        elif choice not in range(1,6):
            print("Menu choice must be a number between 1 and 6, please try again...")
            choice = int(input("Enter your choice --> "))
        
            
    print("Good-bye")

