#include "headers/Shape.hpp"

#include "headers/TwoDimensional.hpp"
#include "headers/Rectangle.hpp"
#include "headers/Circle.hpp"
#include "headers/Triangle.hpp"
#include "headers/Square.hpp"

#include <gtest/gtest.h>

TEST(Circle, Draw)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    Shape * shape = new Circle;
    shape->draw();
    delete shape;

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);


    std::string resultArray[9] = {"       * * *      \n",
                                  "   *           *  \n",
                                  "                  \n",
                                  " *               *\n",
                                  " *       .       *\n",
                                  " *               *\n",
                                  "                  \n",
                                  "   *           *  \n",
                                  "       * * *      \n"};
    std::string result;
    for (int i = 0; i < 9; ++i) {
        result += resultArray[i];
    }

    EXPECT_EQ(lastOutput, result);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

