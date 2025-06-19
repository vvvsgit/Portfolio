#ifndef __LIST_NODE_HPP__
#define __LIST_NODE_HPP__

#include <cstddef>

template <typename NODETYPE> class List;

template <typename NODETYPE>
class ListNode
{
public:
    friend class List<NODETYPE>;
public:
    ListNode(const NODETYPE& data);
    NODETYPE getData() const;
private:
    NODETYPE data_;
    ListNode<NODETYPE>* nextPtr_;
};

#include "templates/ListNode.cpp"

#endif

