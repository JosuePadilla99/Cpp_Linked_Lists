#ifndef NUMBERLIST_H
#define NUMBERLIST_H

class NumberList{
private:
    struct ListNode{
        double number;
	struct ListNode *next; //creating a pointer for the next node
    };
    ListNode *head; //creating a pointer for the head of the list

public:
    NumberList() {head = nullptr;};
    ~NumberList();
    void appendNode(double);
    void insertNode(double);
    void deleteNode(double);
    void displayList();

};

#endif
