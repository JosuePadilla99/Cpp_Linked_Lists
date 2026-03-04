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
    Node* current;
    int i{1}; //setting a counter to collect the number of nodes in the list till we hit the index

    std::cout << "List before adding node is: " << std::endl;
    printForward();
    std::cout << std::endl;

    //looping through getting the next pointer until we reach the index or node we want to access
    current = head;
    while(i <= index - 1){ /*
        we stop at one before our index because we want to insert node in between the previous node of the index 
        and the index of the node we want to replace*/
        current = current->getNextPtr();
        i++;
    }

    //if the node we want to access is not null, we then insert it in between
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
    //int counter{0};
    int i{1};

    current = head;
    if(index == 0){
        head = current->getNextPtr();
        if(head != nullptr){
            head->setPrevPtr(nullptr);
        }
    }

    while(i <= index - 1){
        current = current->getNextPtr();
        i ++;
    }

    previous = current->getPrevPtr();
    if(previous != nullptr){
        previous->setNextPtr(current->getNextPtr());
    }

    next = current->getNextPtr();
    if(next != nullptr){
        next->setPrevPtr(previous);
    }

    std::cout << "Successfully deleted node at index: " << index << std::endl;
    printForward();
    // while(head->getNextPtr() != nullptr){
    //     std::cout << "Test print: " << head->getData() << std::endl;
    //     head = head->getNextPtr();
    // }
    

    // current = head; 
    // we can set this but we need to ensure that we relink head with the list
    /* We are actually deleting the pointer but when we do, we are also freeing up memory from the rest of the list
    we need to relink the list back together when we remove the node to delete. This is b/c we are setting 
    current to the head pointer, then using this to traverse through the list and then freeing current.*/

    // current = head;
    // if(headPtr != nullptr){
    //     while(current->getNextPtr() != nullptr){
    //         current = current->getNextPtr();
    //         counter ++;
    //     }
    // }

    // std::cout << "Length of the list is: " << counter << std::endl;
    
    // for(int i{0}; i < index; i++){
    //     current = current->getNextPtr();
    //     if((i == index - 1) && (current->getNextPtr() != nullptr)){
    //         std::cout << "TEST ONE" << std::endl;
    //         previous = current->getPrevPtr();
    //         previous->setNextPtr(current->getNextPtr());
    //         next = current->getNextPtr();
    //         next->setPrevPtr(current->getPrevPtr());
    //         std::cout << "TEST TWO" << std::endl;
    //         break;
    //     }
    // }
    
}
void List::readItem(int index){
    Node* head = getHeadPtr();
    Node* current;
    int i{1};

    current = head;
    while(i <= index){
        current = current->getNextPtr();
        i ++;
    }
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
        current = nextNode; //this is crucial so we can now have the value of what was the next node before swapping pointers 
    }

    //swapping the head and tail pointers to finish the swap where the prevNode is equal to current or the tail
    tailPtr = headPtr;
    headPtr = prevNode;

    std::cout << "Last value is: " << headPtr->getData() << std::endl;
    
    printForward();
}

void List::printForward(){
    Node* current = getHeadPtr();

    if(!current){
        std::cout << "Head is null" << std::endl;
    }

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
   
    end = head;
    while(end->getNextPtr() != nullptr){
        end = end->getNextPtr();
    }
    
    while(end != nullptr){
        if(end->getData() != 0){
            std::cout << "Value of node printed backwards is: " << end->getData() << std::endl;
        }
        end = end->getPrevPtr();
    }
}
