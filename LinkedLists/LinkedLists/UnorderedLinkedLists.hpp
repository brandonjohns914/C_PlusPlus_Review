//
//  UnorderedLinkedLists.hpp
//  LinkedLists
//
//  Created by Brandon Johns on 7/10/24.
//

#ifndef UnorderedLinkedLists_hpp
#define UnorderedLinkedLists_hpp

#include <stdio.h>
#include <iostream>
#include "LinkedListIterator.hpp"
#include "LinkedListType.hpp"
#include <cassert>

template<class Type>
class unorderedLinkedList: public linkedListType<Type> {
public:
    bool search(const Type& item) const;
    
    void insertFirst(const Type& item);
    
    void insertLast(const Type& item);
    
    void deleteNode(const Type& deleteItem);
}


#endif /* UnorderedLinkedLists_hpp */

template<class Type>
bool unorderedLinkedList<Type>:: search(const Type& item) const {
    
}

template<class Type>
void unorderedLinkedList<Type>:: insertFirst(const Type& item) {
    
}

template<class Type>
void unorderedLinkedList<Type>:: insertLast(const Type& item) {
    
}

template<class Type>
void unorderedLinkedList<Type>:: deleteNode(const Type& deleteItem) {
    
}
