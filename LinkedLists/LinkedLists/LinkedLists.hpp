//
//  LinkedLists.hpp
//  LinkedLists
//
//  Created by Brandon Johns on 7/9/24.
//

#ifndef LinkedLists_hpp
#define LinkedLists_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

template<class Type>
struct nodeType {
    Type info;
    nodeType<Type> *link;
};

template<class Type>
class linkedListIterator {
public:
    linkedListIterator();
    
    linkedListIterator(nodeType<Type> *ptr);
    
    Type operator*();
    
    linkedListIterator<Type> operator++();
    
    bool operator ==(const linkedListIterator<Type>& right) const;
    
    bool operator!= (const linkedListIterator<Type>& right) const;
    
private:
    nodeType<Type> *current;
};

 
#endif /* LinkedLists_hpp */


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
