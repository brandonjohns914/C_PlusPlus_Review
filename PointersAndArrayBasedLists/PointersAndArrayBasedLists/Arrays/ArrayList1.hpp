//
//  ArrayList1.hpp
//  PointersAndArrayBasedLists
//
//  Created by Brandon Johns on 7/7/24.
//

#ifndef ArrayList1_hpp
#define ArrayList1_hpp

#include <cassert>
#include <stdio.h>
#include <iostream>
using namespace std;

template <class arrayType> 
class ArrayListType1 {
public:
    ArrayListType1<arrayType>();
    ~ArrayListType1<arrayType>();
    
    bool isEmpty();
    bool isFull();
    int listSize();
    int maxListSize();
    void print();
    void clearList();
    bool isItemAtEqual(int location, arrayType& item);
    void insertAt(int location, arrayType& insertItem);
    void insertEnd(arrayType& insertItem);
    void removeAt(int location);
    void retrieveAt(int location, arrayType& retrieveItem);
    void replaceAt(int locaiton, arrayType& replaceItem);
    
    int sequentialSearch(arrayType& item);
    void insert(arrayType& insertItem);
    void remove(arrayType& removeItem);
    
    ArrayListType1<arrayType>& operator= (ArrayListType1<arrayType>& otherList);
    ArrayListType1<arrayType>(ArrayListType1<arrayType>& otherList);
    
    

protected:
    int length;
    int maxSize;
    arrayType * list;
};
#endif /* ArrayList1_hpp */

template<class arrayType>
ArrayListType1<arrayType>:: ArrayListType1() {
    length = 0;
    maxSize = 100;
    list = new arrayType[maxSize];
}

template<class arrayType>
ArrayListType1<arrayType>:: ~ArrayListType1() {
    delete [] list;
}

template <class arrayType>
bool ArrayListType1<arrayType>:: isEmpty() {
    return length == 0;
}

template <class arrayType>
bool ArrayListType1<arrayType>:: isFull() {
    return length == maxSize; 
}

template <class arrayType>
int ArrayListType1<arrayType>:: listSize() {
    return length;
}

template <class arrayType>
int ArrayListType1<arrayType>:: maxListSize() {
    return maxSize;
}

template<class arrayType>
void ArrayListType1<arrayType>:: clearList() {
    length =0;
    
}

template<class arrayType>
void ArrayListType1<arrayType>:: print() {
    for(int i =0; i< length; i++) {
        cout<< list[i] << " " <<endl;
    }
}

template<class arrayType>
bool ArrayListType1<arrayType>:: isItemAtEqual(int location, arrayType& item) {
    return (list[location] == item);
}

template<class arrayType>
void ArrayListType1<arrayType>:: insertAt(int location, arrayType& insertItem) {
    if (location < 0 || location >= maxSize) {
        cout<<"items location is out of range" <<endl;
    }
    else {
        if(length >= maxSize) {
            cout<<"cannot insert into a full list" <<endl;
        }
        else {
            for(int i = length; i > location; i--){
                list[i] = list[i - 1];
            }
            list[location] = insertItem;
            length++;
        }
    }
}

template<class arrayType>
void ArrayListType1<arrayType>:: insertEnd(arrayType &insertItem) {
    if (length >= maxSize) {
        cout<<"List is full cannot add any more items" <<endl;
    }
    else {
        list[length] = insertItem;
        length++;
    }
}

template<class arrayType>
void ArrayListType1<arrayType>:: removeAt(int location) {
    if (location < 0 || location >= maxSize) {
        cout<<"Location of item is out range" <<endl;
    }
    else {
        for(int i = location; i < length - 1; i++) {
            list[i] = list[i+1];
        }
        length--; 
    }
}


template<class arrayType>
void ArrayListType1<arrayType>:: retrieveAt(int location, arrayType& retrieveItem) {
    if (location < 0 || location >= length) {
        cout<<"The location of the item is out of range";
    }
    else{
        retrieveItem = list[location];
    }
}

template<class arrayType>
void ArrayListType1<arrayType>:: replaceAt(int locaiton, arrayType& replaceItem) {
    if (location < 0 || location >= length) {
        cout<<"The location of the item is out of range.";
    }
    else {
        list[location] = replaceItem;
    }
}


template<class arrayType>
int ArrayListType1<arrayType>:: sequentialSearch(arrayType& item) {
    int location;
    bool found = false;
    
    for(location = 0; location< length; location++) {
        if (list[location] == item) {
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

template<class arrayType>
void ArrayListType1<arrayType>:: insert(arrayType& insertItem){
    int location;
    if(length == 0){
        list[length++] = insertItem;
    }
    else if (length == maxSize){
        cout<<"List is full cannot insert new item";
    }
    else {
        location = sequentialSearch(insertItem);
        if (location == -1) {
            list[length++];
        }
        else {
            cout<<"Item is already int he list no duplicates allowed";
        }
    }
}

template<class arrayType>
void ArrayListType1<arrayType>:: remove(arrayType& removeItem){
    int location;
    
    if (length==0){
        cout<<"cannot delete from a empty list";
    }
    else {
        location = sequentialSearch(removeItem);
        
        if(location != -1) {
            removeAt(location);
        }
        else {
            cout<< "The item to be deleted is not in the list"; 
        }
    }
}

template<class arrayType>
ArrayListType1<arrayType>&  ArrayListType1<arrayType>:: operator= (ArrayListType1<arrayType>& otherList) {
    if(this != &otherList) {
        delete [] list;
        maxSize = otherList.maxSize;
        list = new arrayType[maxSize];
        assert( list != NULL);
        
        for(int i = 0; i< length; i++) {
            list[i] = otherList.list[i];
        }
    }
    return *this;
}

template<class arrayType>
ArrayListType1<arrayType>:: ArrayListType1<arrayType>(ArrayListType1<arrayType>& otherList){
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new arrayType[maxSize];
    
    assert(list != NULL);
    
    for(int i = 0; i < length; i++ ){
        list[i] = otherList.list[i];
    }
    
}



