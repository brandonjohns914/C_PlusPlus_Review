//
//  QueueADT.hpp
//  PointersAndArrayBasedLists
//
//  Created by Brandon Johns on 7/17/24.
//

#ifndef QueueADT_hpp
#define QueueADT_hpp

#include <stdio.h>
#include <iostream>

template <class Type>
class queueADT {
public:
    virtual bool isEmptyQueue() const = 0;
    virtual bool isFullQueue() const = 0;
    
    virtual void initializeQueue() = 0;
    
    virtual Type front() const = 0;
    virtual Type back() const = 0;
    
    virtual void addQueue(const Type& item) = 0;
    virtual void deleteQueue() = 0; 
};

#endif /* QueueADT_hpp */
