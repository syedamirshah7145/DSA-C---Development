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

    void selectionSort(){
        Node *p1 = head;
        Node *p2 = head;
        Node *min;
        while(p1 != nullptr){
            p2 = p1;
            min = p2;
            while(p2 != nullptr){
                if(min->data > p2->data){
                    min = p2;
                }
                p2 = p2->next;
            }

            //Swapping Values
            int temp = p1->data;
            p1->data = min->data;
            min->data = temp;
            p1 = p1->next;
        }
    }
};

int main(){
    LinkedList *l = new LinkedList(23);
    l->append(32);
    l->append(42);
    l->append(20);
    l->append(21);
    l->append(22);
    l->selectionSort();
    l->display();
}