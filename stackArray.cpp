#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Stack Dynamic using doubly linked list
struct NodeDoubly{
    char data;
    NodeDoubly *next;
    NodeDoubly *pre;
};

NodeDoubly *topDoubly = nullptr;

bool isEmptyDoubly(){
    if(topDoubly == nullptr){
        return true;
    }
    return false;
}

void displayDoubly(){
    if(isEmptyDoubly()){
        cout<<"List already empty!"<<endl;
    }
    else{
        NodeDoubly *ptr = topDoubly;
        while(ptr != nullptr){
            cout<<ptr->data<<endl;
            ptr = ptr->next;
        }
    }
}

void pushDoubly(char data){
    NodeDoubly *ptr = new NodeDoubly;
    ptr->data = data;
    ptr->next = nullptr;
    ptr->pre = nullptr;
    if(isEmptyDoubly()){
        topDoubly = ptr;
        topDoubly->next = nullptr;
        topDoubly->pre = nullptr;
    }
    else{
        ptr->next = topDoubly;
        topDoubly->pre = ptr;
        topDoubly = ptr;
    }
}

void popDoubly(){
    if(isEmptyDoubly()){
        cout<<"Stack already Empty!"<<endl;
    }
    else if(topDoubly->next == nullptr){
        delete(topDoubly);
        topDoubly = nullptr;
    }
    else{
        NodeDoubly *temp = topDoubly;
        topDoubly = topDoubly->next;
        topDoubly->pre = nullptr;
        delete(temp);
    }
}

char topElementDoubly(){
    if(isEmptyDoubly()){
        cout<<"Stack Empty!"<<endl;
    }
    else{
        return topDoubly->data;
    }
    return 0;
}

//Stack Dynamic using singly linked list
struct Node{
    char data;
    Node *next;
};

Node *topSingly = nullptr;

bool isEmptySingly(){
    if(topSingly == nullptr){
        return true;
    }
    return false;
}

void pushSingly(char data){
    Node *temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    if(isEmptySingly()){
        topSingly = temp;
    }
    else{
        temp->next = topSingly;
        topSingly = temp;
    }
}

void popSingly(){
    if(isEmptySingly()){
        cout<<"Stack Already Empty!";
    }
    else{
        Node *temp = topSingly;
        topSingly = topSingly->next;
        delete(temp);
    }
}

void displaySingly(){
    if(isEmptySingly()){
        cout<<"Stack Empty!";
    }
    else{
        Node *ptr = topSingly;
        while(ptr != nullptr){
            cout<<ptr->data;
            ptr = ptr->next;
        }
    }
}

char topElementSingly(){
    if(isEmptySingly()){
        cout<<"Stack Empty!"<<endl;
    }
    else{
        return topSingly->data;
    }
    return 0;
}


//Stack using array of size 100
#define size1 100
char mineStack[size1];
int top = -1;

bool isEmpty(){
    if(top<=-1){
        return true;
    }
    return false;
}

void push(char value){
    if(top>=size1-1){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        top++;
        mineStack[top] = value;
    }
}

void pop(){
    if(top>=0){
        top--;
    }
}

char topElement(){
    if(isEmpty()){
    }
    else{
        return mineStack[top];
    }
    return 0;
}

void display() {
   if(top>=0) {
      cout<<"Stack elements are:"<<endl;
      for(int i=top; i>=0; i--){
        cout<<mineStack[i]<<endl;
        cout<<endl;
      }
   } 
   else{
    cout<<"Stack is empty"<<endl;
   }
}
//end

//Stack of Int
#define size2 100
int topInt = -1;
int stackInt[size2];
bool isEmptyInt(){
    if(topInt<=-1){
        return true;
    }
    return false;
}

void pushInt(int value){
    if(topInt >= size2-1){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        topInt++;
        stackInt[topInt] = value;
    }
}

void popInt(){
    if(topInt>=0){
        topInt--;
    }
}

int topElementInt(){
    if(isEmptyInt()){
    }
    else{
        return stackInt[topInt];
    }
    return 0;
}

