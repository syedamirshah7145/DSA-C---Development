#include <iostream>
using namespace std;

class Node {

    public:
    int data;
    Node *next;

    Node(){
        data = 0;
        next = nullptr;
    }

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class List {
    Node *head;
    public:
    List(){
        head = nullptr;
    }

    void reverseElements(){
        if(head == nullptr){
            cout<<"List already empty!";
        }
        Node *prev = nullptr;
        Node *next = nullptr;

        while(head != nullptr){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        head = prev;
    }

    Node* returnFromLast(Node *header,int index){
        Node *slow = header;
        Node *fast = header;
        if(header == nullptr){
            return slow = nullptr;
        }
        for (int i = 0; i < index; i++)
        {
            fast = fast->next;
        }
        if(fast == nullptr){
            return slow = nullptr;
        }
        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    void printList(){
        Node *temp = head;
        if(head == nullptr)
         cout<<"No data to display";
        else{
            while(temp != nullptr){
                cout<<temp->data<<endl;
                temp = temp->next;
            }
        }
    }

    void printReverseList(){
        if(head == nullptr){
            cout<<"Sorry No data to display!";
            return;
        }
        Node *tail = head;
        Node *temp = head;
        while(tail->next != nullptr){
            tail = tail->next;
        }

        while(tail != head){
            while(temp->next != tail){
                temp = temp->next;
            }
            cout<<tail->data<<endl;
            tail = temp;
            temp = head;
        }
        cout<<head->data;
    }

    void insert(int data){
        Node *newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
        }
        else{
            Node *temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deleteFromLast(int index){
        if(head == nullptr){
            cout<<"No data to del!"<<endl;
        }
        else{
            Node *fast = head;
            Node *slow = head;
            for (int i = 0; i < index; i++)
            {
                fast = fast->next;
            }
            //incase of only 1 node
            if(fast == nullptr){
                Node *temp = slow;
                head = slow->next;
                delete temp;
                return;
            }

            while(fast->next != nullptr){
                slow = slow->next;
                fast = fast->next;
            }
            Node *temp = new Node();
            temp = slow->next;
            slow->next = slow->next->next;
            delete temp;
        }
    }

    void deleteDuplicates(){
        if(head == nullptr){
            cout<<"No data to perform operation!";
        }
        Node *headcopy = head;
        Node *p1 = nullptr;
        Node *p2 = nullptr;
        while(headcopy != nullptr){
            p2 = headcopy;
            p1 = headcopy->next;
            while(p1 != nullptr){
                if(headcopy->data == p1->data){
                    Node *temp = p1;
                    p2->next = p1->next;
                    p1 = p1->next;
                    delete temp;
                }
                else{
                    p2 = p1;
                    p1 = p1->next;
                }
            }
            headcopy = headcopy->next;
        }
    }

    void swap(int index){
        Node *headcopy = head;
        Node *currentx = nullptr;
        Node *preCurrentx = nullptr;
        Node *currenty = nullptr;
        Node *preCurrenty = nullptr;
        bool flag = true;
        for (int i = 0; i < index; i++)
        {
            if(flag){
                currentx = head;
                flag = false;
            }
            else{
                preCurrentx = currentx;
                currentx = currentx->next;
            }
            
        }

        preCurrenty = returnFromLast(headcopy ,index);

        if(preCurrenty == nullptr){
            currenty = head;
        }
        else{
            currenty = preCurrenty->next;
        }

        if(preCurrentx != nullptr){
            preCurrentx->next = currenty;
        }
        else{
            head = currenty;
        }

        if(preCurrenty != nullptr){
            preCurrenty->next = currentx;
        }
        else{
            head = currentx;
        }

        Node *temp = currenty->next;
        currenty->next = currentx->next;
        currentx->next = temp;

    }

    void deleteData(int data){
        if(head == nullptr){
            cout<<"List Empty Already!"<<endl;
        }
        else if(head->data == data){
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        else{
            Node *p1 = head;
            Node *p2 = nullptr;
            while(p1->next != nullptr){
                if(p1->next->data == data){
                    p2 = p1;
                    p1 = p1->next;
                    p2->next = p1->next;
                    delete p1;
                    break;
                }
                p1 = p1->next;
            }
        }
    }
};

int main(){
    List l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);
    l.insert(6);
    l.swap(6);
    l.printList();
}