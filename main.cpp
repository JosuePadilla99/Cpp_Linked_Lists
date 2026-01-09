#include <iostream>
#include <string>
#include "NUMBERLIST_H.h"

using namespace std;

void operationCall();

int main(){
    string promptAnswer;
    cout << "Would you like to perform an operation on the linked list? (Enter yes or no)" << endl;	
    cin >> promptAnswer;
    if(promptAnswer == "yes"){
        operationCall();
    }
    else{
        cout << "User entered no to performing an operation on the linked list" << endl;
    }
    return 0;
}

void operationCall(){
    NumberList list;

    int caseNum;
    cout << "Would you like to insert, append, or display the linked list?: (Enter 1 to insert, 2 to append, or 3 to display)" << endl;
    cin >> caseNum;

    switch(caseNum){
         case 1:
	     int numbersToEnter;
             cout << "Enter the amount of numbers you want to insert in the linked list: " << endl;
	     cin >> numbersToEnter;
	     while(numbersToEnter > 0){
	         float numberToAdd;
		 cout << "Enter a decimal to add to the linked list: " << endl;
		 cin >> numberToAdd;
		 list.insertNode(numberToAdd);
		 numbersToEnter --;
	     }
	     break;
	 
	 case 2:
	     int numbersToApp;
	     cout << "Enter the amount of numbers you'd like to append to the linked list: " << endl;
	     cin >> numbersToApp;
	     while(numbersToApp > 0){
	         float numberToAppend;
		 cout << "Enter a decimal you'd like to append to the linked list: " << endl;
		 cin >> numberToAppend;
		 list.appendNode(numberToAppend);
		 numbersToApp --;
	     }
	     break;

	 case 3:
	     list.displayList();
	     break;

	 default:
	     cout << "Case number entered did not match the provided cases" << endl;
	     break;
    }
} 

