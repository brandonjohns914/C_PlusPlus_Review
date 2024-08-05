//
//  BTrees.hpp
//  LinkedLists
//
//  Created by Brandon Johns on 8/5/24.
//

#ifndef BTrees_hpp
#define BTrees_hpp

#include <stdio.h>
#include <iostream>
#include "BTreeNode.hpp"
#include "NodeType.hpp"
#include <cassert>

using namespace std;


template <class Type, int bTreeOrder>
class bTree {
public:
    bool search(const Type& item);
    void searchNode(bTreeNode<Type, bTreeOrder> *current, const Type &item, bool & found, int & location);
    
    void insert(const Type& item);
    void insertNode(bTreeNode<Type, bTreeOrder> *current, const Type& item, bTreeNode<Type, bTreeOrder>* &rightChild, int position);
    
    void inOrder();
    void recInOrder(bTreeNode<Type, bTreeOrder> *current);
    
    void splitNode (bTreeNode<Type, bTreeOrder> *current, const Type& item, bTreeNode<Type, bTreeOrder>* rightChild, int position,
                    bTreeNode<Type, bTreeOrder>* &rightNode, Type &median);
    
    bTree();
protected:
    bTreeNode<Type, bTreeOrder> *root;
};

#endif /* BTrees_hpp */

template <class Type, int bTreeOrder>
bool bTree<Type, bTreeOrder>:: search(const Type& item){
    bool found = false;
    int location;
    
    bTreeNode<Type, bTreeOrder> *current;
    
    current = root;
    
    while(current != NULL && !found){
        searchNode(current, item,found,location);
        if(!found){
            current = current->children[location];
        }
    }
    return found;
}

template <class Type, int bTreeOrder>
void bTree<Type, bTreeOrder>:: searchNode(bTreeNode<Type, bTreeOrder> *current, const Type &item, bool & found, int & location) {
    location = 0;
    while(location < current->recCount && item > current->list[location]) {
        location++;
        
    }
    
    if(location < current->recCount && item == current->list[location]){
        found = true;
    }
    else {
        found = false;
    }
}

template <class Type, int bTreeOrder>
void bTree<Type, bTreeOrder>:: insertNode(bTreeNode<Type, bTreeOrder> *current, const Type& item, bTreeNode<Type, bTreeOrder>* &rightChild, int position){
    int index;
    
    for(index = current->recCount; index > position; index --){
        current->list[index] = current->list[index - 1];
        current->children[index + 1] = current->children[index];
    }
    
    current ->list[index] = item;
    current->children[index + 1] = rightChild;
    current->recCount++;
    
}

template <class Type, int bTreeOrder>
void bTree<Type, bTreeOrder>:: insert(const Type& item){
    bool isTaller = false;
    Type median;
    
    bTreeNode<Type, bTreeOrder> * rightChild;
    
    insertBTree(root, item, median, rightChild, isTaller);
    
    if(isTaller){
        bTreeNode<Type, bTreeOrder> * tempRoot;
        tempRoot = new bTreeNode<Type, bTreeOrder>;
        tempRoot->recCount = 1;
        tempRoot->list[0] = median;
        tempRoot->children[0] = root;
        tempRoot->children[1] = rightChild;
    }
}

template <class Type, int bTreeOrder>
void bTree<Type, bTreeOrder>:: recInOrder(bTreeNode<Type, bTreeOrder> *current) {
    if(current != NULL){
        recInOrder(current->children[0]);
        
        for(int i = 0; i < current->recCount; i++){
            cout<< current-> list[i]<< " ";
            recInOrder(current->children[i + 1]);
        }
    }
}

template <class Type, int bTreeOrder>
void bTree<Type, bTreeOrder>:: inOrder(){
    recInorder(root);
}

template <class Type, int bTreeOrder>
bTree<Type, bTreeOrder>:: bTree() {
    
}


template <class Type, int bTreeOrder>
void bTree<Type, bTreeOrder>:: splitNode (bTreeNode<Type, bTreeOrder> *current, const Type& item, bTreeNode<Type, bTreeOrder>* rightChild, int position,
                                          bTreeNode<Type, bTreeOrder>* &rightNode, Type &median) {
    rightNode = new bTreeNode<Type, bTreeOrder>;
    int mid = (bTreeOrder - 1 ) / 2;
    
    if(position <= mid) {
        int index = 0;
        int i = mid;
        
        while(i < bTreeOrder - 1) {
            rightNode-> list[index] = current->list[i];
            rightNode -> children[index + 1] = current->children[i + 1];
            index ++;
            i++;
        }
        
        current->recCount = mid;
        insertNode(current, item, rightChild, position);
        (current->recCount)--;
        
        median = current->list[current->recCount];
        
        rightNode->recCount = index;
        rightNode->child[0] = current-> children[current->recCount + 1];
    }
    else {
        int i = mid + 1;
        int index = 0;
        
        while(i < bTreeOrder - 1){
            rightNode->list[index] = current->list[i];
            rightNode->children[index + 1] = current->children[i+1];
            index++;
            i++;
        }
        
        current->recCount = mid;
        rightNode->recCount = index;
        
        median = current->list[mid];
        insertNode(rightNode, item, rightChild, position - mid - 1);
        rightNode->children[0] = current->children[current->recCount + 1];
    }
}
