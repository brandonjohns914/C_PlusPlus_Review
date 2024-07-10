//
//  main.cpp
//  LinkedLists
//
//  Created by Brandon Johns on 7/9/24.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

/*
 nodeType* buildListForward()
{
     nodeType *first, *last, *newNode;
     int num;
     
     cout<<"Enter a number"<<endl;
     cin >> num;
     first = NULL;
     
     while (num  != -999) {
         newNode = new nodeType;
         newNode -> info = num;
         newNode->link = NULL;
         
         if(first == NULL) {
             first = newNode;
             last = newNode;
         }
         else {
             last -> link = newNode;
             last = newNode;
         }
         cin>> num;
     }
 }
 
 nodeType* buildListBackward()
{
     nodeType *first, *newNode;
     int num;
     
     cout<<"Enter a number"<<endl;
     cin >> num;
     first = NULL;
     
     while (num  != -999) {
         newNode = new nodeType;
         newNode -> info = num;
         newNode->link = first;
         
         first = newNode;
         cin>> num;
     }
 }
 */
