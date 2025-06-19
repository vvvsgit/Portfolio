#include <string>

class GradeBook
{
public:
    GradeBook(std::string);
    void setCourseName(std::string);
    std::string getCourseName();
    void displayMessage();
    void inputGrades();
    void displayGradeReport();
private:
    std::string courseName_;
    int aCount_;
    int bCount_;
    int cCount_;
    int dCount_;
    int fCount_;
};

