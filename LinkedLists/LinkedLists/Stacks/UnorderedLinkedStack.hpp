//
//  UnorderedLinkedStack.hpp
//  LinkedLists
//
//  Created by Brandon Johns on 7/16/24.
//

#ifndef UnorderedLinkedStack_hpp
#define UnorderedLinkedStack_hpp

#include <stdio.h>
#include "NodeType.hpp"
#include "StackADT.hpp"
#include "UnorderedLinkedLists.hpp"
#include <iostream>
#include<cassert>

using namespace std;
template <class Type>
class unorderedLinkedStackType: public unorderedLinkedList<Type> {
public:
    void initializeStack();
    bool isEmptyStack() const;
    bool isFullStack() const;
    void push(const Type& item);
    Type top() const;
    void pop();
    
protected:
    nodeType<Type> *first;
    nodeType<Type> *last;
};
#endif /* UnorderedLinkedStack_hpp */

template <class Type>
void unorderedLinkedStackType<Type>:: initializeStack() {
    unorderedLinkedList<Type>:: initializedList();
}

template <class Type>
bool unorderedLinkedStackType<Type>:: isEmptyStack() const{
    return unorderedLinkedList<Type>:: isEmptyList();
}

template <class Type>
bool unorderedLinkedStackType<Type>::  isFullStack() const{
    return false;
}
template <class Type>
void unorderedLinkedStackType<Type>:: push(const Type& item) {
    unorderedLinkedList<Type>:: insertFirst(item);
}
template <class Type>
Type unorderedLinkedStackType<Type>:: top() const{
    return unorderedLinkedList<Type>::front();
}

template <class Type>
void unorderedLinkedStackType<Type>::  pop() {
    nodeType<Type> *temp;
    
    temp = first;
    first = first->link;
    delete temp; 
}
