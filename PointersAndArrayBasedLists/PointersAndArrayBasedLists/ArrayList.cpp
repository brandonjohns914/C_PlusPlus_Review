//
//  ArrayList.cpp
//  PointersAndArrayBasedLists
//
//  Created by Brandon Johns on 7/7/24.
//


#include<stdio.h>
#include<array>
#include <iostream>
#include<string>
#include <cassert>

#include "ArrayList.hpp"
using namespace std; 

//template<class Type>
//ArrayListType<Type>:: ArrayListType(int size)
//{
//    if (size <0) {
//        cerr << "Size must be a positive number" <<endl;
//        cerr<<"Creating default size of 100"<<endl;
//        maxSize = 100;
//    }
//    else {
//        maxSize = size;
//    }
//    
//    length = 0;
//    list = new Type[maxSize];
//    
//    assert(list != NULL);
//}
//
//
//template<class Type>
//ArrayListType<Type>:: ArrayListType(const ArrayListType<Type> & otherList){
//    maxSize = otherList.maxSize;
//    length = otherList.length;
//    list = new Type[maxSize];
//    assert(list!= NULL);
//    
//    for (int i = 0; i< length; i++) {
//        list[i] = otherList.list[i];
//    }
//}
//
//template<class Type>
//ArrayListType<Type>:: ~ArrayListType(){
//    delete [] list;
//}
//
//template<class Type>
//const ArrayListType<Type> & ArrayListType<Type>:: operator= (const ArrayListType<Type>& otherList) {
//    if (this != &otherList) {
//        delete [] list;
//        maxSize = otherList.maxSize;
//        length = otherList.maxSize;
//        list = new Type[maxSize];
//        assert(list != NULL);
//        
//        for(int i = 0; i < length; i++) {
//            list[i] = otherList.list[i];
//        }
//    }
//    return *this;
//}
//
//
//template<class Type>
//bool ArrayListType<Type>:: isEmpty() const
//{
//    return(length == 0);
//}
//
//template<class Type>
//bool ArrayListType<Type>:: isFull() const {
//    return(length == maxSize);
//}
//
//template<class Type>
//int ArrayListType<Type>:: listSize() const{
//    return length;
//}
//
//template<class Type>
//int ArrayListType<Type>:: maxListSize() const{
//    return maxSize;
//}
//
//template<class Type>
//void ArrayListType<Type>:: print() const {
//    for (int i = 0; i <length; i++) {
//        cout<< list[i] << " " <<endl;
//    }
//}
//
//template<class Type>
//bool ArrayListType<Type>:: isItemAtEqual(int location, const Type& item) const{
//    return(list[location] == item);
//}
//
//template<class Type>
//void ArrayListType<Type>:: insertAt(int location, const Type& insertItem) {
//    if(location < 0 || location >= maxSize) {
//        cerr<< "Position is out of range"<<endl;
//    }
//    else {
//        if (length >= maxSize) {
//            cerr<< "List is full"<<endl;
//        }
//        else {
//            for(int i = 0; i > location; i--) {
//                list[i] = list[i-1];
//                
//            }
//            list[location] = insertItem;
//            length++;
//        }
//    }
//}
//
//template<class Type>
//void ArrayListType<Type>:: insertEnd(const Type& insertItem) {
//    if (length >= maxSize) {
//        cerr << "List is full" <<endl;
//    }
//    else {
//        list[length] == insertItem;
//        length++;
//    }
//}
//
//template<class Type>
//void ArrayListType<Type>:: removeAt(int location) {
//    if(location < 0 || location >= length) {
//        cerr<<"Item is out range" << endl;
//    }
//    else {
//        for(int i = location; i < length - 1; i++) {
//            list[i] = list[i+1];
//            
//            
//        }
//        length--;
//    }
//}
//
//template<class Type>
//void ArrayListType<Type>:: retrieveAt(int location, Type& retrieveItem) const {
//    if(location < 0 || location >= length) {
//        cerr<<"Item is out range" << endl;
//    }
//    else {
//        retrieveItem = list[location];
//    }
//}
//
//template<class Type>
//void ArrayListType<Type>:: replaceAt(int location, const Type& replaceItem) {
//    if(location < 0 || location >= length) {
//        cerr<<"Item is out range" << endl;
//    }
//    else {
//        list[location] = replaceItem;
//    }
//}
//
//template<class Type>
//void ArrayListType<Type>:: clearList() {
//    length = 0;
//}
//
//template<class Type>
//int ArrayListType<Type>:: sequentialSearch(const Type& item) const {
//    int location;
//    bool found = false;
//    for (location = 0; location < length; location ++) {
//        if(list[location] == item) {
//            found = true;
//            break;
//        }
//    }
//    if(found) {
//        return location;
//    }
//    else {
//        return -1;
//    }
//}
//    
//template<class Type>
//void ArrayListType<Type>:: remove(const Type& removeItem) {
//    int location;
//    
//    if (length == 0) {
//        cerr<<"cannot delete from an empty list"<<endl;
//    }
//    else {
//        location = sequentialSearch(removeItem);
//        
//        if (location != -1){
//            removeAt(location);
//        }
//        else {
//            cout<<"Item is not in the list thus cannot be deleted"<<endl;
//        }
//    }
//}
//
//
//template<class Type>
//void ArrayListType<Type>:: insert(const Type& instertItem) {
//    int location;
//    
//    if (length == 0) {
//        list[length++] == instertItem;
//    }
//    else if (length == maxSize) {
//        cerr<<"Cannot insert into a full list"<<endl;
//    }
//    else {
//        location = sequentialSearch(instertItem);
//        
//        if (location == -1) {
//            list[length++];
//        }
//        else {
//            cerr << "No duplicate items. Item is already in the list"<< endl;
//        }
//    }
//}
