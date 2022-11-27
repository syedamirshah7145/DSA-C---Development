#include <iostream>

using namespace std;


struct Node{
    int data;
    struct Node *next;
};
struct Node *head = nullptr;

void push(struct Node** head,int nodeData){

    //create new node for holding data
    struct Node* newNode = new Node;

    //insert data in new node
    newNode->data = nodeData;

    //set new node as head
    newNode->next = (*head);

    //now head will point to newNode
    (*head) = newNode;
}

void reverseListPrint(Node *head){
    if(head != nullptr){
        reverseListPrint(head->next);
        cout<<head->data<<"\n";
    }
}



void append(struct Node** head,int nodeData){
    struct Node* newNode = new Node;
    struct Node* last = *head;
    newNode->data = nodeData;
    newNode->next = nullptr;

    if(*head == nullptr){
        *head = newNode;
        return;
    }

    while(last->next != nullptr){
        last = last->next;
    }

    last->next = newNode;
    return;
}

// void deleteBeforeSpecificValue(struct Node* headCopy,int targetData){
//     struct Node* p1 = nullptr;
//     struct Node* p2 = nullptr;
//     while(headCopy != nullptr){
//         if(headCopy->data = targetData){
//             delete(p2->next);
//             p2->next = p2->next->next;
//             return;
//         }
//         p2 = p1;
//         p1 = headCopy;
//         headCopy = headCopy->next;
//     }
// }

void reverseListElements(Node **head){
    if(*head == nullptr){
        cout<<"List is Empty!"<<"\n";
        return;
    }
    Node *prevNode = nullptr;
    while(*head != nullptr){
        Node *nextNode = (*head)->next;
        (*head)->next = prevNode;
        prevNode = *head;
        *head = nextNode;
    }
    *head = prevNode;
}

void displayList(struct Node *head){
    while(head != nullptr){
        cout<<head->data<<endl;
        head = head->next;
    }
}

int main(){
    reverseListElements(&head);
    reverseListElements(&head);
    displayList(head);
}