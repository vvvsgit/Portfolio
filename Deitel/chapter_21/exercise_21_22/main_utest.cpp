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

TEST(Tree, DeleteRoot)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    Tree<int> intTree;
    const int intValue[] = { 50, 25, 75, 12, 33, 67, 88, 6, 13, 68 };
    for (int i = 0; i < 10; ++i) {
        intTree.insertNode(intValue[i]);
    }

    std::cout << "\nPreorder traversal\n";
    intTree.preOrderTraversal();
    std::cout << "\nInorder traversal\n";
    intTree.inOrderTraversal();
    std::cout << "\nPostorder traversal\n";
    intTree.postOrderTraversal();
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 0; i <= 10; ++i) {
    switch (i) {
    case 6:  intTree.deleteNode(6);  break; 
    case 4:  intTree.deleteNode(13); break; 
    case 5:  intTree.deleteNode(12); break; 
    case 2:  intTree.deleteNode(33); break; 
    case 3:  intTree.deleteNode(25); break; 
    case 8:  intTree.deleteNode(68); break; 
    case 9:  intTree.deleteNode(67); break; 
    case 10: intTree.deleteNode(88); break; 
    case 7:  intTree.deleteNode(75); break; 
    case 1:  intTree.deleteNode(50); break; 
    case 0:  intTree.deleteNode(51); break; 
    }

    std::cout << "\nPreorder traversal\n";
    intTree.preOrderTraversal();
    std::cout << "\nInorder traversal\n";
    intTree.inOrderTraversal();
    std::cout << "\nPostorder traversal\n";
    intTree.postOrderTraversal();
    std::cout << std::endl;
    std::cout << std::endl;
    }

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "\nPreorder traversal\n50 25 12 6 13 33 75 67 68 88 \nInorder traversal\n6 12 13 25 33 50 67 68 75 88 \nPostorder traversal\n6 13 12 33 25 68 67 88 75 50 \n\nDeleting 51\nNo such element.\n\nPreorder traversal\n50 25 12 6 13 33 75 67 68 88 \nInorder traversal\n6 12 13 25 33 50 67 68 75 88 \nPostorder traversal\n6 13 12 33 25 68 67 88 75 50 \n\nDeleting 50\n\nPreorder traversal\n33 25 12 6 13 75 67 68 88 \nInorder traversal\n6 12 13 25 33 67 68 75 88 \nPostorder traversal\n6 13 12 25 68 67 88 75 33 \n\nDeleting 33\n\nPreorder traversal\n25 12 6 13 75 67 68 88 \nInorder traversal\n6 12 13 25 67 68 75 88 \nPostorder traversal\n6 13 12 68 67 88 75 25 \n\nDeleting 25\n\nPreorder traversal\n13 12 6 75 67 68 88 \nInorder traversal\n6 12 13 67 68 75 88 \nPostorder traversal\n6 12 68 67 88 75 13 \n\nDeleting 13\n\nPreorder traversal\n12 6 75 67 68 88 \nInorder traversal\n6 12 67 68 75 88 \nPostorder traversal\n6 68 67 88 75 12 \n\nDeleting 12\n\nPreorder traversal\n6 75 67 68 88 \nInorder traversal\n6 67 68 75 88 \nPostorder traversal\n68 67 88 75 6 \n\nDeleting 6\n\nPreorder traversal\n75 67 68 88 \nInorder traversal\n67 68 75 88 \nPostorder traversal\n68 67 88 75 \n\nDeleting 75\n\nPreorder traversal\n68 67 88 \nInorder traversal\n67 68 88 \nPostorder traversal\n67 88 68 \n\nDeleting 68\n\nPreorder traversal\n67 88 \nInorder traversal\n67 88 \nPostorder traversal\n88 67 \n\nDeleting 67\n\nPreorder traversal\n88 \nInorder traversal\n88 \nPostorder traversal\n88 \n\nDeleting 88\n\nPreorder traversal\n\nInorder traversal\n\nPostorder traversal\n\n\n");
}

TEST(Tree, DeleteChild)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    Tree<int> intTree;
    const int intValue[] = { 50, 25, 75, 12, 33, 67, 88, 6, 13, 68 };
    for (int i = 0; i < 10; ++i) {
        intTree.insertNode(intValue[i]);
    }

    std::cout << "\nPreorder traversal\n";
    intTree.preOrderTraversal();
    std::cout << "\nInorder traversal\n";
    intTree.inOrderTraversal();
    std::cout << "\nPostorder traversal\n";
    intTree.postOrderTraversal();
    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 0; i <= 10; ++i) {
    switch (i) {
    case 9: intTree.deleteNode(6);  break; 
    case 2: intTree.deleteNode(13); break; 
    case 1: intTree.deleteNode(12); break; 
    case 4: intTree.deleteNode(33); break; 
    case 5: intTree.deleteNode(25); break; 
    case 3: intTree.deleteNode(68); break; 
    case 0: intTree.deleteNode(67); break; 
    case 6: intTree.deleteNode(88); break; 
    case 7: intTree.deleteNode(75); break; 
    case 10: intTree.deleteNode(50); break; 
    case 8: intTree.deleteNode(51); break; 
    }

    std::cout << "\nPreorder traversal\n";
    intTree.preOrderTraversal();
    std::cout << "\nInorder traversal\n";
    intTree.inOrderTraversal();
    std::cout << "\nPostorder traversal\n";
    intTree.postOrderTraversal();
    std::cout << std::endl;
    std::cout << std::endl;
    }

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "\nPreorder traversal\n50 25 12 6 13 33 75 67 68 88 \nInorder traversal\n6 12 13 25 33 50 67 68 75 88 \nPostorder traversal\n6 13 12 33 25 68 67 88 75 50 \n\nDeleting 67\n\nPreorder traversal\n50 25 12 6 13 33 75 68 88 \nInorder traversal\n6 12 13 25 33 50 68 75 88 \nPostorder traversal\n6 13 12 33 25 68 88 75 50 \n\nDeleting 12\n\nPreorder traversal\n50 25 6 13 33 75 68 88 \nInorder traversal\n6 13 25 33 50 68 75 88 \nPostorder traversal\n13 6 33 25 68 88 75 50 \n\nDeleting 13\n\nPreorder traversal\n50 25 6 33 75 68 88 \nInorder traversal\n6 25 33 50 68 75 88 \nPostorder traversal\n6 33 25 68 88 75 50 \n\nDeleting 68\n\nPreorder traversal\n50 25 6 33 75 88 \nInorder traversal\n6 25 33 50 75 88 \nPostorder traversal\n6 33 25 88 75 50 \n\nDeleting 33\n\nPreorder traversal\n50 25 6 75 88 \nInorder traversal\n6 25 50 75 88 \nPostorder traversal\n6 25 88 75 50 \n\nDeleting 25\n\nPreorder traversal\n50 6 75 88 \nInorder traversal\n6 50 75 88 \nPostorder traversal\n6 88 75 50 \n\nDeleting 88\n\nPreorder traversal\n50 6 75 \nInorder traversal\n6 50 75 \nPostorder traversal\n6 75 50 \n\nDeleting 75\n\nPreorder traversal\n50 6 \nInorder traversal\n6 50 \nPostorder traversal\n6 50 \n\nDeleting 51\nNo such element.\n\nPreorder traversal\n50 6 \nInorder traversal\n6 50 \nPostorder traversal\n6 50 \n\nDeleting 6\n\nPreorder traversal\n50 \nInorder traversal\n50 \nPostorder traversal\n50 \n\nDeleting 50\n\nPreorder traversal\n\nInorder traversal\n\nPostorder traversal\n\n\n");
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

