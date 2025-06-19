#include "headers/TreeNode.hpp"

template <typename NODETYPE>
TreeNode<NODETYPE>::TreeNode(const NODETYPE& data)
    : leftPtr_(NULL),
    data_(data),
    rightPtr_(NULL)
{
}

template <typename NODETYPE>
NODETYPE 
TreeNode<NODETYPE>::getData() const
{
    return data_;
}

