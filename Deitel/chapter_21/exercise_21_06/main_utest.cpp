#include "headers/LinkedList.hpp"

#include <gtest/gtest.h>

TEST(LinkedList, Concatenate)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    LinkedList a;
    a.insertAtBack('c');
    a.insertAtBack('c');
    a.insertAtBack('c');
    LinkedList b;
    b.insertAtBack('v');
    b.insertAtBack('v');
    b.insertAtBack('v');
    b.insertAtBack('v');

    concatenate(a, b);
    a.print();

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "c c c v v v v ");

}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

