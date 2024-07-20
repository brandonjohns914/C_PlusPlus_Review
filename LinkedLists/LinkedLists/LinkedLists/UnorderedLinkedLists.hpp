//
//  UnorderedLinkedLists.hpp
//  LinkedLists
//
//  Created by Brandon Johns on 7/10/24.
//

#ifndef UnorderedLinkedLists_hpp
#define UnorderedLinkedLists_hpp

#include <stdio.h>
#include <iostream>
#include "LinkedListIterator.hpp"
#include "LinkedListType.hpp"
#include <cassert>
using namespace std;

template<class Type>
class unorderedLinkedList: public linkedListType<Type> {
public:
    bool search(const Type& item) const;
    
    void insertFirst(const Type& item);
    
    void insertLast(const Type& item);
    
    void deleteNode(const Type& deleteItem);
    
    void linkInsertionSort();
    
protected:
    int count;
    
    nodeType<Type> *first;
    nodeType<Type> *last;
};


#endif /* UnorderedLinkedLists_hpp */

template<class Type>
bool unorderedLinkedList<Type>::search(const Type& item) const {
    nodeType<Type>* current = first; // Start at the first node
    bool found = false; // Initialize found as false

    while (current != NULL && !found) {
        if (current->info == item) {
            found = true; // Item found
        } else {
            current = current->link; // Move to the next node
        }
    }

    return found; // Return whether the item was found
}



template<class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& item) {
    // Create a new node
    nodeType<Type>* newNode = new nodeType<Type>;
    newNode->info = item;
    newNode->link = first; // Link the new node to the first node

    first = newNode; // Update the first pointer to point to the new node
    count++; // Increment the count of nodes

    if (last == NULL) {
        // If the list was empty, set last to the new node
        last = newNode;
    }
}

template<class Type>
void unorderedLinkedList<Type>::insertLast(const Type& item) {
    // Create a new node
    nodeType<Type>* newNode = new nodeType<Type>;
    newNode->info = item;
    newNode->link = NULL;

    if (first == NULL) {
        // List is empty, new node is both the first and the last node
        first = newNode;
        last = newNode;
    } else {
        // Append new node to the end of the list
        last->link = newNode;
        last = newNode;
    }

    // Increment the count of nodes
    count++;
}

template<class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem) {
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    bool found;

    if (first == NULL) {
        // The list is empty, nothing to delete
        cout << "Cannot delete from an empty list" << endl;
    } else {
        // Check if the first node is the node to be deleted
        if (first->info == deleteItem) {
            current = first;
            first = first->link;
            count--;

            if (first == NULL) {
                // List becomes empty after deletion
                last = NULL;
            }

            delete current;
        } else {
            // Initialize the pointers
            found = false;
            trailCurrent = first;
            current = first->link;

            // Traverse the list to find the node to be deleted
            while (current != NULL && !found) {
                if (current->info != deleteItem) {
                    trailCurrent = current;
                    current = current->link;
                } else {
                    found = true;
                }
            }

            if (found) {
                // Node found and will be deleted
                trailCurrent->link = current->link;
                count--;

                if (last == current) {
                    // Update last if the last node is being deleted
                    last = trailCurrent;
                }
                delete current;
            } else {
                // Node to be deleted was not found
                cout << "Item not found in the list." << endl;
            }
        }
    }
}


template<class Type>
void unorderedLinkedList<Type>:: linkInsertionSort() {
    nodeType<Type> *lastInOrder;
    nodeType<Type> *firstOutOfOrder;
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    
    lastInOrder = first;
    if(first == NULL){
        cerr<< "Cannot sorrt an empty list"<<endl;
    }
    else if (first->link == NULL){
        cout<<"The list of length 1 is already in order"<<endl;
    }
    else {
        while(lastInOrder-> link != NULL){
            firstOutOfOrder = lastInOrder->link;
            
            if(firstOutOfOrder-> info < first-> info){
                lastInOrder-> link = firstOutOfOrder->link;
                firstOutOfOrder->link = first;
                first = firstOutOfOrder;
            }
            else {
                trailCurrent = first;
                current = first->link;
                
                while(current->info < firstOutOfOrder->info){
                    trailCurrent = current;
                    current = current->link;
                }
                
                if(current != firstOutOfOrder) {
                    lastInOrder->link = firstOutOfOrder->link;
                    firstOutOfOrder->link = current;
                    trailCurrent->link = firstOutOfOrder;
                }
                else {
                    lastInOrder = lastInOrder->link;
                }
            }
        }
    }
}
