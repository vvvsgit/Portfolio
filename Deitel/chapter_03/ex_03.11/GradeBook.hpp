#include <string>

class GradeBook
{
public:
    GradeBook(std::string, std::string);
    void setCourseName(std::string);
    void setInstructorName(std::string);
    std::string getCourseName();
    std::string getInstructorName();
    void displayMessage();
private:
    std::string courseName_;
    std::string instructorName_;
};

