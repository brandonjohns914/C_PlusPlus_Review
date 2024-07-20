//
//  OrderedArrayListType.hpp
//  PointersAndArrayBasedLists
//
//  Created by Brandon Johns on 7/17/24.
//

#ifndef OrderedArrayListType_hpp
#define OrderedArrayListType_hpp

#include<stdio.h>
#include<array>
#include <iostream>
#include<string>
#include <cassert>
#include "ArrayList.hpp"

template <class Type>
class orderedArrayListType: public arrayListType<Type> {
public:
  
protected:
    Type *list;
    int length;
    int maxSize;
    
    
    
public:
    orderedArrayListType(int size = 100);
    orderedArrayListType(const orderedArrayListType<Type>& otherList);
    ~orderedArrayListType();
    
    const orderedArrayListType<Type> & operator= (const orderedArrayListType<Type>& otherList);
    
 
    bool isEmpty() const;
    bool isFull() const;
    bool isItemAtEqual(int location, const Type& item) const;
    
    
    int listSize() const;
    int maxListSize() const;
    
    void print() const;
    
    // retrieves
    void retrieveAt(int location, Type& retrieveItem) const;
    
    // replaces
    void replaceAt(int location, const Type& replaceItem);
    
    // removes all
    void clearList();
        
    // remove
    void remove(const Type& removeItem);
    void removeAt(int location);
    
    // insert
    void insert(const Type& instertItem);
    void insertAt(int location, const Type& insertItem);
    void insertEnd(const Type& insertItem);
    void insertOrdered(const Type& insertItem);
    
    //search
    int sequentialSearch(const Type& item) const;
    int binarySearch(const Type& item) const;
    

private:
    
};

#endif /* OrderedArrayListType_hpp */



template<class Type>
orderedArrayListType<Type>:: orderedArrayListType(int size)
{
    if (size <0) {
        cerr << "Size must be a positive number" <<endl;
        cerr<<"Creating default size of 100"<<endl;
        maxSize = 100;
    }
    else {
        maxSize = size;
    }
   
    length = 0;
    list = new Type[maxSize];
   
    assert(list != NULL);
}


template<class Type>
orderedArrayListType<Type>:: orderedArrayListType(const orderedArrayListType<Type> & otherList){
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new Type[maxSize];
    assert(list!= NULL);
   
    for (int i = 0; i< length; i++) {
        list[i] = otherList.list[i];
    }
}

template<class Type>
orderedArrayListType<Type>:: ~orderedArrayListType(){
    delete [] list;
}

template<class Type>
const orderedArrayListType<Type> & orderedArrayListType<Type>:: operator= (const orderedArrayListType<Type>& otherList) {
    if (this != &otherList) {
        delete [] list;
        maxSize = otherList.maxSize;
        length = otherList.maxSize;
        list = new Type[maxSize];
        assert(list != NULL);
       
        for(int i = 0; i < length; i++) {
            list[i] = otherList.list[i];
        }
    }
    return *this;
}


template<class Type>
bool orderedArrayListType<Type>:: isEmpty() const
{
    return(length == 0);
}

template<class Type>
bool orderedArrayListType<Type>:: isFull() const {
    return(length == maxSize);
}

template<class Type>
bool orderedArrayListType<Type>:: isItemAtEqual(int location, const Type& item) const{
    return(list[location] == item);
}


template<class Type>
int orderedArrayListType<Type>:: listSize() const{
    return length;
}

template<class Type>
int orderedArrayListType<Type>:: maxListSize() const{
    return maxSize;
}

template<class Type>
void orderedArrayListType<Type>:: print() const {
    for (int i = 0; i <length; i++) {
        cout<< list[i] << " " <<endl;
    }
}

template<class Type>
void orderedArrayListType<Type>:: retrieveAt(int location, Type& retrieveItem) const {
    if(location < 0 || location >= length) {
        cerr<<"Item is out range" << endl;
    }
    else {
        retrieveItem = list[location];
    }
}

template<class Type>
void orderedArrayListType<Type>:: replaceAt(int location, const Type& replaceItem) {
    if(location < 0 || location >= length) {
        cerr<<"Item is out range" << endl;
    }
    else {
        list[location] = replaceItem;
    }
}

