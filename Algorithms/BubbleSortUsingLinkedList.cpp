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

    void bubbleSort(){
        Node *p1 = head;
        Node *p2 = head;
        Node *p3 = head;
        while(p3->next != nullptr){
            p3 = p3->next;
        }
        while(p1 != nullptr){
            while(p2 != p3){
                if(p2->data > p2->next->data){
                    int temp = p2->data;
                    p2->data = p2->next->data;
                    p2->next->data = temp;
                }
                if(p2->next == p3){
                    break;
                }
                p2 = p2->next;
            }
            p3 = p2;
            p2 = head;
            p1 = p1->next;
        }
    }
};

int main()
{
    LinkedList *l = new LinkedList(12);
    l->append(13);
    l->append(1123);
    l->append(1233);
    l->append(3);
    l->bubbleSort();
    l->display();
}