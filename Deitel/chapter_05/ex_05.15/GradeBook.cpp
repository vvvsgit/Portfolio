#include "GradeBook.hpp"

#include <iostream>

GradeBook::GradeBook(std::string name)
{
    setCourseName(name);
    aCount_ = 0;
    bCount_ = 0;
    cCount_ = 0;
    dCount_ = 0;
    fCount_ = 0;
}

void
GradeBook::setCourseName(std::string name)
{
    if (name.length() <= 25) {
        courseName_ = name;
    } else {
        courseName_ = name.substr(0, 25);
        std::cout << "Name \"" << name << "\" exceeds maximum length (25).\n" << "Limiting courseName to first 25 characters.\n" << std::endl;
    }
}

std::string
GradeBook::getCourseName()
{
    return courseName_;
}

void
GradeBook::displayMessage()
{
    std::cout << "Welcome to th grade book for \n" << getCourseName() << "!\n" << std::endl;
}

void
GradeBook::inputGrades()
{
    int grade;
    std::cout << "\nEnter the letter grades.\nEnter the EOF character to end input." << std::endl;

    while ((grade = std::cin.get()) != EOF) {
        switch (grade) {
        case 'A': case'a': ++aCount_;    break;
        case 'B': case'b': ++bCount_;    break;
        case 'C': case'c': ++cCount_;    break;
        case 'D': case'd': ++dCount_;    break;
        case 'F': case'f': ++fCount_;    break;
        case '\n': case '\t': case ' ': break;
        default: std::cout << "Incorrect letter grade entered. Enter a new grade." << std::endl; break;
        }
    }
}

void
GradeBook::displayGradeReport()
{
    std::cout << "\n\nNumber of students who received each letter grade."
              << "\nA: " << aCount_
              << "\nB: " << bCount_
              << "\nC: " << cCount_
              << "\nD: " << dCount_
              << "\nF: " << fCount_ << std::endl;
    std::cout << "Grade point average is " << (4 * aCount_ + 3 * bCount_ + 2 * cCount_ + 1 * dCount_ + 0 * fCount_) / (aCount_ + bCount_ + cCount_ + dCount_ + fCount_) << std::endl;
}

