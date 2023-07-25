#################
#################
# Nathaniel Brown
# CSC 201
# Nov 1, 2022
# Fall 2022
#################
# Assignment 9  #
#################
# Title: Programming with data using lists
#################
#################
# Description:  #
#################
# This program will provide four visualizations with values stoerd
# in a list relating to monkeypox, and the questions created at the
# start of the semester. The values will be stored in lists and
# collected from the internet, or the data set for previous assignments
# The program will additionally be broken down into several functions to 
# copmlete the required tasks of this program. 
# EVERY LINE OF CODE SHOULD BE WITHIN A FUNCTION
#################
#################
# Solution:     #
#################
# First we will import the matplotlib.pyplot as plt, that way we can use the appropriate commands to
# establish appropriate graphs. Secondly we will start define a main function in which the lists of data
# for the charts. Next we will start to define each chart using the parameters of the defined lists in the
# main function. This process will repeat for all four charts. Lastly we will define three functions
# used to calculate the maximum, minimum, and average of an applied list. These functions will then be added,
# within the main function. This way when the main function executes and calls upon each
# chart function; the min, avg, and max ( of the applicable list) will be displayed alongside the 
# visualization itself. The min, avg, and max functions do not need to be called directly in the main function
# as the chart functions will naturally call upon them as well.
#################
#################
#
#
################# PROGRAM START #################
#
# 
import matplotlib.pyplot as plt     # import sub-library for graphs, charts, plots, etc.
#
#
################# SCATTER VISUAL F #################
# This function creates and outputs a scatter chart based on the lists of x
# and y coordinates it recieves as arguments.
################# Scatter Start #################
def scatter_vis(scatx_coords, scaty_coords):       #def scat function, with x/y coords as parameters, defined in main()
    
    plt.scatter(scatx_coords, scaty_coords)        #plots scatter with afforementioned lists.
    
    plt.title("Confirmed Cases by Traveler Patients")      #Sets Scat Title
    plt.xlabel("Number of Traveler Patients")              #Sets x axis label
    plt.ylabel("Confirmed Cases")                          #Sets y axis label
    
    plt.xticks(scatx_coords)                       #plots ticks with x coords def in main() Below does same, but adds string replacement.
    plt.yticks(scaty_coords , ['Brazil' , 'France' , 'Germany' , 'England' , 'Italy' , 'Argentina' , 'Denmark' , 'Bolivia'])
    
    plt.show()                                             #Shows plot
################# LINE VISUAL F #################
# This function creates and outputs a line chart based on the lists of x and y
# coordinates it receives as arguments.
################# Line Start #################
def line_vis(linex_coords , liney_coords):         #def line func using x/y line coord lists as parameters defined in main()

    plt.title('United States Monthly Confirmed Cases')  #plots line title
    plt.plot(linex_coords, liney_coords)           #plots line with afforementioned list
    plt.show()                                     #shows line
    
################# BAR VISUAL F #################
# This function creates and outputs a bar chart based on the lists of x-coords
# of each bar's left edge and heights of each bar along the y-axis it recieves
# as arguments.
################# Bar Start #################
def bar_vis(left_edges, heights):                 #def bar func using lists as parameters that are def in main()

    plt.bar(left_edges, heights, color = {'r' , 'g' , 'b'})   # plots bar using afforementioned list and sets color of bars
    
    plt.title('Total Monkeypox by Continent')                 #Sets bar title
    plt.xlabel(' Continent ')                                 #sets x label
    plt.ylabel(' Confirmed Cases ')                           # sets y label

    plt.show()                                                #shows bar
################# PIE VISUAL F #################
# This function creates and outputs a pie chart based on the lists of values and
# slice labels it receives as an argument. 
################# PIE Start #################
def pie_vis(casesbycountry , slice_labels):       #def pie func using lists as parameters that are defined in main()
    plt.pie(casesbycountry, labels = slice_labels, colors = {'b' , 'r' , 'm' , 'g' , 'k'})  #plots pie with aforementioned lists, sets colors.
    plt.title('Cases by Country')            # sets plot title
    
    plt.show()                               # show plot
