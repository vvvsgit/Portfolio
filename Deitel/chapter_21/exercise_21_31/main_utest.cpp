#include "headers/List.hpp"
#include "headers/Queue.hpp"

#include <gtest/gtest.h>
#include <iostream>
#include <string>

void
instructions()
{
    std::cout << "Enter one of the following:\n"
    << " 1 to insert at beginning of list\n"
    << " 2 to insert at end of list\n"
    << " 3 to delete from beginning of list\n"
    << " 4 to delete from end of list\n"
    << " 5 to end list processing\n";
}

template <typename T>
void
testList(List<T>& listObject, const std::string& typeName)
{
    std::cout << "Testing a List of " << typeName << " values\n";
    instructions();
    int choice;
    T value;
    int caseInput[] = {1, 1, 2, 2, 3, 3, 4, 4, 5};
    int ci = 0;
    T valueInput[] = {static_cast<T>(1.1), static_cast<T>(2.2), static_cast<T>(3.3), static_cast<T>(4.4)};
    int vi = 0;
    do {
        std::cout << "? ";
        std::cout << caseInput[ci] << std::endl;
        choice = caseInput[ci];
        switch (choice)
        {
        case 1:
            std::cout << "Enter " << typeName << ": ";
            value = static_cast<T>(valueInput[vi]);
            std::cout << valueInput[vi] << std::endl; ++vi;
            listObject.insertAtFront(value);
            listObject.print();
        break;
        case 2:
            std::cout << "Enter " << typeName << ": ";
            value = static_cast<T>(valueInput[vi]);
            std::cout << valueInput[vi] << std::endl; ++vi;
            listObject.insertAtBack(value);
            listObject.print();
        break;
        case 3:
            if (listObject.removeFromFront(value))
            std::cout << value << " removed from list\n";
            listObject.print();
        break;
        case 4:
            if (listObject.removeFromBack(value))
            std::cout << value << " removed from list\n";
            listObject.print();
        break;
        }
        ++ci;
    } while (choice != 5);
    std::cout << "End list test\n" << std::endl;
}

TEST(List, Int)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    List<int> integerList;
    testList(integerList, "integer");

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "Testing a List of integer values\nEnter one of the following:\n 1 to insert at beginning of list\n 2 to insert at end of list\n 3 to delete from beginning of list\n 4 to delete from end of list\n 5 to end list processing\n? 1\nEnter integer: 1\nThe list is: 1 \n\n? 1\nEnter integer: 2\nThe list is: 2 1 \n\n? 2\nEnter integer: 3\nThe list is: 2 1 3 \n\n? 2\nEnter integer: 4\nThe list is: 2 1 3 4 \n\n? 3\n2 removed from list\nThe list is: 1 3 4 \n\n? 3\n1 removed from list\nThe list is: 3 4 \n\n? 4\n4 removed from list\nThe list is: 3 \n\n? 4\n3 removed from list\nThe list is empty\n\n? 5\nEnd list test\n\n");
}

TEST(List, Double)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    List<double> doubleList;
    testList(doubleList, "double");

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput,  "Testing a List of double values\nEnter one of the following:\n 1 to insert at beginning of list\n 2 to insert at end of list\n 3 to delete from beginning of list\n 4 to delete from end of list\n 5 to end list processing\n? 1\nEnter double: 1.1\nThe list is: 1.1 \n\n? 1\nEnter double: 2.2\nThe list is: 2.2 1.1 \n\n? 2\nEnter double: 3.3\nThe list is: 2.2 1.1 3.3 \n\n? 2\nEnter double: 4.4\nThe list is: 2.2 1.1 3.3 4.4 \n\n? 3\n2.2 removed from list\nThe list is: 1.1 3.3 4.4 \n\n? 3\n1.1 removed from list\nThe list is: 3.3 4.4 \n\n? 4\n4.4 removed from list\nThe list is: 3.3 \n\n? 4\n3.3 removed from list\nThe list is empty\n\n? 5\nEnd list test\n\n"); 
}

TEST(Queue, Int)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    Queue<int> intQueue;
    std::cout << "processing an integer Queue" << std::endl;
    for (int i = 0; i < 3; ++i)
    {
        intQueue.enqueue(i);
        intQueue.printQueue();
    }
    int dequeueInteger;
    while (!intQueue.isQueueEmpty())
    {
        intQueue.dequeue(dequeueInteger);
        std::cout << dequeueInteger << " dequeued" << std::endl;
        intQueue.printQueue();
    }

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "processing an integer Queue\nThe list is: 0 \n\nThe list is: 0 1 \n\nThe list is: 0 1 2 \n\n0 dequeued\nThe list is: 1 2 \n\n1 dequeued\nThe list is: 2 \n\n2 dequeued\nThe list is empty\n\n");
}

TEST(Queue, Double)
{
    std::ostringstream buffer;
    std::streambuf* oldBuffer = std::cout.rdbuf(buffer.rdbuf());

    Queue<double> doubleQueue;
    double value = 1.1;
    std::cout << "processing a double Queue" << std::endl;
    for (int j = 0; j < 3; ++j)
    {
        doubleQueue.enqueue(value);
        doubleQueue.printQueue();
        value += 1.1;
    }
    double dequeueDouble;
    while (!doubleQueue.isQueueEmpty())
    {
        doubleQueue.dequeue(dequeueDouble);
        std::cout << dequeueDouble << " dequeued" << std::endl;
        doubleQueue.printQueue();
    }

    const std::string lastOutput = buffer.str();
    std::cout.rdbuf(oldBuffer);

    EXPECT_EQ(lastOutput, "processing a double Queue\nThe list is: 1.1 \n\nThe list is: 1.1 2.2 \n\nThe list is: 1.1 2.2 3.3 \n\n1.1 dequeued\nThe list is: 2.2 3.3 \n\n2.2 dequeued\nThe list is: 3.3 \n\n3.3 dequeued\nThe list is empty\n\n");
}

TEST(List, InsertDelete)
{
    List<int> integerList;
    EXPECT_TRUE(integerList.isEmpty());

    integerList.insert(0, 3);
    EXPECT_FALSE(integerList.isEmpty());
    EXPECT_EQ(integerList.size(), 1);
    integerList.print();
    
    integerList.insert(1, 2);
    EXPECT_EQ(integerList.size(), 2);
    integerList.print();

    integerList.insert(0, 4);
    EXPECT_EQ(integerList.size(), 3);
    integerList.print();

    integerList.insert(1, 5);
    integerList.insert(3, 6);
    integerList.print();
    EXPECT_EQ(integerList.size(), 5);

    integerList.erase(0);
    EXPECT_EQ(integerList.size(), 4);
    integerList.print();

    integerList.erase(3);
    EXPECT_EQ(integerList.size(), 3);
    integerList.print();

    integerList.erase(1);
    EXPECT_EQ(integerList.size(), 2);
    integerList.print();
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

