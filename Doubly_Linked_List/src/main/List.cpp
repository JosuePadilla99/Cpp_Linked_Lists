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
        Node* newNode = new Node(value); //allocate memory to the heap for a new node
        Node* head = getHeadPtr();
        Node* tail = getTailPtr();
        Node* current;
        //need to check to see if the list is empty. If it is, we will set the head and tail ptr to the new node
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
            current -> setPrevPtr(tail); \
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
    Node* tail = getTailPtr();
    Node* current;
    int counter{0}; //setting a counter to collect the number of nodes in the list
    
    //getting the number of nodes in the list
    current = head;
    if(headPtr != nullptr){
        while(current->getNextPtr() != nullptr){
            current = current -> getNextPtr();
            counter ++;
        }
    }
    std::cout << "Linked List length is: " << counter << std::endl;

    if(index > counter){
        throw "The index number you entered was larger than the length of the linked list.";
    }
    
    /*We want to loop through iterations for the size of the list using the counter variable
    -get the next node in the linked list
    -We want to stop one short of the index because we going to insert the new node in between the prev node
    and the current node.*/
    current = head;
    for(int i{1}; i < counter; i++){
        current = current -> getNextPtr();
        if((i == index - 1) && (current -> getNextPtr() != nullptr)){
            newNode -> setNextPtr(current ->getNextPtr());
            newNode -> setPrevPtr(current);
            current -> setNextPtr(newNode);
            current -> setPrevPtr(current ->getPrevPtr());
            
        }
    
    }
    std::cout << "Successfully added node at index: " << index << std::endl;

    printForward();

}
void List::deleteAtIndex(int index)
{}
void List::readItem(int index){}
void List::reverseList(){}

void List::printForward(){
    Node* current = getHeadPtr();

    while(current != nullptr){
        current = current->getNextPtr();
        std::cout << "Value of node is: " << current->getData() << ", ";
        
    }
}
void List::printBackward(){
    Node* tail = tail->getPrevPtr();
    
    while(tail != nullptr){
        tail = tail->getPrevPtr();
        std::cout << "Value of node printed backwards is: " << tail->getData() << ",";
    }
}
