#ifndef __LINKED_LIST_HPP__
#define __LINKED_LIST_HPP__

#include <iostream>

struct ListNode
{
    ListNode(const char data)
        : data_(data), nextPtr_(NULL) {}
    char getData() const { return data_; }

    ///data members
    char data_;
    ListNode* nextPtr_;
};


class LinkedList
{
public:
    friend void concatenate(LinkedList& left, LinkedList& right);
public:
    LinkedList();
    ~LinkedList();
    void insertAtBack(const char data);
    bool isEmpty() const;
    void print() const;

private:
    ListNode* firstPtr_;
    ListNode* lastPtr_;
};


#endif

void concatenate(LinkedList& left, LinkedList& right);

