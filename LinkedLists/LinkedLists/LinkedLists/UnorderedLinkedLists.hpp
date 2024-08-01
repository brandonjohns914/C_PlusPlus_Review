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
    
    void divideList(nodeType<Type> *first1, nodeType<Type> *&first2);
    
    nodeType<Type> * mergeList(nodeType<Type> *first1, nodeType<Type> *first2);
    
    void recursiveMergeSort(nodeType<Type>* &head);
    void mergeSort();
    
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

template <class Type>
void unorderedLinkedList<Type>:: divideList(nodeType<Type> *first1, nodeType<Type> *&first2){
    nodeType<Type> *middle;
    nodeType<Type> *current;
    
    if(first1 == NULL){
        first2 = NULL;
    }
    else if(first1->link == NULL){
        first2 = NULL;
    }
    else {
        middle = first1;
        current = first1->link;
        
        if(current != NULL){
            current = current->link;
        }
        while(current != NULL) {
            middle = middle->link;
            current = current->link;
            if(current != NULL){
                current = current->link;
            }
        }
        
        first2 = middle->link;
        middle->link = NULL;
    }
}

template <class Type>
nodeType<Type>* unorderedLinkedList<Type>:: mergeList(nodeType<Type> *first1, nodeType<Type> *first2) {
    nodeType<Type> *lastSmall;
    nodeType<Type> *newHead;
    
    if (first1 == NULL){
        return first2;
    }
    else if(first2 == NULL){
        return first1;
    }
    else {
        if (first1->info < first2->info){
            newHead = first1;
            first1= first1->link;
            lastSmall = newHead;
        }
        else {
            newHead = first2;
            first2 = first2->link;
            lastSmall = newHead;
        }
        
        while(first1 != NULL && first2 != NULL){
            
            if (first1->info < first2->info){
                lastSmall->link = first1;
                lastSmall = lastSmall->link;
                first1 = first1->link;
            }
            else {
                lastSmall->link = first2;
                lastSmall = lastSmall->link;
                first2 = first2->link;
            }
        }
        
        if(first1==NULL){
            lastSmall->link = first2;
        }
        else {
            lastSmall->link = first1;
        }
        return newHead;
    }
}

template <class Type>
void unorderedLinkedList<Type>:: recursiveMergeSort(nodeType<Type>* &head){
    nodeType<Type> *otherHead;
    if(head!= NULL) {
        if(head->link != NULL){
            divideList(head, otherHead);
            recursiveMergeSort(head);
            recursiveMergeSort(otherHead);
            head = mergeList(head, otherHead);
        }
    }
}

template <class Type>
void unorderedLinkedList<Type>:: mergeSort(){
    recursiveMergeSort(first);
    if(first == NULL) {
        last = NULL;
    }
    else {
        last = first;
        while(last->link != NULL){
            last = last->link;
        }
    }
}
