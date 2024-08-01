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
    void swapSelectionSort(int first, int second);
    void selectionSort();
    
    // insertionsort
    void insertionSort();
    
    //shellsort
    void intervalInsertionSort(int begin, int increment);
    void shellSort();

    //quicksort
    void swapQuickSort(int first, int second);
    int partition(int first, int last);
    void recursiveQuickSort(int first, int last);
    void quickSort();
    
    
    //heap
    void heapify(int low, int high);
    void buildHeap();
    void heapSort();
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
void arrayListType<Type>:: swapSelectionSort(int first, int second) {
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

template<class Type>
void arrayListType<Type>:: intervalInsertionSort(int begin, int increment){
    int i;
    int j;
    Type temp;
    for( i = begin + increment; i < length; i += increment) {
        temp = list[i];
        
        for(j = i; j>= increment && list[j - increment]> temp; j -= increment){
            list[j] = list[j - increment];
        }
        
        list[j] = temp;
    }
}

template<class Type>
void arrayListType<Type>:: shellSort() {
    int increment;
    for(increment = 1; increment < (length -1) / 9; increment = 3 * increment + 1);
    
    do {
        for(int begin = 0; begin < increment; begin++) {
            intervalInsertionSort(begin, increment);
        }
        increment = increment / 3;
    } while(increment > 0);
}

template<class Type>
void arrayListType<Type>:: swapQuickSort(int first, int second) {
    Type temp;
    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
}

template<class Type>
int arrayListType<Type>:: partition(int first, int last){
    Type pivot;
    int index;
    int smallIndex;
    
    swapQuickSort(first, (first + last) / 2);
    pivot = list[first];
    smallIndex = first;
    
    for (index = first + 1; index <= last; index++) {
        if(list[index]< pivot) {
            smallIndex++;
            swapQuickSort(smallIndex, index);
        }
    }
    swapQuickSort(first, smallIndex);
    return smallIndex;
}

template<class Type>
void arrayListType<Type>:: recursiveQuickSort(int first, int last) {
    int pivotLocation;
    
    if(first < last) {
        pivotLocation = partition(first, last);
        recursiveQuickSort(first, pivotLocation - 1);
        recursiveQuickSort(pivotLocation + 1, last);
    }
}

template<class Type>
void arrayListType<Type>::  quickSort() {
    recursiveQuickSort(0, length -1);
}

template<class Type>
void arrayListType<Type>:: heapify(int low, int high) {
    int largeIndex;
    Type temp = list[low];
    largeIndex = 2 * low + 1;
    while(largeIndex <= high) {
        if (largeIndex < high) {
            if (list[largeIndex] < list[largeIndex + 1]){
                largeIndex = largeIndex + 1;
            }
        }
        if(temp > list[largeIndex]){
            break;
        }
        else {
            list[low] = list[largeIndex];
            low = largeIndex;
            largeIndex = 2 * low + 1;
        }
    }
    list[low] = temp;
}

template <class Type>
void arrayListType<Type>:: buildHeap() {
    for(int index = length / 2 - 1; index >= 0; index--){
        heapify(index, length -1);
    }
}

template <class Type>
void arrayListType<Type>:: heapSort() {
    Type temp;
    buildHeap();
    
    for(int lastOutOfOrder = length -1; lastOutOfOrder >= 0; lastOutOfOrder--) {
        temp = list[lastOutOfOrder];
        list[lastOutOfOrder] = list[0];
        list[0] = temp;
        heapify(0, lastOutOfOrder - 1);
    }
}
