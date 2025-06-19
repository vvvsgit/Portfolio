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
    const TreeNode<NODETYPE>* binarySearchTree(const NODETYPE& value) const;
private:
    void insertNodeHelper(TreeNode<NODETYPE>** ptr, const NODETYPE& value);
    void preOrderHelper(TreeNode<NODETYPE>* ptr) const;
    void inOrderHelper(TreeNode<NODETYPE>* ptr) const;
    void postOrderHelper(TreeNode<NODETYPE>* ptr) const;
    const TreeNode<NODETYPE>* binarySearchTree(TreeNode<NODETYPE>* ptr, const NODETYPE& value) const;
private:
    TreeNode<NODETYPE>* rootPtr_;
};

#include "templates/Tree.cpp"

#endif

