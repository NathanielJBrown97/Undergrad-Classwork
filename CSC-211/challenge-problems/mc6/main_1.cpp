#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

int main()
{
    // var for number of requests and takes value
    int num_student_course_requests;
    std::cin >> num_student_course_requests;

    // unordered map rather than vector; to associate students with each course.
    std::unordered_map<std::string, std::set<std::string>> courses;

    // iterate through each student course request.
    for (int cur_student_course_request = 0; cur_student_course_request < num_student_course_requests; cur_student_course_request++)
    {
        // strings for data: first,last names, and course name -- take their input
        std::string first, last, course;
        std::cin >> first >> last >> course;
        // string for their full name.
        std::string name = first + " " + last;

        // check if course already exists in map
        if (courses.find(course) == courses.end())
        {
            // if not, add it to map
            courses[course] = std::set<std::string>();
        }

        // add student to set of students taking specific course.
        courses[course].insert(name);
    }

    // sort courses in lexicographic order
    std::set<std::string> sorted_courses;
    for (auto &c : courses)
    {
        sorted_courses.insert(c.first);
    }

    // output number of students for each course
    for (auto &c : sorted_courses)
    {
        std::cout << c << " " << courses[c].size() << std::endl;
    }
}
