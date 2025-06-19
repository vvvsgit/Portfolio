#include "GradeBook.hpp"

#include <iostream>

GradeBook::GradeBook(std::string courseName, std::string instructorName)
{
    setCourseName(courseName);
    setInstructorName(instructorName);
}

void
GradeBook::setCourseName(std::string name)
{
    courseName_ = name;
}

void
GradeBook::setInstructorName(std::string name)
{
    instructorName_ = name;
}

std::string
GradeBook::getCourseName()
{
    return courseName_;
}

std::string
GradeBook::getInstructorName()
{
    return instructorName_;
}

void
GradeBook::displayMessage()
{
    std::cout << "\nWelcome to the grade book for\n" << getCourseName() << '!' << std::endl;
    std::cout << "This course is presented by: " << getInstructorName() << std::endl;
}

