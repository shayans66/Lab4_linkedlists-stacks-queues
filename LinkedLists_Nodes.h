#pragma once

#include "Dollar.h"
//#include "Stacks_Queues.h"

#include <iostream>
#include <string>
#include <cstring>

// Node class
class LinkNode{
public:
    // instance variables: dollar data and next dollar pointer
    Dollar* data;
    LinkNode* next;
    
    // constructor: initialize dollar data and there is no 'next' dollar to point to
    LinkNode(Dollar* d){
        data = d;
        next = NULL;
    }
    // default constructor
    LinkNode(){}
    ~LinkNode(){}
};

// Linked list with Dollar nodes class
class LinkedList {
private:
    // attributes: count is length of list, start is a pointer to the first node, and
    // end is a pointer to the last node
    int count;
    LinkNode* start;
    LinkNode* end;
public:
    // getter methods for attributes
    int getCount(){ return count; }
    LinkNode* getStart(){ return start; }
    LinkNode* getEnd(){ return end; }
    
    // constructor: also serves as "createNewList()" method in spec
    LinkedList(){
        start = NULL;
        end = NULL;
        count = 0;
    }
    void createNewList(){
        start = NULL;
        end = NULL;
        count = 0;
    }
    
    // destructor: start at beggining node, and loop through all the nodes, deleting them
    // it needs to be `virtual` so the sub-classes can inherit it
    virtual ~LinkedList(){
        if(isListEmpty())
            return;
        
        LinkNode* temp = start->next;

        // for each node, delete it. but store a temporary node such that we can delete the
        // current node but still have a path to the next node
        for(LinkNode* node = start; node != NULL; temp = temp->next ){
            
            delete node;

            node = temp;
        }
    
    }
    // add another node with Dollar data to START of list
    void addDataStart(Dollar* dol){
        // make new node with appropriate data
        LinkNode* newNode = new LinkNode();
        newNode->data = dol;
        // if list is empty, added node shouldn't point to anything, but start/end point to it
        if(isListEmpty()){
            newNode->next = NULL;
            start = newNode;
            end = newNode;
            count++;
            return;
        }
        newNode->next = start;
        
        start = newNode;
        count++;
    }
    
    // add another node with Dollar data to END of list
    void addDataEnd(Dollar* dol){
        // make new node with appropriate data
        LinkNode* newNode = new LinkNode();
        newNode->data = dol;
        newNode->next = NULL;
        // if list is empty, start and end can't be dereferenced.
        // thus, they must be set to 'newNode' manually
        if(isListEmpty()){
            start = newNode;
            end = newNode;
            count++;
            return;
        }
        // update next attribute of now second-to-last node to point to address of new last node
        end->next = newNode;
        // update end to point to last node's address
        end = newNode;
        // update length
        count++;
    }
    // delete node at a given position (index) in linkedlist
    void deleteData(int index){
        int cur = 0;
        LinkNode* current = start;
        while(cur != index ){
            current = current->next;
            cur++;
        }
        // Node current is now pointing to node BEFORE the one specified by paramter "index"
        end = current;
        delete current->next;
        // update count
        count--;

    }
    // returns dollar in node with given index, overloaded with other 'findData' method
    Dollar* findData(int ind){
        int curInd = 0;
        LinkNode* current = start;
        while( curInd != ind ){
            current = current->next;
            curInd++;
        }
        // at this point, current points to node at index 'ind'
        return current->data;
    }
    // returns index of node with given Dollar data
    int findData(Dollar* dol){
        int ind = 0;
        LinkNode* current = start;
        while( !(*(current->data) == *dol) ){   //
            current = current->next;
            ind++;
        }
        
        return ind;
    }
    // returns if list is empty
    bool isListEmpty(){
        return start == NULL;
    }
    // destroys list the same way the class destructor does: deletes all nodes
    void destroyList(){
        if(isListEmpty())
            return;
        LinkNode* temp = start->next;
        
         for each node, delete it. but store a temporary node such that we can delete the
         current node but still have a path to the next node
        for(LinkNode* node = start; node != NULL; temp = temp->next ){

            delete node;

            node = temp;
        }
       
        
        
        start = end = NULL;
        count = 0;
    }
    // prints all dollar objects in list using "std::cout", which takes advantage of
    // ostream operator overload in "Dollar.h"
    void printList(){
        LinkNode* current = start;
        while(current !=NULL){
            // if on last index, don't print comma
            if(current->next == NULL){
                std::cout << *(current->data) << std::endl;
                return;
            }
            std::cout << *(current->data) << ", ";
            current = current->next;
            
        }
        std::cout << std::endl;
    }
};
