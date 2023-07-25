#include <iostream>
#include <iomanip>
#include <vector>

int main() {
//DEBUGGING LINE std::cout << "Enter number of cases: " << std::endl;
    //declare variable and take input for the num of cases
    int numberofCASES; std::cin >> numberofCASES;
    //for loop, i < number of cases we will increase iteration
    for (int i = 0; i < numberofCASES; i++) {
//DEBUGGING LINE std::cout << "Enter number of students: " << std::endl;
        //declare variable and take input for the num of students
        int numberofSTUDENTS; std::cin >> numberofSTUDENTS;
        //create vector of float to store grades of each student iteration. The size of this vector is set to the current number of students.
        std::vector<double> grades(numberofSTUDENTS);
        //store sum value for later calculation
        double sum = 0;
        //for loop, j < num of students, increase iteration
        for (int j = 0; j < numberofSTUDENTS; j++) {
//DEBUGGING LINE std::cout << "Enter grade: " << std::endl;
            //input current iteration of grade value to the vector.
            std::cin >> grades[j];
            //increment sum value by the current value of vector iteration.
            sum += grades[j];
        }
        //float variable for the average of sum / num of students.
        double avg = sum / numberofSTUDENTS;
        //set counter for next for loop.
        double count = 0;
        //for loop, j < num of students, increase iteration
        for (int j = 0; j < numberofSTUDENTS; j++) {
            //if the grade iteration is > the average, add 1 to count val.
            if (grades[j] > avg) {
                count++;
            }
        }
        //define percentage for print (count divided by the num of students) multiplied by 100.
        double percentABOVEavg = (count / numberofSTUDENTS) * 100;
        //print the output needed set to precision of 3 for decimals.
        std::cout << std::fixed << std::setprecision(3) << percentABOVEavg << "%" << std::endl;
    }

    return 0;
}