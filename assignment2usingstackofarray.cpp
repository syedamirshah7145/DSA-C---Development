#include <iostream>

using namespace std;
#define size 100
char stack[size];
int top = -1;

struct Node {
    char data;
    Node *next;
};

struct NodeDoubly{
    char data;
    NodeDoubly *next;
    NodeDoubly *previous; 
};

void appendSingly(struct Node** head,char nodeData){
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

void displayListSingly(struct Node *head){
    while(head != nullptr){
        cout<<head->data<<endl;
        head = head->next;
    }
}

bool isEmpty(){
    if(top<=-1){
        return true;
    }
    return false;
}

void push(char value){
    if(top>=size-1){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        top++;
        stack[top] = value;
    }
}

void pop(){
    if(top<=-1){
        cout<<"Stack Underflow"<<endl;
    }
    else{
        cout<<"Popped element is "<<stack[top]<<endl;
        top--;
    }
}

char topElement(){
    if(isEmpty()){
        cout<<"Stack is empty!"<<endl;
    }
    else{
        return stack[top];
    }
}

void display() {
   if(top>=0) {
      cout<<"Stack elements are:"<<endl;
      for(int i=top; i>=0; i--){
        cout<<stack[i]<<" ";
        cout<<endl;
      }
   } 
   else{
    cout<<"Stack is empty"<<endl;
   }
}

bool isPalindromeSingly(Node *head){
    Node *slow = head;
    Node *fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    //case for even case
    if(fast == nullptr){
        while(head != slow){
            push(head->data);
            head = head->next;
        }
    }
    else{
        while(head != slow){
            push(head->data);
            head = head->next;
        }
        head = head->next;
    }

    while(head != nullptr){
        if(head->data != topElement()){
            return false;
        }
        pop();
        head = head->next;
    }
    return true;
}





int main(){
    Node *head = nullptr;
    appendSingly(&head,'l');
    appendSingly(&head,'a');
    appendSingly(&head,'a');
    appendSingly(&head,'l');
    cout<<isPalindromeSingly(head)<<endl;
}