//
//  main.cpp
//  PointersAndArrayBasedLists
//
//  Created by Brandon Johns on 7/7/24.
//

#include "ArrayList.hpp"
#include <stdio.h>
#include <iostream>
#include<array>
#include<string>
#include<cassert>
#include "StackType.hpp"
using namespace std;

void arrayListExample();
void largestExample();
int largest(const int list[], int lowerIndex, int upperIndex);
void StackExample();
void testCopyConstructor(stackType<int> otherStack);
int main() {
    arrayListExample(); 
    //largestExample();
    
    return 0;
}

void arrayListExample() {
    int size = 100;
    ArrayListType<int> intList(size);
    ArrayListType<string> stringList(size);
    
    int number;
    cout << "Enter 5 integers: ";
    for (int counter = 0; counter < 5; counter++){
        cin >> number;
        intList.insertAt(counter, number);
    }

    cout << endl;
    cout << "The list you entered is: ";
    intList.print();
    cout << endl;
    cout << "Enter the item to be deleted: " ;
    cin >> number;
    intList.remove(number);
    
    cout << "After removing " << number << ", the list is:" << endl;
    intList.print();
    cout << endl;
    
    string str;
    cout << "Enter 5 strings: ";
    for (int counter = 0; counter < 5; counter++)
    {
        cin >> str ;
        stringList.insertAt(counter, str);
    }
    cout << endl;
    cout << "The list you entered is: " << endl;
    stringList.print();
    cout << endl;
    cout << "Enter the item to be deleted: " ;
    cin >> str;
    stringList.remove(str);
    cout << "After removing " << str << ", the list is:" << endl;

    stringList.print();
    cout << endl;
}


void largestExample() {
    int intArray[10] = {23, 43, 35,38,67,12,76,10,34, 8};
    
    cout<< "The largest number in the array: "<< largest(intArray, 0, 9)<<endl;
}

int largest(const int list[], int lowerIndex, int upperIndex){
    int max;
    
    if (lowerIndex == upperIndex) {
        return list[lowerIndex];
    }
    else {
        max = largest(list, lowerIndex + 1, upperIndex);
        
        if(list[lowerIndex] >= max) {
            return list[lowerIndex];
        }
        else {
            return max;
        }
    }
}

void StackExample(){
    stackType<int> stack(50);
    stackType<int> copyStack(50);
    stackType<int> dummyStack(500);
    
    stack.initializeStack();
    stack.push(23);
    stack.push(30);
    stack.push(11);
    copyStack = stack;
    
    cout<<"Stack: "<<endl;
    
    while(!copyStack.isEmptyStack()){
        cout<< copyStack.top() << " ";
        copyStack.pop();
    }
    cout<<endl;
    
    testCopyConstructor(stack);
    
    if(!stack.isEmptyStack()){
        cout<<"The original stack is not empty"<<endl;
        cout<<"the top element of the original stack: "<< copyStack.top() <<endl;
    }
    dummyStack = stack;
    
    cout<<"Elements of dummy stack: "<<endl;
    
    while(!dummyStack.isEmptyStack()){
        cout<< dummyStack.top() << " " <<endl;
        dummyStack.pop();
    }
    cout<<endl;
    
}

void testCopyConstructor(stackType<int> otherStack){
    if(!otherStack.isEmptyStack()){
        cout<<"The original stack is not empty"<<endl;
        cout<<"the top element of the original stack: "<< otherStack.top() <<endl;
    }
}
