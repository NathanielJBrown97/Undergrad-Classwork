#Nathaniel Brown
#November 17, 2022
#CSC 201 Fall 22'
#Assignment 11: Programming with Pandas DataFrame
#Title: Pandas Dataframe
###
#Description: This assignment's goal is to use our csv file from the previous week; read and translate the
#csv file into a data frame. Where we will filter the information out, create a subset and from there
# we will run some computations and output our new subset dataframe and statistics.
###
#Solution: The best way to handle this assignment is by first creating a function to read the csv file.
# and translate it into a whole dataframe. From there the whole dataframe can be passed to a fucntion
#that will filter the data to select a specific subset of data. That can then be passed to a computation function
# which will allow us to run specific calculations such as a median calculation. which can finally be passed to a 
# output function which will print both our subset and statistics on said subset. (Of course, all bundled in a main function).
###
##### IMPORTS and Outer Variables#####
import pandas as pd                 # imports pandas for high performance containers with data structures
import csv
##############################
##### READ AS DATAFRAME #####
# this function sets up the program and manages calls to functions defined for specified processing, 
# calculations and output
# Arguments - 1 
# Returns - 1
def read_as_dataframe(masterfile):    #defines function to read csv file and make dataframe for use throughout the assignment. Pushes masterfile for csv reading.
    og = pd.read_csv(masterfile)      #this is the original panda dataframe variable; however, due to some issues with integers being read as strings...
    df = og.astype({"Age":"int"})     #this dataframe variable is used throughout the assignment. And converts Age to an integer for usage in the compute function.
    return df                         #returns df variable, for usage later in the main()

##############################
##### GET SUBSET #####
# This function creates a filtered subset of the Pandas Dataframe
# Arguments - 1 Pandas DataFrame containing data from csv file
# return - 1 subset of hte pandas dataframe
def get_subset(whole):               #this function is used to get a subset of the data using the passed dataframe defined "whole" in the main function
    country_filter = whole['Opinion: Most Infected'] == "China"    #Creates a filter based on the Opinion column on which country people thought had the most cases of monkeypox. 
    china_sub = whole[country_filter]           #Takes the established filter and assigns it a variable name
    
    return china_sub                            #returns said variable for future use in the main function.
##############################
##### COMPUTE #####
# This function computes ONE data statistic on the filtered subset of the Pandas DataFrame
# Arguments - 1 Filtered subset of the Pandas Dataframe and 1 string representing the column name
# in the DataFrame you want to compute the data statistic on
# Return - 1 Computed data statistic on the given column name in the filtered subset of the pandas dataframe
def compute(china_subset):                      #defines a computation function using the passed variable china_subset, which was defiend in the get_subset and main functions.
    median = china_subset['Age'].median()       #runs a median calculation on the Age responess of responses that met china_subset critera.
    return median                               #returns median variable for future use in the main()
##############################
##### OUTPUT STATS #####
# This function outputs the filtered subset and the calculated data statistic on the subset.
# ARguments - 1 Filtered subset of the dataframe and the calculated data statistic on the subset
# Returns - None
def output_stats(china_subset , median_stats):  #defines a function to output both the computation and subset dataframes using their respective variables defiend in the main()
    print(china_subset)   #prints the subset dataframe containing just those who responded with 'China' for their opinion origination responess.
    print("The median age of those that believe China is the most infected with Monkeypox is: " , median_stats) #a print statement that tells the user the median age of afforementioned participants.
##############################
##### MAIN FUNCTION #####
# This function setups the program and manages call functions defined for specified processing,
# calculations, visualizations and output.
def main():            #defines main function used to execute the entire program.
    masterfile = "dataframes.csv"      #variable name of csv file used throughout.
    whole = read_as_dataframe(masterfile) #dataframe variable name, equating to the read_as() with passed parameter of the csv file variable.
    china_subset = get_subset(whole)    #china exlcusive subset variable name, equating to the get_subset function with the passed afforementioned 'whole' dataframe.
    median_stats = compute(china_subset) #median computation variable name, equating to the compute function with the china subset used as a passed parameter.
    output_stats(china_subset , median_stats) #essentially hte print function; printing both the filtered subset and the median statistics created in the previous chain of functoins. (uses both the median and subset variables as parameteres.)
main()      # as mentioned above runs the main function, essentially starting the program.
