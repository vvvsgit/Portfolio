#include "headers/ListNode.hpp"

template <typename NODETYPE>
ListNode<NODETYPE>::ListNode(const NODETYPE& data)
    : data_(data)
    , nextPtr_(NULL)
{
}

template <typename NODETYPE>
NODETYPE
ListNode<NODETYPE>::getData() const
{
    return data_;
}

