//
//  LinkedQueueType.hpp
//  LinkedLists
//
//  Created by Brandon Johns on 7/17/24.
//

#ifndef LinkedQueueType_hpp
#define LinkedQueueType_hpp

#include <stdio.h>
#include <iostream>
#include "QueueADT.hpp"
#include "NodeType.hpp"
#include <cassert>
using namespace std;

template <class Type>
class linkedQueueType: public queueADT<Type> {
public:
    const linkedQueueType<Type>& operator= (const linkedQueueType<Type>& otherQueue);
    
    bool isEmptyQueue() const;
    bool isFullQueue() const;
    
    void initializeQueue();
    
    Type front() const;
    Type back() const;
    
    void addQueue(const Type& item);
    void deleteQueue();
    
    linkedQueueType();
    linkedQueueType(const linkedQueueType<Type>& otherQueue);
    ~linkedQueueType();
    
private:
    nodeType<Type> *queueFront;
    nodeType<Type> *queueRear;
    
    void copyQueue(const linkedQueueType<Type> & otherQueue);
};


#endif /* LinkedQueueType_hpp */


template <class Type>
const linkedQueueType<Type>& linkedQueueType<Type>:: operator= (const linkedQueueType<Type>& otherQueue) {
    
    if(this != &otherQueue){
        copyQueue(otherQueue);
    }
    return *this; 
}

template <class Type>
bool linkedQueueType<Type>:: isEmptyQueue() const {
    return(queueFront == NULL);
}

template <class Type>
bool linkedQueueType<Type>:: isFullQueue() const {
    return false;
}


template <class Type>
void linkedQueueType<Type>::  initializeQueue() {
    nodeType<Type> *temp;
    
    while(queueFront != NULL){
        temp = queueFront;
        queueFront = queueFront-> link;
        delete temp;
    }
    queueRear = NULL;
}

template <class Type>
Type linkedQueueType<Type>:: front() const {
    assert(queueFront!= NULL);
    return queueFront->info;
}
template <class Type>
Type linkedQueueType<Type>:: back() const {
    assert(queueRear != NULL);
    return queueRear->info;
}
template <class Type>
void linkedQueueType<Type>:: addQueue(const Type& item) {
    nodeType<Type> * newNode;
    newNode = new nodeType<Type>;
    
    newNode->info = item;
    newNode->link = NULL;
    
    if (queueFront == NULL){
        queueFront = newNode;
        queueRear = newNode;
    }
    else {
        queueRear -> link = newNode;
        queueRear = queueRear->link;
    }
}
template <class Type>
void linkedQueueType<Type>:: deleteQueue() {
    nodeType<Type> *temp;
    
    if(!isEmptyQueue()){
        temp = queueFront;
        queueFront = queueFront->link;
        
        delete temp;
        
        if(queueFront == NULL){
            queueRear = NULL;
        }
    }
    else {
        cout<<"cannot remove from an empty queue"<<endl;
    }
}

template <class Type>
linkedQueueType<Type>:: linkedQueueType() {
    queueFront = NULL;
    queueRear = NULL;
    
}

template <class Type>
linkedQueueType<Type>:: linkedQueueType(const linkedQueueType<Type>& otherQueue) {
    
}

template <class Type>
linkedQueueType<Type>:: ~linkedQueueType() {
    initializeQueue();
}

template<class Type>
void linkedQueueType<Type>::copyQueue(const linkedQueueType<Type>& otherQueue) {
    nodeType<Type>* newNode, *current;
    
    // Initialize the current queue if it's not empty
    if (queueFront != NULL) {
        initializeQueue();
    }
    
    // Handle the case where the other queue is empty
    if (otherQueue.queueFront == NULL) {
        queueFront = NULL;
        queueRear = NULL;
    } else {
        // Copy the first node
        current = otherQueue.queueFront;
        queueFront = new nodeType<Type>;
        queueFront->info = current->info;
        queueFront->link = NULL;
        
        queueRear = queueFront;
        current = current->link;
        
        // Copy the remaining nodes
        while (current != NULL) {
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = NULL;
            queueRear->link = newNode;
            queueRear = newNode;
            current = current->link;
        }
    }
}
