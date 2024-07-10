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
using namespace std;

void arrayListExample();

int main() {
    arrayListExample(); 
    
    
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
