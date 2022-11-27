#include <iostream>

using namespace std;

struct Node{
    char data;
    Node *next;
};

Node *top = nullptr;

bool isEmpty(){
    if(top == nullptr){
        return true;
    }
    else{
        return false;
    }
}

void push(char data){
    Node *newNode = new Node;
    newNode->next = nullptr;
    newNode->data = data;
    if(isEmpty()){
        top = newNode;
    }
    else{
        newNode->next = top;
        top = newNode;
    }
}

void pop(){
    if(isEmpty()){
        cout<<"Stack Empty!"<<endl;
    }
    else{
        Node *temp = top;
        top = top->next;
        delete(temp);
    }
}

char topElement(){
    if(top == nullptr){
        cout<<"Stack Empty!";
    }
    else{
        return top->data;
    }
}

void display(Node *top){
    while(top != nullptr){
        cout<<top->data<<endl;
        top = top->next;
    }
}

// void isPalindrome(String s){
    
// }

// bool isPalindrome(node)

void insertAtEnd(){
    
}

int main(){
    push('f');
    push('2');
    pop();
    display(top);
}