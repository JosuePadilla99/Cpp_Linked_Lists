//
//  List.cpp
//  DoublyLinkedList
//
//  Created by Madhuri Debnath on 9/24/20.
//

#include<iostream>
#include "List.h"
using namespace std;

Node* List::getHeadPtr() const{
    return headPtr;
}

Node* List::getTailPtr() const{
    return tailPtr;
}

void List::insert(int value){  
    try{
        Node* newNode = new Node(value); // Allocate memory to the heap for a new node
        Node* head = getHeadPtr();
        Node* tail = getTailPtr();
        Node* current;

        // Need to check to see if the list is empty. If it is, we will set the head and tail ptr to the new node
        if(headPtr == nullptr){
            headPtr = newNode;
            tailPtr = newNode;
        }
        else{
            
            current = head;
            while(current->getNextPtr() != nullptr){
                current = current -> getNextPtr();
            }

            /*statements to ensure we link the linked backwarads and forwards. 
            -Setting the next pointer in the list to that of the newNode we want to add
            -setting the previous node of the node we added to that of the "current"
            -setting the "current" node pointer to the tail pointer of the node
            -setting the pointer for the next node from the new node to null as this is the end of the list*/
            current -> setNextPtr(newNode); 
            newNode -> setPrevPtr(current); 
            current -> setPrevPtr(tail); 
            newNode -> setNextPtr(nullptr);

        }
        std::cout << "Successfully created new node!" << std::endl;
    }
    catch(runtime_error error){
        std::cout << "Did not create new node" << error.what();
    }
}

void List::insertAtIndex(int data, int index){
    Node* newNode = new Node(data);
    Node* head = getHeadPtr();
    Node* current;
    int i{1}; //setting a counter to collect the number of nodes in the list till we hit the index

    std::cout << "List before adding node is: " << std::endl;
    printForward();
    std::cout << std::endl;
    
     // If user wants to add node at the beginning, ensuring we add the new node to the beginning of the list
    if(index == 1){
        newNode->setPrevPtr(nullptr);
        newNode->setNextPtr(headPtr);
        headPtr->setPrevPtr(newNode);
        headPtr = newNode;
        
        std::cout << "Successfully added node at index: " << index << std::endl;
        printForward();
        return;

    }

    //looping through getting the next pointer until we reach the index or node we want to access
    current = head;
    while(i <= index - 1){ /*
        we stop at one before our index because we want to insert node in between the previous node of the index 
        and the index of the node we want to replace*/
        current = current->getNextPtr();
        i++;
    }

    //if the node we want to access is not null, we then insert it in between the current and previous node
    if(current != nullptr){
        newNode -> setNextPtr(current ->getNextPtr());
        newNode -> setPrevPtr(current);
        current -> setNextPtr(newNode);
        current -> setPrevPtr(current ->getPrevPtr());
    }

    std::cout << "Successfully added node at index: " << index << std::endl;

    printForward();

}
void List::deleteAtIndex(int index){
    Node* head = getHeadPtr();
    //Node* tail = getTailPtr();
    Node* next;
    Node* previous;
    Node* current;
    int i{1};
    
    // Deleting node at index 1 if user wants to delete the first node in the list
    current = head;
    if(index == 1){
        headPtr = headPtr->getNextPtr();
        headPtr->setPrevPtr(nullptr);
        
        delete current;
        std::cout << "Successfully deleted node at index: " << index << std::endl;
        printForward();
        return;
    } 

    // Looping through till we reach out index value
    while(i <= index){ 
        current = current->getNextPtr();
        i ++;
    }
    
    // getting the previous pointer of the current node and setting its next to the next of curren to "skip" current
    previous = current->getPrevPtr();
    if(previous != nullptr){
        previous->setNextPtr(current->getNextPtr());
    }
    
    // getting next node of current and setting its previous pointer to that of previous to "skip" current node
    next = current->getNextPtr();
    if(next != nullptr){
        next->setPrevPtr(previous);
    }

    delete current;

    std::cout << "Successfully deleted node at index: " << index << std::endl;
    printForward();
    
}
void List::readItem(int index){
    Node* head = getHeadPtr();
    Node* current;
    int i{1};
   
    // Looping through till we hit the index we want to read from
    current = head;
    while(i <= index){
        current = current->getNextPtr();
        i ++;
    }

    // Printing out the value of the index as long as the node is not null
    if(current != nullptr){
        std::cout << "Value of node " << index << " is: " << current->getData() << std::endl; 
    }

}
void List::reverseList(){
    Node* current = headPtr;
    Node* prevNode = nullptr;

    while (current != nullptr) { 
        Node* nextNode = current->getNextPtr(); //making sure we can store the value of the next node crucial

        current->setNextPtr(prevNode); //swapping next to the previous pointer
        current->setPrevPtr(nextNode); //swapping the previous pointer to the next pointer

        prevNode = current;
        current = nextNode; //this is crucial so we can now have the value of what was the next node for swapping pointers 
    }

    //swapping the head and tail pointers to finish the swap where the prevNode is equal to current or the tail
    tailPtr = headPtr;
    headPtr = prevNode;

    std::cout << "Last value is: " << headPtr->getData() << std::endl;
    
    printForward();
}

void List::printForward(){
    Node* current = getHeadPtr();
    
    // Checking to ensure list is not empty
    if(!current){
        std::cout << "Head is null" << std::endl;
    }
   
    // Looping through and printing out non zero values
    while(current){
        if(current->getData() != 0){
            std::cout << "Value of node is: " << current->getData() << ", ";
        }
        current = current->getNextPtr();
        
    }
}
void List::printBackward(){
    Node* head = getHeadPtr();
    Node* end;
   
    // getting the tail or end of the list to use in the next loop
    end = head;
    while(end->getNextPtr() != nullptr){
        end = end->getNextPtr();
    }
    
    // Using our end pointer to then loop through and print the previous value of the tail or end of our linked list
    while(end != nullptr){
        if(end->getData() != 0){
            std::cout << "Value of node printed backwards is: " << end->getData() << ",";
        }
        end = end->getPrevPtr();
    }
}
