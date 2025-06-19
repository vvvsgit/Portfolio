#include "headers/functions.hpp"

#include <gtest/gtest.h>

TEST(StackReversePrint, Argument)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    std::list<char> charList;
    charList.push_back('j');
    charList.push_back('i');
    charList.push_back('h');
    charList.push_back('g');
    charList.push_back('f');
    charList.push_back('e');
    charList.push_back('d');
    charList.push_back('c');
    charList.push_back('b');
    charList.push_back('a');
    print(charList);

    std::list<char> reverseCharList;

    std::cout << std::endl;
    fillListReversed(charList, reverseCharList);
    print(reverseCharList);

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "j i h g f e d c b a \na b c d e f g h i j ");
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

