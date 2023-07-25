#include "gradebook.h"
#include <string>
#include <iostream>
#include <vector>
GradeBook::GradeBook(std::string name) {
    this->studentName = name;
}
// Setter for Projects
void GradeBook::setProject1Grade(double grade){
    this->Project1Grade = grade;
}
void GradeBook::setProject2Grade(double grade){
    this->Project2Grade = grade;
}

// METHODS
void GradeBook::SetStudentName(std::string name){
    this->studentName = name;
}

// double that takes in all grades vectors - calls helper calcAvg function to return averages
double GradeBook::calculateCourseGrade(const std::vector<double> &labGradesVector,
                                       const std::vector<double> &assignmentGradesVector,
                                       const std::vector<double> &projectGradesVector,
                                       const std::vector<double> &examGradesVector
){
    const int assignment_weight = 200;
    const int lab_weight = 200;
    const int exam_weight = 100;
    const int project_weight = 500;
    int totalPoints = 1000;
    double pointsEarned = 0;
    double average = 0;

    if (assignmentGradesVector.empty())
        totalPoints -= assignment_weight;
    else{
        for (double grade : this->assignmentGradesVector){
            pointsEarned += grade;
        }
    }
    if (labGradesVector.empty())
        totalPoints -= lab_weight;
    else{
        for (double grade : this->labGradesVector){
            pointsEarned += grade;
        }
    }
    if (examGradesVector.empty())
        totalPoints -= exam_weight;
    else{
        for (double grade : this->examGradesVector){
            pointsEarned += grade;
        }
    }
    if (projectGradesVector.empty())
        totalPoints -= project_weight;
    else{
        for (double grade : this->projectGradesVector){
            pointsEarned += grade;
        }
    }

    if (totalPoints > 0){
        average = pointsEarned/totalPoints;
        average *= 100;
    }

    return average;
}

// HELPERS

//void function taking reference of specific vector, and individual grade.
//adds grade into the specific vector -- this should be flexible and work for all grades
void GradeBook::addGradeToVector(std::vector<double> &SpecificGradeVector, double grade) {
    SpecificGradeVector.push_back(grade);
}

//double (for precision) helper function, takes specific vector, returns average
double GradeBook::calculateSpecificAverage(std::vector<double> &SpecificGradeVector, int maxGrades, double maxScore){
    double sum = 0;
    double average = 0;

    // for each grade in specific vector
    for(int eachGrade : SpecificGradeVector){
        //add to sum
        sum += eachGrade;
    }
    average = ((sum / maxGrades) / maxScore) * 100;
    return average;
}
//solution to project average
double GradeBook::PROJECTcalculateSpecificAverage(std::vector<double> &SpecificGradeVector, int maxScore, double maxScoreProject1, double maxScoreProject2, double project1Grade, double project2Grade){
    double totalPoints = project1Grade + project2Grade;
    std::cout << totalPoints << std::endl;
    std::cout << project1Grade << " " << project2Grade << std::endl;
    std::cout << maxScore <<std::endl;
    double average = (totalPoints /  maxScore) *100;
    return average;
}
std::string GradeBook::getStudentName() const {
    return this->studentName;
}