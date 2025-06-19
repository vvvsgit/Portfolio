#include "headers/List.hpp"

#include <cassert>

template <typename NODETYPE>
List<NODETYPE>::List()
    : firstPtr_(NULL)
    , lastPtr_(NULL)
{
}

template <typename NODETYPE>
List<NODETYPE>::~List()
{
    if (!isEmpty()) {
        std::cout << "Destroying nodes ...\n";
        ListNode<NODETYPE>* currentPtr = firstPtr_;
        ListNode<NODETYPE>* tempPtr;
        while (currentPtr != NULL) {
            tempPtr = currentPtr;
            std::cout << tempPtr->data_ << '\n';
            currentPtr = currentPtr->nextPtr_;
            delete tempPtr;
        } 
    } 
    std::cout << "All nodes destroyed\n\n";
}

template <typename NODETYPE>
void
List<NODETYPE>::insertAtFront(const NODETYPE& value)
{
    ListNode<NODETYPE>* newPtr = getNewNode(value);
    if (isEmpty()) {
        firstPtr_ = lastPtr_ = newPtr;
    } else {
        newPtr->nextPtr_ = firstPtr_;
        firstPtr_ = newPtr;
    }
} 

template <typename NODETYPE>
void
List<NODETYPE>::insertAtBack(const NODETYPE& value)
{
    ListNode<NODETYPE>* newPtr = getNewNode(value);
    if (isEmpty()) {
        firstPtr_ = lastPtr_ = newPtr;
    } else {
        lastPtr_->nextPtr_ = newPtr;
        lastPtr_ = newPtr;
    }
}

template <typename NODETYPE>
bool
List<NODETYPE>::removeFromFront(NODETYPE& value)
{
    if (isEmpty()) {
        return false;
    } else {
        ListNode<NODETYPE>* tempPtr = firstPtr_;
        if (firstPtr_ == lastPtr_) {
            firstPtr_ = lastPtr_ = NULL;
        } else {
            firstPtr_ = firstPtr_->nextPtr_;
        }
        value = tempPtr->data_;
        delete tempPtr;
        return true;
    }
}

template <typename NODETYPE>
bool
List<NODETYPE>::removeFromBack(NODETYPE& value)
{
    if (isEmpty()) {
        return false;
    } else {
        ListNode<NODETYPE>* tempPtr = lastPtr_;
        if (firstPtr_ == lastPtr_) {
            firstPtr_ = lastPtr_ = NULL;
        } else {
            ListNode<NODETYPE>* currentPtr = firstPtr_;
            
            while (currentPtr->nextPtr_ != lastPtr_) {
                currentPtr = currentPtr->nextPtr_;
            }
            lastPtr_ = currentPtr;
            currentPtr->nextPtr_ = NULL;
        } 
        value = tempPtr->data_;
        delete tempPtr;
        return true;
    }
}

template <typename NODETYPE>
bool
List<NODETYPE>::isEmpty() const
{
    return NULL == firstPtr_;
}

template <typename NODETYPE>
ListNode<NODETYPE>* 
List<NODETYPE>::getNewNode(const NODETYPE& value)
{
    return new ListNode<NODETYPE>(value);
}

template <typename NODETYPE>
void
List<NODETYPE>::print() const
{
    if (isEmpty()) {
        std::cout << "The list is empty\n" << std::endl;
        return;
    }
    ListNode<NODETYPE>* currentPtr = firstPtr_;
    std::cout << "The list is: ";
    while (currentPtr != NULL) {
        std::cout << currentPtr->data_ << ' ';
        currentPtr = currentPtr->nextPtr_;
    }
    std::cout << "\n" << std::endl;
}

template <typename NODETYPE>
size_t
List<NODETYPE>::size() const
{
    if (isEmpty()) return 0;
    if (firstPtr_ == lastPtr_)  return 1;
    
    ListNode<NODETYPE>* tempPtr = firstPtr_;
    size_t count = 0;
    while (tempPtr != lastPtr_) {
        ++count;
        tempPtr = tempPtr->nextPtr_;
    }

    return count + 1;
}

template <typename NODETYPE>
void
List<NODETYPE>::insert(const size_t pos, const NODETYPE& value)
{
    if (isEmpty()) {
        insertAtFront(value);
        return;
    }
    assert(pos <= size());

    ListNode<NODETYPE>* newPtr = getNewNode(value);
    if (pos == 0) {
        newPtr->nextPtr_ = firstPtr_;
        firstPtr_ = newPtr;
        return;
    }

    ListNode<NODETYPE>* tempPtr = firstPtr_;
    for (size_t i = 0; i < pos - 1; ++i) {
        tempPtr = tempPtr->nextPtr_;
    }
    if (pos == size()) {
        tempPtr->nextPtr_ = newPtr;
        lastPtr_ = newPtr;
        return;
    }
    newPtr->nextPtr_ = tempPtr->nextPtr_;
    tempPtr->nextPtr_ = newPtr;
}

template <typename NODETYPE>
void
List<NODETYPE>::erase(const size_t pos)
{
    assert(!isEmpty());
    assert(pos < size());
    if (firstPtr_ == lastPtr_) {
        delete firstPtr_;
        firstPtr_ = lastPtr_ = NULL;
        return;
    }

    ListNode<NODETYPE>* tempPtr = firstPtr_;
    if (pos == 0) {
        firstPtr_ = firstPtr_->nextPtr_;
        delete tempPtr;
        return;
    }
    for (size_t i = 0; i < pos - 1; ++i) {
        tempPtr = tempPtr->nextPtr_;
    }
    ListNode<NODETYPE>* toDelete = tempPtr->nextPtr_;
    if (toDelete == lastPtr_) {
        lastPtr_ = tempPtr;
        lastPtr_->nextPtr_ = NULL;
        delete toDelete;
        return;
    }
    tempPtr->nextPtr_ = tempPtr->nextPtr_->nextPtr_;
    delete toDelete;
}

