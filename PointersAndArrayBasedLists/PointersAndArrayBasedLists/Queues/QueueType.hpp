//
//  QueueType.hpp
//  PointersAndArrayBasedLists
//
//  Created by Brandon Johns on 7/17/24.
//

#ifndef QueueType_hpp
#define QueueType_hpp

#include <stdio.h>
#include <iostream>
#include "QueueADT.hpp"
#include <cassert>
using namespace std;

template <class Type>
class queueType: public queueADT<Type> {
public:
    const queueType<Type>& operator= (const queueType<Type>& otherQueue);
    
    bool isEmptyQueue() const;
    bool isFullQueue() const;
    
    void initializeQueue();
    
    Type front() const;
    Type back() const;
    
    void addQueue(const Type& item);
    void deleteQueue();
    
    queueType(int queueSize = 100);
    queueType(const queueType<Type>& otherQueue);
    ~queueType();
private:
    int maxQueueSize;
    int count;
    int queueFront;
    int queueRear;
    
    Type *list;
};

#endif /* QueueType_hpp */


template <class Type>
const queueType<Type>& queueType<Type>:: operator= (const queueType<Type>& otherQueue){
    if (this != &otherQueue) {
        delete [] list;
        maxQueueSize = otherQueue.maxQueueSize;
        queueFront = otherQueue.queueFront;
        queueRear = otherQueue.queueRear;
        count = otherQueue.count;
        
        list = new Type[maxQueueSize];
        assert(list != NULL);
       
        for(int i = 0; i < count; i++) {
            list[i] = otherQueue.list[i];
        }
    }
    return *this;
}

template <class Type>
bool queueType<Type>:: isEmptyQueue() const{
    return(count == 0);
}

template <class Type>
bool queueType<Type>:: isFullQueue() const{
    return (count == maxQueueSize);
}

template <class Type>
void queueType<Type>:: initializeQueue(){
    queueFront = 0;
    queueRear = maxQueueSize - 1;
    count = 0;
}

template <class Type>
Type  queueType<Type>:: front() const {
    assert(!isEmptyQueue());
    return list[queueFront];
}

template <class Type>
Type queueType<Type>:: back() const{
    assert(!isEmptyQueue());
    return list[queueRear];
}

template <class Type>
void queueType<Type>::  addQueue(const Type& item){
    if(!isFullQueue()){
        queueRear = (queueRear + 1) % maxQueueSize; //% because the array is a circle
        
        count++;
        list[queueRear] = item;
    }
    else {
        cout<<" cannot add to a full queue"<<endl;
    }
}

template <class Type>
void queueType<Type>:: deleteQueue(){
    if(!isEmptyQueue()) {
        count--;
        queueFront = (queueFront + 1) % maxQueueSize;
    }
    else {
        cout<<"cannot delete from an empty queue"<<endl;
    }
}

template <class Type>
queueType<Type>:: queueType(int queueSize) {
    if (queueSize <= 0) {
        cout<<"Size of the array must be a positive number"<<endl;
        cout<<"Creating a default array of size 100"<<endl;
        maxQueueSize = 100;
    }
    else {
        maxQueueSize = queueSize;
    }
    
    queueFront = 0;
    queueRear = maxQueueSize - 1;
    count = 0;
    list = new Type[maxQueueSize];
}

template <class Type>
queueType<Type>:: queueType(const queueType<Type>& otherQueue) {
    maxQueueSize = otherQueue.maxQueueSize;
    queueFront = otherQueue.queueFront;
    queueRear = otherQueue.queueRear;
    count = otherQueue.count;

    list = new Type[maxQueueSize];
    assert(list != NULL);

    // Copy elements from otherQueue to this queue, taking wrap-around into account
    if (count > 0) {
        int otherIndex = otherQueue.queueFront;
        for (int i = 0; i < count; i++) {
            list[i] = otherQueue.list[otherIndex];
            otherIndex = (otherIndex + 1) % maxQueueSize;
        }
    }
}

template <class Type>
queueType<Type>:: ~queueType(){
    delete [] list;
}
