//declaring new node, always use = new Node otherwise issue; mistake 1

#include <iostream>
#include <stdlib.h>

using namespace std;

string dialog = "1. Push.\n2. Append.\n3. Delete First Node.\n4. Delete Last Node.\n5. Delete Nth Node From Last.\n6.Display List.\n7.Search.\n8.insert after specific value.\n9.delete after specific value.\n0. Exit.\n";
struct Node *head = nullptr;
struct Node{
    int data;
    struct Node *next;
};



void push(struct Node** head,int nodeData){

    //create new node for holding data
    struct Node* newNode = new Node;

    //insert data in new node
    newNode->data = nodeData;

    //set new node as head
    newNode->next = (*head);

    //now head will point to newNode
    (*head) = newNode;
}

void append(struct Node** head,int nodeData){
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

void deleteFirstNode(struct Node** head){
    if(*head == nullptr){
        cout<<"Head is null";
    }

    struct Node* tempNode = *head;
    *head = (*head)->next;
    delete tempNode;
}

void deleteFromLast(struct Node** head){
    if(*head == nullptr){
        cout<<"head is null";
    }
    if((*head)->next == nullptr){
        delete(*head);
        head = nullptr;
    }

    struct Node* secondLast = *head;
    while(secondLast->next->next != nullptr){
        secondLast = secondLast->next;
    }
    delete(secondLast->next);
    secondLast->next = nullptr;
}

void deleteNthNodeFromLast(Node** head,int n){
    if(*head == nullptr){
        cout<<"Head is null";
    }

    Node *p = *head;
    int len = 0;
    while(p != nullptr){
        len++;
        p = p->next;
    }

    int fromStart = len-n;
    if(len-n<0 || n==0){
        cout<<"size of list is small or wrong nth index"<<endl;
    }
    else{
        if(fromStart==0){
             *head = (*head)->next;
        }
        else{
             p = *head;
             int i = 0;
             while(p!=nullptr){
             i++;
             if(i==fromStart){
                p->next = p->next->next;
                break;
             }
        p = p->next;
    }
    }
    }
}

void displayList(struct Node *head){
    while(head != nullptr){
        cout<<head->data<<endl;
        head = head->next;
    }
}

void search(struct Node* head,int targetData){
    while(head != nullptr){
        if(head->data == targetData){
            cout<<head->data<<endl;
        }
        head = head->next;
    }
}

void insertAfterSpecificValue(struct Node* head,int targetData,int data){
    while(head != nullptr){
        if(head->data == targetData){
            struct Node *dataHolder = new Node;
            dataHolder->data = data;
            dataHolder->next = nullptr;
            dataHolder->next = head->next;
            head->next = dataHolder;
            return;
        }
        head = head->next;
    }
}

void insertBeforeSpecificValue(struct Node** head,int targetData,int data){
    struct Node *temp = nullptr;
    struct Node *headcopy = *head;
    if((*head)->data == targetData){
        struct Node *dataHolder = new Node;
        dataHolder->data = data;
        dataHolder->next = nullptr;
        dataHolder->next = *head;
        *head = dataHolder;
        return;
    }
    else{
        while(headcopy != nullptr){
        if(headcopy->data == targetData){
            struct Node *dataHolder = new Node;
            dataHolder->data = data;
            dataHolder->next = nullptr;
            dataHolder->next = temp->next;
            temp->next = dataHolder;
            return;
        }
        temp = headcopy;
        headcopy = headcopy->next;
    }
    } 
}

void deleteAfterSpecificValue(struct Node* head,int targetData){
    while(head != nullptr){
        if(head->data == targetData){
            if(head->next != nullptr){
                delete(head->next);
                head->next = head->next->next;
                return;
            }  
        }
        head = head->next;
    }
}

void reverseListPrint(Node *head){
    if(head == NULL);
    return;

    cout<<head->data<<"\n";
    reverseListPrint(head->next);
    
}

int main(){
    
    int opt = 1;
    
    
while(opt!=0){
    int opt;
    cout<<dialog;
    cin>>opt;
    switch (opt)
        {
        case 1:
            cout<<"Enter value to be push";
            int value1;
            cin>>value1;
            push(&head,value1);
            cout<<"\n\n";
            break;
        case 2:
            cout<<"Enter value to be appended";
            int value2;
            cin>>value2;
            append(&head,value2);
            cout<<"\n\n";
            break;
        case 3:
            deleteFirstNode(&head);
            cout<<"\n\n";
            break;
        case 4:
            deleteFromLast(&head);
            cout<<"\n\n";
            break;
        case 5:
            cout<<"Enter index of value to be deleted from last";
            int value3;
            cin>>value3;
            deleteNthNodeFromLast(&head,value3);
            cout<<"\n\n";
            break;
        case 6:
            displayList(head);
            cout<<"\n\n";
            break;
        case 7:
            cout<<"Enter value to be find";
            int value4;
            cin>>value4;
            search(head,value4);
            cout<<"\n\n";
            break;
        case 8:
            int value6;int value7;
            cout<<"Enter target value\n";
            cin>>value6;
            cout<<"Enter value to be inserted\n";
            cin>>value7;
            insertAfterSpecificValue(head,value6,value7);
            break;
        case 9:
            int value10;int value11;
            cout<<"Enter target value\n";
            cin>>value10;
            cout<<"Enter value to be inserted\n";
            cin>>value11;
            insertBeforeSpecificValue(&head,value10,value11);
            displayList(head);
            break;
        case 10:
            int value5;
            cout<<"Enter target value\n";
            cin>>value5;
            deleteAfterSpecificValue(head,value5);
            break;
        //under construction
        // case 11:
        //     int value5;
        //     cout<<"Enter target value\n";
        //     cin>>value5;
        //     deleteBeforeSpecificValue(head,value5);
        //     break;
        case 0:
            exit(3);
        case 11:
            reverseListPrint(head);
            break;
        }  
}
    

}