template<class Type>
void orderedArrayListType<Type>:: clearList() {
    length = 0;
}

   
template<class Type>
void orderedArrayListType<Type>:: remove(const Type& removeItem) {
    int location;
   
    if (length == 0) {
        cerr<<"cannot delete from an empty list"<<endl;
    }
    else {
        location = sequentialSearch(removeItem);
       
        if (location != -1){
            removeAt(location);
        }
        else {
            cout<<"Item is not in the list thus cannot be deleted"<<endl;
        }
    }
}

template<class Type>
void orderedArrayListType<Type>:: removeAt(int location) {
    if(location < 0 || location >= length) {
        cerr<<"Item is out range" << endl;
    }
    else {
        for(int i = location; i < length - 1; i++) {
            list[i] = list[i+1];
           
           
        }
        length--;
    }
}

template<class Type>
void orderedArrayListType<Type>:: insert(const Type& instertItem) {
    int location;
   
    if (length == 0) {
        list[length++] == instertItem;
    }
    else if (length == maxSize) {
        cerr<<"Cannot insert into a full list"<<endl;
    }
    else {
        location = sequentialSearch(instertItem);
       
        if (location == -1) {
            list[length++];
        }
        else {
            cerr << "No duplicate items. Item is already in the list"<< endl;
        }
    }
}

template<class Type>
void orderedArrayListType<Type>:: insertAt(int location, const Type& insertItem) {
    // location cannot be less than zero or larger than the maxsize
    if(location < 0 || location >= maxSize) {
        cerr<< "Position is out of range"<<endl;
    }
    else {
        // length cannot be larger than maxsize because that makes the list full
        if (length >= maxSize) {
            cerr<< "List is full"<<endl;
        }
        else {
            // setting the index to the length and the length must be greater than the location.
            // starting at the last item work down
            for(int i = length; i > location; i--) {
                list[i] = list[i-1];
               
            }
            // insert the item at the location
            list[location] = insertItem;
            
            //increase the size by the new item.
            length++;
        }
    }
}

template<class Type>
void orderedArrayListType<Type>:: insertEnd(const Type& insertItem) {
    // length cannot be larger than maxsize
    if (length >= maxSize) {
        cerr << "List is full" <<endl;
    }
    else {
        // at the last item in the array set that to the item
        list[length] == insertItem;
        // increase the the size by 1
        length++;
    }
}

template<class Type>
void orderedArrayListType<Type>:: insertOrdered(const Type& insertItem){
    int first = 0;
    int last = length - 1;
    int mid = (first + last ) / 2;
    bool found = false;
    
    if (length == 0){
        list[0] = insertItem;
        length++;
    }
    else if(length  == maxSize) {
        cerr<<"Cannot insert into a full list"<<endl;
    }
    else {
        while(first <= last && !found){
            if(list[mid] == insertItem){
                found = true;
            }
            else if(list[mid] > insertItem){
                last = mid - 1;
            }
            else {
                first = mid + 1;
            }
        }
        
        if(found){
            cerr<<"the insert item is already in the list no duplicates"<<endl;
        }
        else {
            if(list[mid] < insertItem){
                mid++;
            }
            insertAt(mid, insertItem);
        }
    }
}


template<class Type>
int orderedArrayListType<Type>:: sequentialSearch(const Type& item) const {
    int location;
    bool found = false;
    for (location = 0; location < length; location ++) {
        if(list[location] == item) {
            found = true;
            break;
        }
    }
    if(found) {
        return location;
    }
    else {
        return -1;
    }
}

template<class Type>
int orderedArrayListType<Type>:: binarySearch(const Type& item) const{
    int first = 0;
    int last = length -1;
    int mid = (first + last ) / 2;
    
    bool found = false;
    
    while(first <= last && !found) {
        if(list[mid] == item) {
            found = true;
        }
        else if(list[mid] > item) {
            last = mid -1;
        }
        else {
            first = mid + 1;
        }
    }
    
    if(found){
        return mid;
    }
    else {
        return -1;
    }
}