void displayInt() {
   if(topInt>=0) {
      cout<<"Stack elements are:"<<endl;
      for(int i=topInt; i>=0; i--){
        cout<<stackInt[i]<<endl;
        cout<<endl;
      }
   } 
   else{
    cout<<"Stack is empty"<<endl;
   }
}

//end



bool isPalindrome(string s){
    int length = s.size();
    for(int i = 0;i<length;i++){
        push(s[i]);
    }
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] != topElement()){
            return false;
        }
        pop();
        i++;
    }
    return true;
}

bool isPalindromeSingly(string s){
    int length = s.size();
    for(int i = 0;i<length;i++){
        pushSingly(s[i]);
    }
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] != topElementSingly()){
            return false;
        }
        popSingly();
        i++;
    }
    return true;
}

bool isPalindromeDoubly(string s){
    int length = s.size();
    for(int i = 0;i<length;i++){
        pushDoubly(s[i]);
    }
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] != topElementDoubly()){
            return false;
        }
        popDoubly();
        i++;
    }
    return true;
}

bool checkSinglyTyped(string s){
    int length = s.size();
    for (size_t i = 0; i < length; i++)
    {
        if(isEmpty()){
            if(s[i] == '(' || s[i] == ')'){
                push(s[i]);
            }
        }
        else if(s[i] == ')'){
            pop();
        }
        else{
            push(s[i]);
        }
    }
    if(isEmpty()){
        return true;
    }
    else{
        return false;
    }
}

int priorityMultipleBraces(char data){
    if(data == '(' || data == ')'){
        return 1;
    }
    if(data == '{' || data == '}'){
        return 2;
    }
    if(data == '[' || data == ']'){
        return 3;
    }
    return 0;
}

bool checkMultipleTyped(string s){
    int length = s.size();
    for (size_t i = 0; i < length; i++)
    {
        if(isEmpty()){
        push(s[i]);
        }
        else if((topElement() == '(' && s[i] == ')') || (topElement() == '{' && s[i] == '}') || (topElement() == '[' && s[i] == ']')){
            pop();
        }
        else{
            if(priorityMultipleBraces(s[i]) <= priorityMultipleBraces(topElement())){
                push(s[i]);
            }
            else{
                return false;
            }
        }
    }
    if(isEmpty()){
        return true;
    }
    else{
        return false;
    } 
}

int priority(char x){
    if(x == '('){
        return 0;
    }
    if(x == '+' || x == '-'){
        return 1;
    }
    if(x == '*' || x == '/'){
        return 2;
    }
    if(x == '^'){
        return 3;
    }
    return 0;
}

void postfixExpression(string s){
    for (int i = 0; i < s.size(); i++)
    {
        if(isalnum(s[i])){
            cout<<s[i];
        }
        else if(s[i] == '('){
            push(s[i]);
        }
        else if(s[i] == ')'){
            while(topElement() != '('){
                cout<<topElement();
                pop();
            }
            pop();
        }
        else{
            while(priority(topElement()) >= priority(s[i])){
                cout<<topElement();
                pop();
            }
            push(s[i]);
        }
    }
    while(top != -1){
        cout<<topElement();
        pop();
    }
}

int postfixEvaluate(string s){
    for (int i = 0; i < s.size(); i++)
    {
        if(isdigit(s[i])){
            pushInt(s[i] - '0');
        }
        else{
            int x = topElementInt();
            popInt();
            int y = topElementInt();
            popInt();
            if(s[i] == '+'){
                pushInt(y+x);
            }
            else if(s[i] == '-'){
                pushInt(y-x);
            }
            else if(s[i] == '*'){
                pushInt(y*x);
            }
            else if(s[i] == '/'){
                pushInt(y/x);
            }
            else{
                pushInt(pow(y,x));
            }
        }
    }
    return topElementInt();
    
}

int main(){
    // postfixExpression("a+b*c+(d*e+f)*g");
    // cout<<checkMultipleTyped("");
    // postfixExpression("7+(5-3*6)+8/2+9");
    cout<<postfixEvaluate("7536*-+82/+9+");
}

