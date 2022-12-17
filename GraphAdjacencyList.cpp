#include <iostream>

using namespace std;

struct edge{
    int data;
    edge *next;
};

struct node{
    int data;
    edge *head;
    edge *tail;
    node *next;
};

node *head = nullptr;
node *tail = nullptr;

void insertVertex(int vdata){
    node *temp = new node;
    temp->data = vdata;
    temp->head = nullptr;
    temp->tail = nullptr;

    if(head == nullptr){
        temp->next = nullptr;
        head = tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
        tail->next = nullptr;
    }
}

bool checkVName(int data){
    node *temp = head;
    while(temp->data != data && temp!=tail){
        temp = temp->next;
    }
    if(temp == nullptr){
        cout<<"Not found!";
        return false;
    }
    return true;
}

void addEdge(int vData,int eData){
    node *temp = head;
    while(temp->data != vData && temp != nullptr){
        temp = temp->next;
    }
    if(temp == nullptr){
        cout<<"Not Found!";
        return;
    }
    if(temp != nullptr && checkVName(eData)){
        edge *etemp = new edge;
        etemp->data = eData;
        etemp->next = nullptr;
        if(temp->head == nullptr){
            temp->head = temp->tail = etemp;
        }
        else{
            temp->tail->next = etemp;
            temp->tail = etemp;
        }
    }
}

void display(){
    node *temp = head;
    edge *etemp;
    while(temp != nullptr){
        cout<<temp->data<<" : ";
        etemp = temp->head;
        while(etemp != nullptr){
            cout<<etemp->data<<" , ";
            etemp = etemp->next;
        }
        cout<<endl;
        temp = temp->next;
    }
}

int main(){
    insertVertex(1);
    insertVertex(2);
    insertVertex(0);
    addEdge(1,0);
    addEdge(0,1);
    addEdge(1,2);
    display();
}