//
//  ArrayList.hpp
//  PointersAndArrayBasedLists
//
//  Created by Brandon Johns on 7/7/24.
//

#ifndef ArrayList_hpp
#define ArrayList_hpp

#include<stdio.h>
#include<array>
#include <iostream>
#include<string>
#include <cassert>

using namespace std;

template <class Type>
class ArrayListType {
    
protected:
    Type *list;
    int length;
    int maxSize;
    
    
    
public:
    // constructor
    ArrayListType(int size = 100);
    
    // copy constructor
    ArrayListType(const ArrayListType<Type>& otherList);
    
    //destructor
    ~ArrayListType();
    
    //overloading assignment operator and const does not change the objects members
    const ArrayListType<Type> & operator= (const ArrayListType<Type>& otherList);
    
    // if true list is empty
    bool isEmpty() const;
    
    // if full returns true
    bool isFull() const;
    
    // determines the number of elements in the list
    int listSize() const;
    
    //determines the max size of the list
    int maxListSize() const;
    
    //prints the list
    void print() const;
    
    //returns true if the item is equal at the location
    bool isItemAtEqual(int location, const Type& item) const;
    
    // inserts an item at a specific location
    void insertAt(int location, const Type& insertItem);
    
    // inserts item at the end of the array
    void insertEnd(const Type& insertItem);
    
    // removes item at that location
    void removeAt(int location);
    
    // retrieves an item at the location
    void retrieveAt(int location, Type& retrieveItem) const;
    
    // replaces item at specific location
    void replaceAt(int location, const Type& replaceItem);
    
    // removes all items in the list
    void clearList();
    
    //searches for an item and returns its location
    int sequentialSearch(const Type& item) const;
        
    // removes specific item from the list
    void remove(const Type& removeItem);
    
    // inserts item in the list
    void insert(const Type& instertItem);
    

};

#endif /* ArrayList_hpp */


template<class Type>
ArrayListType<Type>:: ArrayListType(int size)
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
ArrayListType<Type>:: ArrayListType(const ArrayListType<Type> & otherList){
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new Type[maxSize];
    assert(list!= NULL);
    
    for (int i = 0; i< length; i++) {
        list[i] = otherList.list[i];
    }
}

template<class Type>
ArrayListType<Type>:: ~ArrayListType(){
    delete [] list;
}

template<class Type>
const ArrayListType<Type> & ArrayListType<Type>:: operator= (const ArrayListType<Type>& otherList) {
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
bool ArrayListType<Type>:: isEmpty() const
{
    return(length == 0);
}

template<class Type>
bool ArrayListType<Type>:: isFull() const {
    return(length == maxSize);
}

template<class Type>
int ArrayListType<Type>:: listSize() const{
    return length;
}

template<class Type>
int ArrayListType<Type>:: maxListSize() const{
    return maxSize;
}

template<class Type>
void ArrayListType<Type>:: print() const {
    for (int i = 0; i <length; i++) {
        cout<< list[i] << " " <<endl;
    }
}

template<class Type>
bool ArrayListType<Type>:: isItemAtEqual(int location, const Type& item) const{
    return(list[location] == item);
}

template<class Type>
void ArrayListType<Type>:: insertAt(int location, const Type& insertItem) {
    if(location < 0 || location >= maxSize) {
        cerr<< "Position is out of range"<<endl;
    }
    else {
        if (length >= maxSize) {
            cerr<< "List is full"<<endl;
        }
        else {
            for(int i = 0; i > location; i--) {
                list[i] = list[i-1];
                
            }
            list[location] = insertItem;
            length++;
        }
    }
}

template<class Type>
void ArrayListType<Type>:: insertEnd(const Type& insertItem) {
    if (length >= maxSize) {
        cerr << "List is full" <<endl;
    }
    else {
        list[length] == insertItem;
        length++;
    }
}

template<class Type>
void ArrayListType<Type>:: removeAt(int location) {
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
void ArrayListType<Type>:: retrieveAt(int location, Type& retrieveItem) const {
    if(location < 0 || location >= length) {
        cerr<<"Item is out range" << endl;
    }
    else {
        retrieveItem = list[location];
    }
}

template<class Type>
void ArrayListType<Type>:: replaceAt(int location, const Type& replaceItem) {
    if(location < 0 || location >= length) {
        cerr<<"Item is out range" << endl;
    }
    else {
        list[location] = replaceItem;
    }
}

template<class Type>
void ArrayListType<Type>:: clearList() {
    length = 0;
}

template<class Type>
int ArrayListType<Type>:: sequentialSearch(const Type& item) const {
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
void ArrayListType<Type>:: remove(const Type& removeItem) {
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
void ArrayListType<Type>:: insert(const Type& instertItem) {
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
