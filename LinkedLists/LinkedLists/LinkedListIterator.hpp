//
//  LinkedListIterator.hpp
//  LinkedLists
//
//  Created by Brandon Johns on 7/9/24.
//

#ifndef LinkedListIterator_hpp
#define LinkedListIterator_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

template<class Type>
struct nodeType {
    Type info;
    nodeType<Type> *link;
};

template<class Type>
class linkedListIterator {
public:
    linkedListIterator();
    
    linkedListIterator(nodeType<Type> *ptr);
    
    Type operator*();
    
    linkedListIterator<Type> operator++();
    
    bool operator ==(const linkedListIterator<Type>& right) const;
    
    bool operator!= (const linkedListIterator<Type>& right) const;
    
private:
    nodeType<Type> *current;
};

#endif /* LinkedListIterator_hpp */
