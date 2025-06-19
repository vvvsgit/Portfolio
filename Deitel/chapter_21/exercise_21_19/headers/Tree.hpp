#ifndef __TREE_HPP__
#define __TREE_HPP__

#include "headers/TreeNode.hpp"

#include <iostream>

template <typename NODETYPE> 
class Tree
{
public:
    Tree();
    void insertNode(const NODETYPE& value);
    void preOrderTraversal() const;
    void inOrderTraversal() const;
    void postOrderTraversal() const;
    int depth() const;
private:
    void insertNodeHelper(TreeNode<NODETYPE>** ptr, const NODETYPE& value);
    void preOrderHelper(TreeNode<NODETYPE>* ptr) const;
    void inOrderHelper(TreeNode<NODETYPE>* ptr) const;
    void postOrderHelper(TreeNode<NODETYPE>* ptr) const;
    void depthHelper(TreeNode<NODETYPE>* ptr, int& result, int counter = 0) const;
private:
    TreeNode<NODETYPE>* rootPtr_;
};

#include "templates/Tree.cpp"

#endif

