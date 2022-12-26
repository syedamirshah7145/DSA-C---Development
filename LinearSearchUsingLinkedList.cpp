#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
public:
    Node *head = new Node;

    LinkedList(int data)
    {
        head->next = nullptr;
        head->data = data;
    }

    void append(int nodeData)
    {
        struct Node *newNode = new Node;
        struct Node *last = head;
        newNode->data = nodeData;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        while (last->next != nullptr)
        {
            last = last->next;
        }

        last->next = newNode;
        return;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    bool linearSearch(int key){
        Node *temp = head;
        while(temp != nullptr){
            if(temp->data == key){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    bool recursiveLinearSearch(Node *head,int key){
        if(head == nullptr){
            return false;
        }
        if(head->data == key){
            return true;
        }
        else{
            return recursiveLinearSearch(head->next,key);
        }
    }
};

main()
{
    LinkedList *l = new LinkedList(12);
    l->append(1);
    l->append(23);
    l->display();
    cout<<l->recursiveLinearSearch(l->head,23);
    cout<<l->recursiveLinearSearch(l->head,1);
}