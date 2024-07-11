//
//  DoublyLinkedList.hpp
//  DoublyLinkedLists
//
//  Created by Brandon Johns on 7/11/24.
//

#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp

#include <stdio.h>
#include <iostream>
#include <cassert>
using namespace std;

template<class Type>
struct nodeType {
    Type info;
    nodeType<Type> *next;
    nodeType<Type> *back;
};

template<class Type>
class doublyLinkedList{
public:
    
    doublyLinkedList();
    doublyLinkedList(const doublyLinkedList<Type>& otherList);
    ~doublyLinkedList();
   
    
    void initializeList();
    void destory();
    void print() const;
    void reversePrint() const;
    void insert(const Type& item);
    void deleteNode(const Type& item);
    bool search(const Type& item) const;
    bool isEmptyList() const;
    int length() const;
    Type front() const;
    Type back() const;
    const doublyLinkedList<Type> & operator = (const doublyLinkedList<Type> & otherList);
    
protected:
    int count;
    nodeType<Type> *first;
    nodeType<Type> *last;
    
private:
    void copyList(const doublyLinkedList<Type> & otherList);
};

#endif /* DoublyLinkedList_hpp */

template<class Type>
doublyLinkedList<Type>:: doublyLinkedList() {
    first = NULL;
    last = NULL;
    count = 0;
}

template<class Type>
doublyLinkedList<Type>:: doublyLinkedList(const doublyLinkedList<Type>& otherList){
    
}

template<class Type>
doublyLinkedList<Type>:: ~doublyLinkedList(){
    
}

template<class Type>
void doublyLinkedList<Type>:: initializeList() {
    destory();
}

template<class Type>
void doublyLinkedList<Type>:: destory() {
    nodeType<Type> *temp;
    
    while(first != NULL) {
        temp = first;
        first = first-> next;
        delete temp;
    }
    last = NULL;
    count = 0;
}

template<class Type>
void doublyLinkedList<Type>:: print() const {
    nodeType<Type> *current;
    current = first;
    
    while(current!= NULL) {
        cout<< current->info << " " <<endl;
        current = current-> next;
    }
}

template<class Type>
void doublyLinkedList<Type>:: reversePrint() const {
    nodeType<Type> *current;
    current = last;
    while(current !=NULL){
        cout<< current->info << " " <<endl;
        current = current->back;
    }
}

template<class Type>
void doublyLinkedList<Type>::insert(const Type& item) {
    nodeType<Type>* newNode = new nodeType<Type>;
    newNode->info = item;
    newNode->next = NULL;
    newNode->back = NULL;

    if (first == NULL) {
        // List is empty, new node is both the first and the last node
        first = newNode;
        last = newNode;
    } else {
        nodeType<Type>* current = first;
        nodeType<Type>* trailCurrent = nullptr;
        bool found = false;

        // Find the position to insert the new node
        while (current != NULL && !found) {
            if (current->info >= item) {
                found = true;
            } else {
                trailCurrent = current;
                current = current->next;
            }
        }

        if (current == first) {
            // Insert new node before the first node
            newNode->next = first;
            first->back = newNode;
            first = newNode;
        } else {
            // Insert new node between trailCurrent and current or at the end
            newNode->next = current;
            newNode->back = trailCurrent;
            if (current != NULL) {
                current->back = newNode;
            } else {
                last = newNode;
            }
            trailCurrent->next = newNode;
        }
    }

    count++;
}

template<class Type>
void doublyLinkedList<Type>::deleteNode(const Type& item) {
    nodeType<Type>* current;
    bool found;

    if (first == NULL) {
        // List is empty
        cout << "Cannot delete from an empty list" << endl;
        return;
    }

    if (first->info == item) {
        // Delete the first node
        current = first;
        first = first->next;

        if (first != NULL) {
            first->back = NULL;
        } else {
            last = NULL;
        }

        count--;
        delete current;
    } else {
        found = false;
        current = first;

        // Find the node to delete
        while (current != NULL && !found) {
            if (current->info >= item) {
                found = true;
            } else {
                current = current->next;
            }
        }

        if (current == NULL) {
            // Node to delete is not found
            cout << "Item is not in the list" << endl;
        } else if (current->info == item) {
            // Node to delete is found
            if (current->back != NULL) {
                current->back->next = current->next;
            }

            if (current->next != NULL) {
                current->next->back = current->back;
            }

            if (current == last) {
                last = current->back;
            }

            count--;
            delete current;
        } else {
            // Node to delete is not found
            cout << "Item is not in the list" << endl;
        }
    }
}







template<class Type>
bool doublyLinkedList<Type>:: search(const Type& item) const{
    bool found = false;
    nodeType<Type> *current;
    current = first;
    while(current != NULL && !found){
        if(current->info >= item){
            found = true;
        }
        else {
            current = current->next;
        }
    }
    if(found){
        found = (current->info == item);
    }
    
    return found;
}

template<class Type>
bool doublyLinkedList<Type>:: isEmptyList() const {
    return( first == NULL);
}

template<class Type>
int doublyLinkedList<Type>:: length() const {
    return count;
}

template<class Type>
Type doublyLinkedList<Type>:: front() const {
    assert(first!= NULL);
    return first->info;
}

template<class Type>
Type doublyLinkedList<Type>:: back() const {
    assert(last!= NULL);
    return last->info;
}

template<class Type>
const doublyLinkedList<Type> & doublyLinkedList<Type>:: operator = (const doublyLinkedList<Type> & otherList){
    
}

template<class Type>
void doublyLinkedList<Type>:: copyList(const doublyLinkedList<Type> & otherList) {
    
}
