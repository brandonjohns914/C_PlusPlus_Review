//
//  OrderedLinkedLists.hpp
//  LinkedLists
//
//  Created by Brandon Johns on 7/10/24.
//

#ifndef OrderedLinkedLists_hpp
#define OrderedLinkedLists_hpp

#include <stdio.h>
#include <iostream>
#include "LinkedListIterator.hpp"
#include "LinkedListType.hpp"
#include <cassert>
using namespace std;

template <class Type>
class orderedLinkedList: public linkedListType<Type> {
public:
    bool search(const Type& item) const;
    void insert(const Type& item);
    void insertFirst(const Type& item);
    void insertLast(const Type& item);
    void deleteNode(const Type& item);
    
    
protected:
    int count;
    nodeType<Type> *first;
    nodeType<Type> *last;
};

#endif /* OrderedLinkedLists_hpp */


template <class Type>
bool orderedLinkedList<Type>:: search(const Type& item) const {
    bool found = false;
    
    nodeType<Type> *current; // traverse the list
    
    current = first; // start the search at the first node
    
    while(current != NULL && !found) {
        if(current-> info >= item){
            found = true;
        }
        else {
            current = current->link;
        }
    }
    
    if (found){
        found = (current->info == item);
    }
    return found;
}
template <class Type>
void orderedLinkedList<Type>:: insert(const Type& item){
    nodeType<Type> * current; // pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    nodeType<Type> *newNode;
    bool found;
    
    newNode = new nodeType<Type>; // create the node
    
    newNode->info = item; // store item int he node
    newNode->link = NULL;
    
    if (first == NULL) { // the list is empty so the new node becomes the first node
        first = newNode;
        last = newNode;
        count++;
    }
    
    else {
        current = first;
        found = false;
        
        while(current != NULL && !found) { // search the list
            if (current-> info >= item){
                found = true;
            }
            else {
                trailCurrent = current;
                current = current->link;
            }
        }
        // new item is smaller than the smallest item so goes in the beginning of the list
        if(current == first ) {
            newNode->link = first;
            first = newNode;
            count++;
        }
        
        // if the item is larger than largest item goes to end of the list
        // if the item is in the middle change where the item where be inserted between current and trailcurrent
        else {
            trailCurrent->link = newNode;
            newNode->link = current;
            
            if (current == NULL){
                last = newNode;
            }
            
            count++;
        }
    }
}
template<class Type>
void orderedLinkedList<Type>::deleteNode(const Type& item) {
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent = nullptr;
    bool found;

    if (first == NULL) {
        // List is empty
        cout << "Cannot delete from an empty list" << endl;
        return;
    }

    current = first;
    found = false;

    // Traverse the list to find the node to delete
    while (current != NULL && !found) {
        if (current->info >= item) {
            found = true;
        } else {
            trailCurrent = current;
            current = current->link;
        }
    }

    if (current == NULL) {
        // Node to delete is not found
        cout << "Item is not in the list" << endl;
    } else {
        if (current->info == item) {
            if (first == current) {
                // Node to delete is the first node
                first = first->link;
                if (first == NULL) {
                    // List becomes empty after deletion
                    last = NULL;
                }
            } else {
                // Node to delete is in the middle or end
                trailCurrent->link = current->link;
                if (current == last) {
                    // Node to delete is the last node
                    last = trailCurrent;
                }
            }
            // Delete the node and decrement the count
            delete current;
            count--;
        } else {
            // Node to delete is not found
            cout << "Item is not in the list" << endl;
        }
    }
}


template <class Type>
void orderedLinkedList<Type>::  insertFirst(const Type& item){
    insert(item);
}

template <class Type>
void orderedLinkedList<Type>:: insertLast(const Type& item){
    insert(item);
}


