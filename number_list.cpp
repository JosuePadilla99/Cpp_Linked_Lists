#include <iostream>

#include "NUMBERLIST_H.h"

using namespace std;

NumberList::~NumberList(){
};

void NumberList::appendNode(double num){
    ListNode *newNode;
    ListNode *nodePtr;
    
    newNode = new ListNode;
    newNode->number = num;
    newNode->next = nullptr;

    if(!head){
        head = newNode;
    }

    else{
        nodePtr = head;
	while(nodePtr->next){
	    nodePtr = nodePtr->next;
	}
    nodePtr->next = newNode;
    }

    //delete newNode;
}

void NumberList::insertNode(double num){
    /*Creating three pointers for the linked list nodes:
     -newNode: pointer used to add a new node to the linked list
     -nodePtr: pointer used to traverse through the linked list
     -prevNode: pointer initially set to null since we don't know what it's pointing to and used to track the previous node 
     in the linked list
     */

    ListNode *newNode;
    ListNode *nodePtr;
    ListNode *prevNode = nullptr;
    
    //Allocating memory for the linked list node and setting the value to the num parameter
    newNode = new ListNode;
    newNode->number = num;

    /*If we are not at the beginning "head" of the list, we will set to the head to the newNode which holds a value of the 
     num param and then the next value in the list to nullptr. The next value nullptr is temporary as we insert values
     */

    if(!head){
        head = newNode;
	newNode->next = nullptr;
    }
    
    //Nested else statement edge cases
    else{
        
	//Setting our traversing node "nodePtr" to the head and the prevNode to nullptr as there isn't a previous node yet
        nodePtr = head;
        prevNode = nullptr;

        /*While our traversing node is not a null value and the next value in the list is less than the num param,
	We will set the previous node to the nodePtr value which is currently head and the nodePtr value will then be set in the next line to the 
	next value in the linked list. This wil ensure that we can accurately track the next value of the node in the linked list and then we ensure that
	previous node will be updated with the previous value of the node pointer aka the previous node
	*/

	while(nodePtr != nullptr && nodePtr->number < num){
	    prevNode = nodePtr;
	    nodePtr = nodePtr->next;
	}

	/*Edge case if we want the new node to be the node inserted:
	-if the prevNode is equal to nullptr:
	-we will set the head of the linked list to the newNode value which was previously set to the value of the num param
	-we will then set the value of the next node in the list to the value of nodePtr aka our traversing node pointer
	*/

	if(prevNode == nullptr){
            head = newNode;
	    newNode->next = nodePtr;
	}

	/*If the previous node is not a null value:
	-we will set the previous node to the newNode value because we can assume that we are not at the head of the linked list meaning we want the head of the 
	list to be equal to the value of the newNode.
	-we will then set the value of the next node to the traversing node aka the nodePtr
	*/

	else{
            prevNode = newNode;
	    newNode->next = nodePtr;
	}
    }
    //freeing memory on the heap
    //delete newNode;
}
        

void NumberList::displayList(){
    ListNode *nodePtr;
    nodePtr = head; 

    while(nodePtr != NULL){
        cout << nodePtr->number << endl;
	nodePtr = nodePtr->next;
    }
}
