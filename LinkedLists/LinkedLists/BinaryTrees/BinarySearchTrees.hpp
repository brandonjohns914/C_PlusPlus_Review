//
//  BinarySearchTrees.hpp
//  LinkedLists
//
//  Created by Brandon Johns on 8/5/24.
//

#ifndef BinarySearchTrees_hpp
#define BinarySearchTrees_hpp

#include <stdio.h>
#include <iostream>
#include "BinaryTreeNode.hpp"
#include "BinaryTrees.hpp"
#include "NodeType.hpp"
#include <cassert>
using namespace std;

template <class Type>
class binarySearchTreeType: public binaryTreeType<Type> {
public:
    bool search(const Type& item) const;
    
    void insert(const Type &item);
    void deleteNode(const Type& item);
    
private:
    void deleteFromTree(binaryTreeNode<Type>* &p);

protected:
    binaryTreeNode<Type> * root;
    
};

#endif /* BinarySearchTrees_hpp */


template <class Type>
bool binarySearchTreeType<Type>:: search(const Type& item) const{
    binaryTreeNode<Type> * current;
    bool found = false;
    
    if (root == NULL) {
        cerr<<" Cannot search the empty tree"<<endl;
    }
    else {
        current = root;
        
        while(current != NULL && !found){
            if(current->info == item){
                found = true;
            }
            else if(current->info > item){
                current = current->llink;
            }
            else {
                current = current->rlink;
            }
        }
    }
    return found;
}

template <class Type>
void binarySearchTreeType<Type>:: insert(const Type &item) {
    binaryTreeNode<Type> *current;
    binaryTreeNode<Type> *trailCurrent;
    binaryTreeNode<Type> *newNode;
    
    newNode = new binaryTreeNode<Type>;
    assert(newNode != NULL);
    newNode->info = item;
    newNode->llink = NULL;
    newNode->rlink = NULL;
    
    if(root == NULL){
        root = newNode;
    }
    else {
        current = root;
        while(current!= NULL){
            trailCurrent = current;
            if(current->info == item) {
                cerr<<"Item is already int he list"<<endl;
                return;
            }
            else if(current->info > item){
                current = current->llink;
            }
            else {
                current = current->rlink;
            }
        }
        
        if(trailCurrent->info > item){
            trailCurrent->llink = newNode;
        }
        else {
            trailCurrent->rlink = newNode;
        }
    }
}
template <class Type>
void binarySearchTreeType<Type>:: deleteNode(const Type& item){
    binaryTreeNode<Type> *current;
    binaryTreeNode<Type> *trailCurrent;
    bool found = false;
    
    if (root == NULL){
        cout<<" Cannot delete from an empty tree"<<endl;
    }
    else {
        current = root;
        trailCurrent = root;
        
        while(current != NULL && !found){
            if(current ->info == item) {
                found = true;
            }
            else
            {
                trailCurrent = current;
                
                if(current->info > item){
                    current= current->llink;
                }
                else {
                    current = current->rlink;
                }
            }
        }
        
        if(current == NULL){
            cout<<"Item is not in the tree" <<endl;
        }
        else if(found){
            if(current==root){
                deleteFromTree(root);
            }
            else if(trailCurrent->info > item){
                deleteFromTree(trailCurrent->llink);
            }
            else {
                deleteFromTree(trailCurrent->rlink); 
            }
        }
    }
}
template <class Type>
void binarySearchTreeType<Type>:: deleteFromTree(binaryTreeNode<Type>* &p) {
    binaryTreeNode<Type> *current;
    binaryTreeNode<Type> *trailCurrent;
    binaryTreeNode<Type> *temp;
    
    if ( p == NULL){
        cerr<<"the node is null"<<endl;
    }
    else if(p->llink == NULL && p->rlink == NULL){
        temp = p;
        p = NULL;
        delete temp;
    }
    else if(p->llink == NULL){
        temp = p;
        p = temp ->rlink;
        delete temp;
    }
    else if(p->rlink == NULL){
        temp = p;
        p = temp->llink;
        delete temp;
    }
    else {
        current = p->llink;
        trailCurrent = NULL;
        
        while(current->rlink != NULL){
            trailCurrent = current;
            current = current->rlink;
        }
        
        p->info = current->info;
        
        if(trailCurrent == NULL){
            p->llink = current -> llink;
        }
        else {
            trailCurrent->rlink = current->llink;
        }
        delete current;
    }
}
