#include "headers/LinkedList.hpp"

LinkedList::LinkedList()
    : firstPtr_(NULL), lastPtr_(NULL)
{
}

LinkedList::~LinkedList()
{
    if (!isEmpty()) {
        ListNode* currentPtr = firstPtr_;
        ListNode* tempPtr;
        while (currentPtr != NULL) {
            tempPtr = currentPtr;
            currentPtr = currentPtr->nextPtr_;
            delete tempPtr;
        }
    }
    firstPtr_ = lastPtr_ = NULL;
}

void 
LinkedList::insertAtBack(const char data)
{
    ListNode* newPtr = new ListNode(data);
    if (isEmpty()) {
        firstPtr_ = lastPtr_ = newPtr;
    } else {
        lastPtr_->nextPtr_ = newPtr;
        lastPtr_ = newPtr;
    }
}

bool
LinkedList::isEmpty() const
{
    return NULL == firstPtr_;
}

void
LinkedList::print() const
{
    if (isEmpty()) {
        std::cout << "-";
        return;
    }
    ListNode* currentPtr = firstPtr_;
    while (currentPtr != NULL)
    {
        std::cout << currentPtr->data_ << ' ';
        currentPtr = currentPtr->nextPtr_;
    } 
}

void
concatenate(LinkedList& left, LinkedList& right)
{
    left.lastPtr_->nextPtr_ = right.firstPtr_;
    left.lastPtr_ = right.lastPtr_;
    right.firstPtr_ = NULL;
    right.lastPtr_ = NULL;
}

