#ifndef __TREE_NODE_HPP__
#define __TREE_NODE_HPP__

#include <cstddef>

template <typename NODETYPE> class Tree;

template <typename NODETYPE>
class TreeNode
{
public:
    friend class Tree<NODETYPE>;
public:
    TreeNode(const NODETYPE& data);
    NODETYPE getData() const;
private:
    TreeNode<NODETYPE>* leftPtr_;
    NODETYPE data_;
    TreeNode<NODETYPE>* rightPtr_;
};

#include "templates/TreeNode.cpp"

#endif

