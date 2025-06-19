#include "GradeBook.hpp"

#include <iostream>

int
main()
{
    GradeBook gradeBook1("CS101 Introduction to C++ Programming", "Maximus");
    GradeBook gradeBook2("CS102 Data Structures in C++", "Augastus");

    gradeBook1.displayMessage();
    gradeBook2.displayMessage();

    std::cout << "\ngradeBook1 created for course: " 
              << gradeBook1.getCourseName() 
              << "\ngradeBook2 created for course: "
              << gradeBook2.getCourseName()
              << std::endl;
    return 0;
}

