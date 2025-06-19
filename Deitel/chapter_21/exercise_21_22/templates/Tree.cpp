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
void 
Tree<NODETYPE>::deleteNode(const NODETYPE& value)
{
    std::cout << "Deleting " << value << std::endl;

    TreeNode<NODETYPE>** target = &rootPtr_;

    while (*target != NULL && (*target)->data_ != value) {
        if (value < (*target)->data_) {
            target = &((*target)->leftPtr_);
        } else {
            target = &((*target)->rightPtr_);
        }
    }

    if (*target == NULL) {
        std::cout << "No such element." << std::endl;
        return;
    }

    TreeNode<NODETYPE>* toDelete = *target;

    if (toDelete->leftPtr_ == NULL && toDelete->rightPtr_ == NULL) {
        delete toDelete;
        *target = NULL;
    } else if (toDelete->leftPtr_ == NULL || toDelete->rightPtr_ == NULL) {
        TreeNode<NODETYPE>* child = (toDelete->leftPtr_ != NULL) ? toDelete->leftPtr_ : toDelete->rightPtr_;
        delete toDelete;
        *target = child;
    } else {
        TreeNode<NODETYPE>* replacementParent = toDelete;
        TreeNode<NODETYPE>* replacement = toDelete->leftPtr_;
        while (replacement->rightPtr_ != NULL) {
            replacementParent = replacement;
            replacement = replacement->rightPtr_;
        }

        toDelete->data_ = replacement->data_;

        TreeNode<NODETYPE>** replacementLink = NULL;
        if (replacementParent == toDelete) {
            replacementLink = &(replacementParent->leftPtr_);
        } else {
            replacementLink = &(replacementParent->rightPtr_);
        }

        TreeNode<NODETYPE>* toFree = *replacementLink;
        *replacementLink = replacement->leftPtr_;
        delete toFree;
    }
}

