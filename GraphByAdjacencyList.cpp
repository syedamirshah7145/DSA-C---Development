#include <iostream>

using namespace std;

struct edge{
    int id;
    edge *next;
};

struct node{
    int id;
    edge *head;
    edge *tail;
    node *next;    
}*head = nullptr,*tail = nullptr;

void insertVertex(int id){
    node *temp = new node;
    temp->id = id;
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

bool checkVertexExist(int id){
    node *temp = head;
    while(temp->id != id && temp != tail){
        temp = temp->next;
    }
    if(temp->id == id){
        return true;
    }
    return false;
}




int main(){
    insertVertex(0);
    insertVertex(2);
    insertVertex(0);
    cout<<checkVertexExist(0);
}