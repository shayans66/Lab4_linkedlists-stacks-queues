//
// Lab 4 - Lists, Stacks, and Queues
//  Ethan Sarnevsht
// Purpose: To demonstrate understanding of implementing the data structures Singly-Linked lists, Stacks, Queues, and the commonly implemented methods that go along with these data structures

/*
 PSEUDOCODE:
 

 
 */

#include "Dollar.h"

#include "LinkedLists_Nodes.h"
#include "Stacks_Queues.h"

#include <iostream>

using namespace std;

int main() {
    
    
    Dollar* dol1 = new Dollar(1,60,"Dollar", "Cent");
    Dollar* dol2 = new Dollar(31,40,"Dollar", "Cent");
    Dollar* dol3 = new Dollar(73,30,"Dollar", "Cent");
    Dollar* dol4 = new Dollar(35,70,"Dollar", "Cent");
    Dollar* dol5 = new Dollar(44,80,"Dollar", "Cent");
    Dollar* dol6 = new Dollar(77,90,"Dollar", "Cent");
    Dollar* dol7 = new Dollar(2,10,"Dollar", "Cent");
    
    LinkedList* list = new LinkedList();

    printf("====== LINKED LIST =======\n");
    list->addDataEnd(dol1);
    list->printList();
    list->addDataStart(dol2);
    list->printList();
    list->addDataEnd(dol3);
    list->printList();
    list->addDataEnd(dol4);
    list->printList();
    list->addDataStart(dol5);
    list->printList();
    list->addDataStart(dol6);
    list->printList();
    list->addDataStart(dol7);
    list->printList();
    // exhibit function of findData for finding Dollars
    int ind3 = list->findData(dol3);
    printf("Dol3 is at index %d\n", ind3);
    // exhibit function of findData for finding Dollar in index
    cout << "The dollar at index 5 is " << *(list->findData(5)) << endl;

    // deleteData functionality
    list->deleteData(3);
    list->printList();

    // isListEmpty() functionality
    printf("Is list empty? %s\n", list->isListEmpty() ? "true" : "false");
    // testing destroyList() and isListEmpty()
    list->destroyList();
    printf("Is list empty? %s\n", list->isListEmpty() ? "true" : "false");

    printf("====== END LINKED LIST =======\n");

    // TESTING STACK STARTS NOW
    printf("====== STACK =======\n");
    
    
    
    printf("====== END STACK =======\n");


    // TESTING QUEUE STARTS NOW
    printf("====== QUEUE =======\n");

    printf("====== END QUEUE =======\n");

    
    
    
}
