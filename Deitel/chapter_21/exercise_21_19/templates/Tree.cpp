#include "headers/Tree.hpp"

template <typename NODETYPE>
Tree<NODETYPE>::Tree()
    : rootPtr_(NULL)
{
}

template <typename NODETYPE>
void 
Tree<NODETYPE>::insertNode(const NODETYPE& value)
{
    insertNodeHelper(&rootPtr_, value);
}


template<typename NODETYPE>
void 
Tree<NODETYPE>::insertNodeHelper(TreeNode<NODETYPE>** ptr, const NODETYPE& value)
{
    if (*ptr == NULL) {
        *ptr = new TreeNode<NODETYPE>(value);
    } else if (value < (*ptr)->data_) {
        insertNodeHelper(&((*ptr)->leftPtr_), value);
    } else if (value > (*ptr)->data_) {
        insertNodeHelper(&((*ptr)->rightPtr_), value);
    } else {
        std::cout << value << " dup" << std::endl;
    }
}

template <typename NODETYPE>
void 
Tree<NODETYPE>::preOrderTraversal() const
{
    preOrderHelper(rootPtr_);
}

template <typename NODETYPE>
void
Tree<NODETYPE>::preOrderHelper(TreeNode<NODETYPE>* ptr) const
{
    if (ptr != NULL) {
        std::cout << ptr->data_ << ' ';
        preOrderHelper(ptr->leftPtr_);
        preOrderHelper(ptr->rightPtr_);
    }
}

template <typename NODETYPE>
void 
Tree<NODETYPE>::inOrderTraversal() const
{
    inOrderHelper(rootPtr_);
}

template <typename NODETYPE>
void
Tree<NODETYPE>::inOrderHelper(TreeNode<NODETYPE>* ptr) const
{
    if (ptr != NULL) {
        inOrderHelper(ptr->leftPtr_);
        std::cout << ptr->data_ << ' ';
        inOrderHelper(ptr->rightPtr_);
    }
}

template <typename NODETYPE>
void
Tree<NODETYPE>::postOrderTraversal() const
{
    postOrderHelper(rootPtr_);
}

template <typename NODETYPE>
void
Tree<NODETYPE>::postOrderHelper(TreeNode<NODETYPE>* ptr) const
{
    if (ptr != NULL) {
        postOrderHelper(ptr->leftPtr_);
        postOrderHelper(ptr->rightPtr_);
        std::cout << ptr->data_ << ' ';
    }
}

template <typename NODETYPE> 
int 
Tree<NODETYPE>::depth() const
{
    int result = 0;
    depthHelper(rootPtr_, result);
    return result;
}

template <typename NODETYPE> 
void 
Tree<NODETYPE>::depthHelper(TreeNode<NODETYPE>* ptr, int& result, int counter) const
{
    if (ptr != NULL) {
        if (result < counter) result = counter;
        depthHelper(ptr->leftPtr_, result, counter + 1);
        depthHelper(ptr->rightPtr_, result, counter + 1);
    }
}

