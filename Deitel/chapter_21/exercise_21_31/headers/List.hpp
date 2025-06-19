#ifndef __LIST_HPP__
#define __LIST_HPP__

#include "headers/ListNode.hpp"

#include <iostream>

template <typename NODETYPE>
class List
{
public:
    List();
    ~List();
    void insertAtFront(const NODETYPE& value);
    void insertAtBack(const NODETYPE& value);
    bool removeFromFront(NODETYPE& value);
    bool removeFromBack(NODETYPE& value);
    bool isEmpty() const;
    void print() const;
    
    size_t size() const;
    void insert(const size_t pos, const NODETYPE& value);
    void erase(const size_t pos);
private:
    ListNode<NODETYPE>* getNewNode(const NODETYPE& value);
    
private:
    ListNode<NODETYPE>* firstPtr_;
    ListNode<NODETYPE>* lastPtr_;
};

#include "templates/List.cpp"

#endif

