#include "headers/Tree.hpp"

#include <gtest/gtest.h>

TEST(Tree, Int)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    Tree<int> intTree;
    std::cout << "Enter 10 integer values:\n";
    const int intValue[] = { 50, 25, 75, 12, 33, 67, 88, 6, 13, 68 };
    for (int i = 0; i < 10; ++i) {
        std::cout << intValue[i] << ' ';
        intTree.insertNode(intValue[i]);
    }

    std::cout << std::endl;
    std::cout << "\nPreorder traversal\n";
    intTree.preOrderTraversal();
    std::cout << "\nInorder traversal\n";
    intTree.inOrderTraversal();
    std::cout << "\nPostorder traversal\n";
    intTree.postOrderTraversal();
    std::cout << std::endl;

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "Enter 10 integer values:\n50 25 75 12 33 67 88 6 13 68 \n\nPreorder traversal\n50 25 12 6 13 33 75 67 68 88 \nInorder traversal\n6 12 13 25 33 50 67 68 75 88 \nPostorder traversal\n6 13 12 33 25 68 67 88 75 50 \n");
}

TEST(Tree, Double)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    Tree<double> doubleTree;
    std::cout << std::fixed << std::setprecision(1)
    << "\n\n\nEnter 10 double values:\n";
    const double doubleValue[] = { 39.2, 16.5, 82.7, 3.3, 65.2, 90.8, 1.1, 4.4, 89.5, 92.5 };
    for (int i = 0; i < 10; ++i) {
        std::cout << doubleValue[i] << ' ';
        doubleTree.insertNode(doubleValue[i]);
    }
    std::cout << std::endl;

    std::cout << "\nPreorder traversal\n";
    doubleTree.preOrderTraversal();
    std::cout << "\nInorder traversal\n";
    doubleTree.inOrderTraversal();
    std::cout << "\nPostorder traversal\n";
    doubleTree.postOrderTraversal();
    std::cout << std::endl;

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "\n\n\nEnter 10 double values:\n39.2 16.5 82.7 3.3 65.2 90.8 1.1 4.4 89.5 92.5 \n\nPreorder traversal\n39.2 16.5 3.3 1.1 4.4 82.7 65.2 90.8 89.5 92.5 \nInorder traversal\n1.1 3.3 4.4 16.5 39.2 65.2 82.7 89.5 90.8 92.5 \nPostorder traversal\n1.1 4.4 3.3 16.5 65.2 89.5 92.5 90.8 82.7 39.2 \n");
}

TEST(Tree, LevelOrderTraversal)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    Tree<int> intTree;
    const int intValue[] = { 39, 82, 16, 3, 65, 90, 1, 4, 89, 92 };
    for (int i = 0; i < 10; ++i) {
        intTree.insertNode(intValue[i]);
    }

    intTree.levelOrderTraversal();
    std::cout << std::endl;

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "39 16 82 3 65 90 1 4 89 92 \n");
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

