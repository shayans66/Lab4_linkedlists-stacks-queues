#pragma once


#include <iostream>
#include <string>
#include <cstring>

#include "LinkedLists_Nodes.h"
#include "Dollar.h"

// Stack inherits from Linklist. It can use methods in linkedlist within Stack class,
// but user cannot use LinkedList class methods on a stack object in main
class Stack : private LinkedList {
    // inherits Constructor and Destructor from Linked List
public:
    Stack() : LinkedList(){}
    ~Stack(){}
    
    
    
    
    // add node with dollar data to top of stack
    void push(Dollar* dol){
        addDataEnd(dol);
    }
    // returns node at the end of the list, remove it as well
    Dollar* pop(){
        Dollar* n = findData(getCount()-1);
        deleteData(getCount()-1);
        return n;
    }
    // returns Dollar data at tp of stack
    Dollar* peek(){
        return findData(getCount()-1);
    }
    // destroys stack
    void destroyStack(){
        destroyList();
    }
    // prints stack
    void printStack(){
        printList();
    }
    // returns if stack is empty or not
    bool isStackEmpty(){
        return isListEmpty();
    }

    
};
// Queue inherits from Linklist. It can use methods in linkedlist within Queue class,
// but user cannot use LinkedList class methods on a queue object in main
class Queue : private LinkedList{
public:
    // inherits Constructor and Destructor from Linked List
    Queue() : LinkedList(){}
    ~Queue(){}
    // adds node to beginning with data dollar
    void enqueue(Dollar* dol){
        addDataStart(dol);
    }
    // removes and deletes dollar in last node
    Dollar* dequeue(){
        Dollar* n = findData(getCount()-1);
        deleteData(getCount()-1);
        return n;
    }
    // returns dollar reference of first node
    Dollar* peekFront(){
        return findData(0);
    }
    // returns dollar reference of last node
    Dollar* peekRear(){
        return findData(getCount()-1);
    }
    // destroys queue
    void destroyQueue(){
        destroyList();
    }
    
    // prints queue
    void printQueue(){
        printList();
    }

    // returns if queue is empty or not
    bool isQueueEmpty(){
        return isListEmpty();
    }


};
