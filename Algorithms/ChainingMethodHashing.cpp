#include <iostream>

using namespace std;

#define size 10

struct node{
    int data;
    node *next;
};

struct node *chain[size];

void init(){
    for (int i = 0; i < size; i++)
    {
        chain[i] = nullptr;
    }
}

void insert(int val){
    struct node *newNode = new node;
    newNode->data = val;
    newNode->next = nullptr;

    int index = val%size;

    if(chain[index] == nullptr){
        chain[index] = newNode;
    }
    //in case of collision
    else{
        node *temp = chain[index];
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(){
    for (int k = 0; k < size; k++)
    {
        node *current = chain[k];
        while(current){
            cout<<current->data<<"\t";
            current = current->next;
        }
        cout<<endl;
    }
}

int main(){
    init();
    insert(21);
    insert(11);
    insert(31);
    insert(212);
    display();
}