################# MINIMUM VAL #################
# This function fidns the minimum value in a list that it receives as an argument.
################# Min Calc Start #################
def find_min(some_list):       #def func to detect minimum
    first = some_list[0]      # sets variable to equal first pos in a passed list
    
    for i in some_list:       # for each i in afforementioned list
        if i < first:         # if less than defined variable
            first = i         # redefine varible to = the index that met the if check
    return first              # return variable value for reuse and print functionality
    
################# MAXIMUM VAL #################
# This function fidns the maxium value in a list that it receives as an argument.
################# Max Calc Start #################
def find_max(some_list):         #def function to detect max of passed list
    first = some_list[0]         #sets variable to equal first pos in afformentioned list
    
    for i in some_list :         #for each index in afformentioned list
        if i > first:            #if index is greater than variable
            first = i            #redefine variable to equal the index
    return first                 # return variable for reuse and print functionality
################# Average Val #################
# This function finds the average value of a list that it receives as an argument.
################# Avg Calc Start #################
def find_avg(some_list):       #def function to detect average
    average = 0                # sets a variable to equal 0
    for i in (some_list):      # for each index within a passed list
        average = sum(some_list) / len(some_list)       #calculate sum of afformentioned list, divided by the length of afforementioned list pos.
    return average             # return variable for reuse and print functionality
#
#
#
################# MAIN FUNCTION #################
# This function setups the program and manages calls to functions defined for
# creating the visualization and computing simple calculations
#
################# Main Start #################
def main():                                 #def main function to call all of afforelisted functions.
#The List-List of Variables  - passed to respective functions as per requirements of assignement.
#Scatter
    scatx_coords = [20 , 2 , 19 ,  2 , 19 , 11 , 3 , 2]
    scaty_coords = [6246 , 3824 , 3547 , 3383 , 813 , 221 , 183 , 125]
#Line
    linex_coords = ['May', 'June', 'July', 'August', 'September']
    liney_coords = [21, 408, 4057, 10338, 3129]
#Bar
    left_edges = [ 'NA' ,'SA'  , 'EU']
    heights = [ 25269 , 10501 , 23627 ]
#Pie
    casesbycountry = [28377 , 3689 , 9813 , 3662, 4092]
    slice_labels = ['United States' , 'United Kingdoms' , 'Brazil' , 'Germany' , 'France']
#Max/Min/Avg Variables   - all used for print statements later in the main() to display info required for assignment.
#    
    mini = "The minimum value is... "  # strings so i dont have to type
    maxi = "The maximum value is... "  #     ^   ^
    avg = "The average value is... "   #    ________
#
    scatmax = find_max(scaty_coords)
    scatmin = find_min(scaty_coords)
    scatavg = find_avg(scaty_coords)
    linemax = find_max(liney_coords)
    linemin = find_min(liney_coords)
    lineavg = find_avg(liney_coords)
    barmax = find_max(heights)
    barmin = find_min(heights)
    baravg = find_avg(heights)
    piemax = find_max(casesbycountry)
    piemin = find_min(casesbycountry)
    pieavg = find_avg(casesbycountry)
#
#### Call Chart functions ####
## Max / Min / Avg Functions after ##
    scatter_vis(scatx_coords, scaty_coords)      # calls scatter visual to print
    print(maxi , scatmax)                        # prints max, min, avg.
    print(mini , scatmin)
    print(avg , scatavg)
    line_vis(linex_coords , liney_coords)        # calls line visual to print
    print(maxi , linemax)                        # prints max, min, avg
    print(mini , linemin)
    print(avg , lineavg)
    bar_vis(left_edges , heights)                #calls bar visual to print
    print(maxi , barmax)                         # prints max, min, avg
    print(mini , barmin)
    print(avg , baravg)
    pie_vis(casesbycountry , slice_labels)       # calls pie visual to print
    print(maxi , piemax)                         # prints max, min, avg
    print(mini , piemin)
    print(avg , pieavg)
main()                                   # initiates the main function, starting the program.
