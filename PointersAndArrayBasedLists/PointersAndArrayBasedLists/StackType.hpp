//
//  StackType.hpp
//  PointersAndArrayBasedLists
//
//  Created by Brandon Johns on 7/11/24.
//

#ifndef StackType_hpp
#define StackType_hpp

#include <stdio.h>
#include <iostream>
#include<cassert>
#include "StackADT.hpp"
using namespace std;

template<class Type>
class stackType: public stackADT<Type> {
public:
    const stackType<Type> & operator =(const stackType<Type> & otherStack);
    
    void initializeStack();
    
    bool isEmptyStack() const;
    
    bool isFullStack() const;
    
    void push(const Type& item);
    
    Type top() const;
    
    void pop();
    stackType(int stackSize = 100);
    
    stackType(const stackType<Type> & otherStack);
    ~stackType();
    
private:
    int maxStackSize;
    int stackTop;
    Type * list;
    
    void copyStack(const stackType<Type>& otherStack);
    
};

#endif /* StackType_hpp */



template<class Type>
const stackType<Type> &  stackType<Type>::  operator =(const stackType<Type> & otherStack) {
    if(this != &otherStack){
        copyStack(otherStack);
    }
    
    return *this; 
}

template<class Type>
void  stackType<Type>:: initializeStack() {
    stackTop = 0;
}

template<class Type>
bool  stackType<Type>:: isEmptyStack() const{
    return(stackTop == 0);
}

template<class Type>
bool  stackType<Type>::  isFullStack() const {
    return(stackTop == maxStackSize);
}

template<class Type>
void  stackType<Type>:: push(const Type& item){
    if(!isFullStack()){
        list[stackTop] = item;
        stackTop++;
    }
    else {
        cout<<"Cannot add toa full stack"<<endl;
    }
}

template<class Type>
Type  stackType<Type>:: top() const {
    assert(stackTop != 0);
    return list[stackTop - 1];
}

template<class Type>
void stackType<Type>::  pop(){
    if(!isEmptyStack()){
        stackTop--;
    }
    else {
        cout<<"Cannot remove from  an empty stack"<<endl;
    }
}

template<class Type>
stackType<Type>:: stackType(int stackSize ) {
    if(stackSize <= 0){
        cout<<"Size of the array to hold the stack must be positive"<<endl;
        
        maxStackSize = 100;
    }
    else {
        maxStackSize = stackSize;
    }
    
    stackTop = 0;
    list = new Type[maxStackSize];
}

template<class Type>
stackType<Type>:: stackType(const stackType<Type> & otherStack){
    delete [] list;
    
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;
    
    list = new Type[maxStackSize];
    
    for(int i = 0; i < stackTop; i++){
        list[i] = otherStack.list[i];
    }
}

template<class Type>
stackType<Type>:: ~stackType(){
    delete [] list;
}

template<class Type>
void stackType<Type>:: copyStack(const stackType<Type>& otherStack){
    list = NULL;
    copyStack(otherStack);
}
