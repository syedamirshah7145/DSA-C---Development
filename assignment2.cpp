//using class now
#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000

class Node{
    public:
    char data;
    Node *next;
    Node(){
        next = nullptr;
    }
};

class singlyLinkedList{
    public:
    Node *head;
           void append(char data);
};

void singlyLinkedList::append(char data){
    Node *temp = new Node;
    temp->data = data;
    if(head == nullptr){
        head = temp;
    }
    else{
        Node *ptr = head;
        while(ptr->next != nullptr){
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

class stackNode{
    Node *top;
    public:
            void push(char data);
            void pop();
            bool isEmpty();
            char topElement();
            void display();
            bool isPalindrome(Node *head);
    stackNode(){
        top = nullptr;
    }
};

void stackNode::push(char data){
    Node *newNode = new Node;
    newNode->data = data;
    if(top == nullptr){
        newNode->next = nullptr;
    }
    else{
        newNode->next = top;
    }
    top = newNode;
}

void stackNode::pop(){
    if(top == nullptr){
        cout<<"Empty!";
    }
    else{
        Node *temp = top;
        top = top->next;
        delete(temp);
    }
}

bool stackNode::isEmpty(){
    if(top == nullptr){
        return true;
    }
    return false;
}

char stackNode::topElement(){
    return top->data;
}

void stackNode::display(){
    if(top == nullptr){
        cout<<"List Empty!";
    }
    else{
        Node *temp = top;
        while(temp != nullptr){
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }
}

bool stackNode::isPalindrome(Node *head){
    Node *middle = top;
    Node *fast = top;
    while(fast->next != nullptr){
        middle = middle->next;
        fast = fast->next->next;
    }
    middle = middle->next;
    while(middle != nullptr){
        if(top->data != middle->data){
            return false;
        }
        top = top->next;
        middle = middle->next;
    }
    return true;
}



class Stack{
    int top;
    char myStack[SIZE];
    public:
            void push(char item);
            char pop();
            bool isEmpty();
            char topElement();
            bool isPalindrome(string s);
    Stack(){
        top = -1;
    }
};

char Stack::topElement(){
    if(top == -1){
        cout<<"Stack is empty!";
    }
    else{
        return myStack[top];
    }
}

void Stack::push(char item)
{
    if(top==SIZE-1)
    {
	cout<<"Stack is Full\n";
  	}
    else{
  	top=top+1;
  	myStack[top]=item;
  	}
}

char Stack::pop(){
    if(top==-1){
        cout<<"Stack underflow!";
    }
    else{
        char item = myStack[top--];
        return item;
    }
}

bool Stack::isEmpty(){
    return (top < 0);
}

bool Stack::isPalindrome(string s){
    class Stack stack;
    int length = s.size();
    int i, mid = length/2;
    for(i = 0;i<mid;i++){
        stack.push(s[i]); 
    }
    if(length%2 != 0){
        i++;
    }
    char element;
    while(s[i] != '\0'){
        element = stack.topElement();
        stack.pop();
        if(element != s[i]){
            return false;
        }
        i++;
    }
    return true;
}



int main(){
    // class Stack stack;
    // cout<<"The stack push"<<endl;
    // stack.push('4');
    // stack.push('5');
    // cout<<stack.topElement()<<endl;
    // if(stack.isPalindrome("12")){
    //     cout<<"yes!";
    // }
    // else{
    //     cout<<"No!";
    // }
    // return 0;

    class stackNode linkedList;
    class singlyLinkedList singlyList;
    singlyList.append('a');
    linkedList.isPalindrome(singlyList.head);
    // class Node node;
    
    // linkedList.push('r');
    // linkedList.push('a');
    // linkedList.push('d');
    // linkedList.push('a');
    // linkedList.push('r');
    // if(linkedList.isPalindrome()){
    //     cout<<"Yes!";
    // }
    // else{
    //     cout<<"No!";
    // }
}