#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

void display(Node *last){
    if(last == nullptr){
        cout<<"List is empty!";
        return;
    }
    Node *temp = last->next;
    cout<<temp->data<<endl;
    while(temp != last){
        temp = temp->next;
        cout<<temp->data<<endl;
    }
}

void insertAtEnd(Node **last,int data){
    if((*last)==nullptr){
        struct Node *temp = new Node;
        temp->data = data;
        (*last) = temp;
        (*last)->next = (*last);
    }
    else{
        struct Node *temp = new Node;
        temp->data = data;
        temp->next = (*last)->next;
        (*last)->next = temp;
        (*last) = temp;
    }
}

Node* returnprevsmaller(Node *last){
    Node *traverser = last;
    Node *smaller = traverser;
    Node *p1 = nullptr;
    do{
        if(smaller->data > traverser->next->data){
            p1 = traverser;
            smaller = traverser->next;
        }
        traverser = traverser->next;
    }
    while(traverser->next != last);
    return p1;
}


void insertElement(Node *smaller,Node **merge){
    if((*merge) == nullptr){
        (*merge) = smaller;
        (*merge)->next = (*merge);
    }
    else{
        smaller->next = (*merge)->next;
        (*merge)->next = smaller;
        (*merge) = (*merge)->next;
    }
}
//delete smaller from previous list and return smaller node to insert in new merge list
void deleteAndReturnSmaller(Node *preSmaller,Node **even,Node **merge){
    if(preSmaller == nullptr && (*even)->next == (*even)){
        Node *smaller = *even;
        insertElement(smaller,&(*merge));
        *even = nullptr;
        delete((*even));
    }
    else if(preSmaller == nullptr){
        Node *smaller = *even;
        Node *traverse = smaller->next;
        while(traverse->next != smaller){
            traverse = traverse->next;
        }
        traverse->next = smaller->next;
        (*even) = traverse;
        insertElement(smaller,&(*merge));
    }
    else{
        Node *smaller = preSmaller->next;
        preSmaller->next = smaller->next;
        insertElement(smaller,&(*merge));
    }
}

void merge(Node **even,Node **odd,Node **merge1){
    Node *evenCopy = (*even);
    bool flageven = false;
    bool flagodd = true;
    while((*even) != nullptr || (*odd) != nullptr){
        if((*odd) != nullptr && flagodd)
        {
            Node *preSmaller = returnprevsmaller((*odd));
            deleteAndReturnSmaller(preSmaller,&(*odd),&(*merge1));
        }

        if((*even) != nullptr && flageven){
            Node *preSmaller = returnprevsmaller((*even));
            deleteAndReturnSmaller(preSmaller,&(*even),&(*merge1));
        }

        if(flagodd){
            flageven = true;
            flagodd = false;
        }
        else{
            flageven = false;
            flagodd = true;
        }
    }
}

int main(){
    Node *odd = nullptr;
    Node *even = nullptr;
    Node *merge1 = nullptr;
    insertAtEnd(&even,12);
    insertAtEnd(&even,2);
    insertAtEnd(&even,36);
    insertAtEnd(&odd,23);
    insertAtEnd(&odd,43);
    insertAtEnd(&odd,25);
    insertAtEnd(&odd,35);
    merge(&even,&odd,&merge1);

    display(merge1);
    cout<<endl;
    display(even);

}