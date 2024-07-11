//
//  LinkedListType.hpp
//  LinkedLists
//
//  Created by Brandon Johns on 7/9/24.
//

#ifndef LinkedListType_hpp
#define LinkedListType_hpp

#include <stdio.h>
#include <iostream>
#include "LinkedListIterator.hpp"
#include <cassert>
using namespace std;

template<class Type>
class linkedListType {
public:
    linkedListType();
    linkedListType(const linkedListType<Type>& otherList);
    ~linkedListType();
    
    const linkedListType<Type>& operator = (const linkedListType<Type> & otherList);
    
    void initializedList();
    bool isEmptyList() const;
    void print() const;
    int length() const;
    void destoryList();
    
    void reversePrint(nodeType<Type>* current) const;
    
    void printListReverse() const;
    
    Type front() const;
    Type back() const;
    
    
    linkedListIterator<Type> begin();
    linkedListIterator<Type> end();
    
    virtual bool search(const Type& searchItem) const = 0;
    virtual void insertFirst(const Type& newItem) = 0;
    virtual void insertLast(const Type& newITem) = 0;
    virtual void deleteNode(const Type& deleteItem) = 0;
    
protected:
    int count;
    
    nodeType<Type> *first;
    nodeType<Type> *last;
    
private:
    void copyList(const linkedListType<Type>& otherList);
    
};

#endif /* LinkedListType_hpp */

template<class Type>
linkedListType<Type>:: linkedListType() {
    first = NULL;
    last = NULL;
    count = 0;
}

template<class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList) {
    first = NULL;
    copyList(otherList);
}

template<class Type>
linkedListType<Type>:: ~linkedListType() {
    destoryList();
}


template<class Type>
void linkedListType<Type>:: initializedList(){
    destoryList();
}

template<class Type>
bool linkedListType<Type>:: isEmptyList() const{
    return (first == NULL);
}

template<class Type>
void linkedListType<Type>:: print() const{
    nodeType<Type> *current;
    current = first;
    while(current != NULL) {
        cout<< current->link << " "<<endl;
        current = current-> link;
    }
}


template<class Type>
void linkedListType<Type>:: reversePrint(nodeType<Type>* current) const {
    if (current != NULL){
        reversePrint(current->link);
        cout<< current->info << " " <<endl; 
    }
}
template<class Type>
void linkedListType<Type>:: printListReverse() const {
    reversePrint(first);
    cout<<endl;
}

template<class Type>
int linkedListType<Type>:: length() const{
    return count;
}

template<class Type>
void linkedListType<Type>:: destoryList(){
    nodeType<Type> *temp;
    while(first != NULL) {
        temp = first;
        first = first -> link;
        delete temp;
    }
    last = NULL;
    count = 0;
}

template<class Type>
Type linkedListType<Type>::  front() const{
    assert(first != NULL);
    return first->info;
}

template<class Type>
Type linkedListType<Type>::  back() const{
    assert(last !=NULL);
    return last->info;
}

template<class Type>
linkedListIterator<Type> linkedListType<Type>:: begin(){
    linkedListIterator<Type> temp(first);
    return temp;
}

template<class Type>
linkedListIterator<Type> linkedListType<Type>:: end(){
    linkedListIterator<Type> temp(NULL);
    return temp;
}



template<class Type>
const linkedListType<Type>& linkedListType<Type>:: operator = (const linkedListType<Type> & otherList){
    if( this != &otherList) {
        copyList(otherList);
    }
    return *this; 
}

template<class Type>
void linkedListType<Type>::  copyList(const linkedListType<Type>& otherList){
    nodeType<Type> *newNode;
    nodeType<Type> *current;
    
    if(first!= NULL){
        destoryList();
    }
    
    if(otherList.first == NULL){
        first = NULL;
        last = NULL;
        count = 0;
    }
    else {
        current = otherList.first;
        count = otherList.count;
        
        first = new nodeType<Type>; // new node
        first->info = current-> info; // copy nodes info
        first->link = NULL; // set link to null
        last = first; // last points to first
        current = current->link; // current pointer next node
        
        //copy list
        while(current!= NULL) {
            newNode = new nodeType<Type>;
            newNode-> info = current->info; // copy info
            newNode->link = NULL; // link to null
            
            last->link = newNode; // attach newNode to last
            last = newNode; // last actually last
            
            current= current->link;
        }
    }
}
