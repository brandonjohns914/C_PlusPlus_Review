//
//  BinaryTrees.hpp
//  LinkedLists
//
//  Created by Brandon Johns on 8/5/24.
//

#ifndef BinaryTrees_hpp
#define BinaryTrees_hpp

#include <stdio.h>
#include <iostream>
#include "BinaryTreeNode.hpp"
#include "NodeType.hpp"
#include <cassert>

using namespace std;

template <class Type>
class binaryTreeType {
public:
    
    bool isEmpty() const;
    void inorderTraversal() const;
    void preorderTraversal() const;
    void postorderTraversal() const;
    
    
    
    int treeHeight() const;
    int treeNodeCount() const;
    int treeLeavesCount() const;
    
    void destoryTree();
    
    binaryTreeType(const binaryTreeType<Type> & otherTree);
    binaryTreeType();
    ~binaryTreeType();
    
    const binaryTreeType<Type> & operator = (const binaryTreeType<Type> & otherTree);

protected:
    binaryTreeNode<Type> *root;
    binaryTreeNode<Type> *stackType;
private:
    void copyTree(binaryTreeNode<Type> * &copiedTreeRoot, binaryTreeNode<Type>* otherTreeRoot);
    void destory(binaryTreeNode<Type>* &p);
    
    int height(binaryTreeNode<Type> *p )const;
    int max(int x, int y) const;
    int nodeCount(binaryTreeNode<Type> * p) const;
    int leavesCount(binaryTreeNode<Type> *p) const;
    
    void inorder(binaryTreeNode<Type> * p) const;
    void preorder(binaryTreeNode<Type> *p )const;
    void postorder(binaryTreeNode<Type> *p) const;
    
};



#endif /* BinaryTrees_hpp */

template <class Type>
int binaryTreeType<Type>:: height(binaryTreeNode<Type> *p ) const {
    if (p == NULL) {
        return 0;
    }
    else {
        return 1 + max(height(p->llink), height(p->rlink));
    }
}

template <class Type>
void binaryTreeType<Type>:: copyTree(binaryTreeNode<Type> * &copiedTreeRoot, binaryTreeNode<Type>* otherTreeRoot) {
    if(otherTreeRoot == NULL) {
        copiedTreeRoot = NULL;
    }
    else {
        copiedTreeRoot = new binaryTreeNode<Type>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
        copyTree(copiedTreeRoot->rlink, copiedTreeRoot->rlink);
    }
}


template<class Type>
void binaryTreeType<Type>:: inorder(binaryTreeNode<Type> * p) const {
    if (p != NULL){
        inorder(p->llink);
        cout<< p->info << " " <<endl;
        inorder(p->rlink);
    }
}


template<class Type>
void binaryTreeType<Type>:: preorder(binaryTreeNode<Type> *p )const{
    if (p != NULL){
        cout<< p->info << " " <<endl;
        preorder(p->llink);
        preorder(p->rlink);
    }
}

template<class Type>
void binaryTreeType<Type>:: postorder(binaryTreeNode<Type> *p) const {
    if (p != NULL){
        postorder(p->llink);
        postorder(p->rlink);
        cout<< p->info << " " <<endl;
    }
}


template <class Type>
bool binaryTreeType<Type>::  isEmpty() const {
    return (root == NULL);
}


template<class Type>
void binaryTreeType<Type>:: inorderTraversal() const {
    inorder(root);
}

template<class Type>
void binaryTreeType<Type>:: preorderTraversal() const {
    preorder(root);
}


template<class Type>
void binaryTreeType<Type>:: postorderTraversal() const {
    postorder(root);
}

template <class Type>
int binaryTreeType<Type>:: treeHeight() const {
    return height(root);
}

template <class Type>
int binaryTreeType<Type>:: treeNodeCount() const {
    return nodeCount(root);
}
template <class Type>
int binaryTreeType<Type>:: treeLeavesCount() const {
    return leavesCount(root);
}

template<class Type>
void binaryTreeType<Type>:: destory(binaryTreeNode<Type>* &p){
    if (p != NULL){
        destory(p->llink);
        destory(p->rlink);
        delete p;
        p= NULL;
    }
}

template<class Type>
void binaryTreeType<Type>:: destoryTree() {
    destory(root);
}

template <class Type>
binaryTreeType<Type>:: binaryTreeType(const binaryTreeType<Type> & otherTree){
    if(otherTree.root == NULL) {
        root = NULL;
    }
    else {
        copyTree(root, otherTree.root);
    }
}

template <class Type>
binaryTreeType<Type>:: binaryTreeType(){
    root = NULL;
}


template <class Type>
binaryTreeType<Type>:: ~binaryTreeType(){
    destory(root);
}





template <class Type>
int binaryTreeType<Type>:: max(int x, int y) const {
    if (x >= y) {
        return x;
    }
    else {
        return y;
    }
}


template <class Type>
int binaryTreeType<Type>:: nodeCount(binaryTreeNode<Type> * p) const{
    if (p == NULL) {
        return 0;
    }
    else {
        return (1 + nodeCount(p->llink) + nodeCount(p->rlink));
    }
}

template <class Type>
int binaryTreeType<Type>:: leavesCount(binaryTreeNode<Type> *p) const {
    if (p == NULL) {
        return 0;
    }
    else if (p->llink == NULL && p->rlink == NULL){
        return 1;
    }
    else {
        return leavesCount(p->llink) + leavesCount(p->rlink);
    }
}


template <class Type>
const binaryTreeType<Type> & binaryTreeType<Type>:: operator = (const binaryTreeType<Type> & otherTree) {
    if(this != &otherTree){
        if(root != NULL) {
            destory(root);
        }
        if(otherTree.root == NULL){
            root = NULL;
        }
        else {
            copyTree(root, otherTree.root);
        }
    }
    
    return *this;
}


