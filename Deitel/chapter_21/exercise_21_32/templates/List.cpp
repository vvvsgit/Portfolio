#include "headers/List.hpp"

template <typename NODETYPE>
List<NODETYPE>::List()
    : firstPtr_(NULL)
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
            firstPtr_ = NULL;
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
        firstPtr_ = newPtr;
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
        firstPtr_ = newPtr;
    } else {
        ListNode<NODETYPE>* lastPtr = firstPtr_;
        while (lastPtr->nextPtr_ != NULL) {
            lastPtr = lastPtr->nextPtr_;
        }

        lastPtr->nextPtr_ = newPtr;
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
        firstPtr_ = firstPtr_->nextPtr_;
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
        ListNode<NODETYPE>* lastPtr = firstPtr_;
        while (lastPtr->nextPtr_ != NULL) {
            lastPtr = lastPtr->nextPtr_;
        }

        ListNode<NODETYPE>* tempPtr = lastPtr;
        if (firstPtr_ == lastPtr) {
            firstPtr_ = NULL;
        } else {
            ListNode<NODETYPE>* currentPtr = firstPtr_;
            
            while (currentPtr->nextPtr_ != lastPtr) {
                currentPtr = currentPtr->nextPtr_;
            }
            lastPtr = currentPtr;
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
        std::cout << "The list is empty\n\n";
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

