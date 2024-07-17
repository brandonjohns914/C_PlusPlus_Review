//
//  StackADT.hpp
//  PointersAndArrayBasedLists
//
//  Created by Brandon Johns on 7/11/24.
//

#ifndef StackADT_hpp
#define StackADT_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

template<class Type>
class stackADT {
public:
    virtual void initializeStack() =0;
    virtual  bool isEmptyStack() const  = 0;
    virtual bool isFullStack() const = 0;
    virtual void push(const Type& newItem ) = 0;
    virtual Type top() const = 0;
    virtual void pop() = 0;
    
};

#endif /* StackADT_hpp */
