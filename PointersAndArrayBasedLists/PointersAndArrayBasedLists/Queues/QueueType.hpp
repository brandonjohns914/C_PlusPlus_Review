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
