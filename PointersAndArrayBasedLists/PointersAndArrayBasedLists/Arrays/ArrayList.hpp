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
class arrayListType {
    
protected:
    Type *list;
    int length;
    int maxSize;
    
    
    
public:
    // constructor
    arrayListType(int size = 100);
    
    // copy constructor
    arrayListType(const arrayListType<Type>& otherList);
    
    //destructor
    ~arrayListType();
    
    //overloading assignment operator and const does not change the objects members
    const arrayListType<Type> & operator= (const arrayListType<Type>& otherList);
    
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
    
    // inserts item in the list
    void insert(const Type& instertItem);
    
    // inserts an item at a specific location
    void insertAt(int location, const Type& insertItem);
    
    // inserts item at the end of the array
    void insertEnd(const Type& insertItem);
    
    // removes item at that location
    void removeAt(int location);
    
    // removes specific item from the list
    void remove(const Type& removeItem);
    
    // retrieves an item at the location
    void retrieveAt(int location, Type& retrieveItem) const;
    
    // replaces item at specific location
    void replaceAt(int location, const Type& replaceItem);
    
    // removes all items in the list
    void clearList();
    
    //searches for an item and returns its location
    int sequentialSearch(const Type& item) const;
    
    // selection sort
    int minLocation(int first, int last);
    void swap(int first, int second);
    void selectionSort();
    
    // insertionsort
    void insertionSort();

};

#endif /* ArrayList_hpp */


//template<class Type>
//ArrayListType<Type>::ArrayListType() {
//    maxSize = 100;
//    list = new Type[maxSize];
//    length = 0;
//}


template<class Type>
arrayListType<Type>:: arrayListType(int size)
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
arrayListType<Type>:: arrayListType(const arrayListType<Type> & otherList){
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new Type[maxSize];
    assert(list!= NULL);
   
    for (int i = 0; i< length; i++) {
        list[i] = otherList.list[i];
    }
}

template<class Type>
arrayListType<Type>:: ~arrayListType(){
    delete [] list;
}

template<class Type>
const arrayListType<Type> & arrayListType<Type>:: operator= (const arrayListType<Type>& otherList) {
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
bool arrayListType<Type>:: isEmpty() const
{
    return(length == 0);
}

template<class Type>
bool arrayListType<Type>:: isFull() const {
    return(length == maxSize);
}

template<class Type>
int arrayListType<Type>:: listSize() const{
    return length;
}

template<class Type>
int arrayListType<Type>:: maxListSize() const{
    return maxSize;
}

template<class Type>
void arrayListType<Type>:: print() const {
    for (int i = 0; i <length; i++) {
        cout<< list[i] << " " <<endl;
    }
}

template<class Type>
bool arrayListType<Type>:: isItemAtEqual(int location, const Type& item) const{
    return(list[location] == item);
}

template<class Type>
void arrayListType<Type>:: insertAt(int location, const Type& insertItem) {
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
void arrayListType<Type>:: insertEnd(const Type& insertItem) {
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
void arrayListType<Type>:: removeAt(int location) {
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
void arrayListType<Type>:: retrieveAt(int location, Type& retrieveItem) const {
    if(location < 0 || location >= length) {
        cerr<<"Item is out range" << endl;
    }
    else {
        retrieveItem = list[location];
    }
}

template<class Type>
void arrayListType<Type>:: replaceAt(int location, const Type& replaceItem) {
    if(location < 0 || location >= length) {
        cerr<<"Item is out range" << endl;
    }
    else {
        list[location] = replaceItem;
    }
}

template<class Type>
void arrayListType<Type>:: clearList() {
    length = 0;
}

template<class Type>
int arrayListType<Type>:: sequentialSearch(const Type& item) const {
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
void arrayListType<Type>:: remove(const Type& removeItem) {
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
void arrayListType<Type>:: insert(const Type& instertItem) {
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
int arrayListType<Type>:: minLocation(int first, int last){
    int minIndex;
    
    minIndex = first;
    
    for(int location = first + 1; location <= last; location++){
        if(list[location]< list[minIndex]){
            minIndex = location;
        }
    }
    
    return minIndex;
}

template<class Type>
void arrayListType<Type>:: swap(int first, int second) {
    Type temp;
    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
}
template<class Type>
void arrayListType<Type>:: selectionSort() {
    
    int minIndex;
    for(int location = 0; location< length - 1; location++){
        minIndex = minLocation(location, length -1);
        swap(location, minIndex);
    }
}

template<class Type>
void arrayListType<Type>:: insertionSort(){
    int firstOutOfOrder;
    int location;
    
    Type temp;
    
    for(firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++){
        if(list[firstOutOfOrder]< list[firstOutOfOrder - 1]){
            temp = list[firstOutOfOrder];
            location = firstOutOfOrder;
            
            do {
                list[location] = list[location - 1];
                location--;
            }
            while(location>0 && list[location - 1] > temp);
            
            list[location] = temp;
        }
    }
}
