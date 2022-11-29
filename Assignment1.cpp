#include <iostream>
#include <malloc.h>

using namespace std;


void menu(){
    cout 
    << "0. Display list" << endl
    << "1. Display Reverse List" << endl
    << "2. Reverse List" << endl
    << "3. Remove Repeated Values from List" <<endl
    << "4. Finding Interection of Two Linked Lists" << endl
    << "5. Delete Nth Node From Last" << endl
    << "6. Swap Node having index from start and index from last"<<endl
    << "7. Merge into one,first from odd and then from even(Circular Linked List)"<<endl
    << "-1.Exit" << endl;
}

struct Node{
    int data;
    Node *next;
};



// 1. Print Reverse Using Iteration (Completed).
void printReverseListUsingIteration(Node *head){
    Node *headcopy = head;
    Node *headcopy1 = head;
    Node *headcopy2 = head;
    Node *p1 = head;
    Node* p2 = nullptr;
    Node *tail = nullptr;

    while(headcopy1!=nullptr){
        tail = headcopy1;
        headcopy1 = headcopy1->next;
    }
    while(head != nullptr){
        p1 = headcopy2;
        while(p1 != tail){
            if(p1->next->data == tail->data){
                cout<<tail->data<<"\n";
            }
            p2 = p1;
            p1 = p1->next;
        }
        tail = p2;
        head = head->next;
    }
    cout<<headcopy2->data;
}

//2. Reverse List Elements (Completed)
void reverseListElements(Node **head){
    if(*head == nullptr){
        cout<<"List Empty!";
        return;
    }
    struct Node* prev = nullptr;
    struct Node* next = nullptr;
    while(*head != nullptr){
        next = (*head)->next;
        (*head)->next = prev;
        prev = *head;
        *head = next;
    }
    *head = prev;
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


void displayList(struct Node *head){
    while(head != nullptr){
        cout<<head->data<<endl;
        head = head->next;
    }
}

//merge two lists
void merge(Node* head,Node* head1,Node **head3){
    while(head!=nullptr){
        append(&(*head3),head->data);
        head = head->next;
    }
    while(head1!=nullptr){
        append(&(*head3),head1->data);
        head1 = head1->next;
    }
}

void sort(Node *head){
    Node *current = head; 
    Node *headcopy = head;
    Node *p2;
    Node *index = nullptr;
    int temp;
    Node *temp1;
    while(current != NULL) {  
                //Node index will point to node next to current  
                index = current->next;  
                p2 = nullptr;
                while(index != NULL) {  
                    //If current node's data is greater than index's node data, swap the data between them  
                    if(current->data > index->data) {  
                        temp1 = current;
                        p2->next = p2->next->next;
                        index->next = temp1;
                        
                    }  
                    p2 = index;
                    index = index->next;  
                }  
                current = current->next;  
            }      
}

// 4. remove the repeated values (Completed)
void removeDuplicatesV2(Node *head){
    if(head == nullptr){
        cout<<"List Empty!";
        return;
    }
    Node *headcopy = head;
    Node *ptr1 = nullptr;
    Node *temp = new Node;
    Node *ptr2;
    while(head != nullptr){
        ptr2 = head;
        ptr1 = head->next;
        while(ptr1 != nullptr){
            if(head->data == ptr1->data){
                temp = ptr1;
                ptr2->next = ptr1->next;
                ptr1 = ptr1->next;
                delete(temp);
            }
            else{
                ptr2 = ptr1;
                ptr1 = ptr1->next;
            }
        }
        head = head->next;
    }
}


//5. find intersection of two linked lists (completed)
void intersection(Node *head,Node *head1){
    while(head != nullptr){
        Node *head1copy = head1;
        while(head1copy != nullptr){
            if(head->data == head1copy->data){
                cout<<head->data<<"\n";
            }
            head1copy = head1copy->next;
        }
        head = head->next;
    }
}

Node* nthpositionreturner(Node *head,int n){

    Node *fast = head;
    Node *slow = head;

    if(head == nullptr){
        return slow = nullptr;
    }

    for (int i = 0; i < n; i++){
        fast = fast->next;
    }
    if(fast == nullptr){
        return slow = nullptr;
    }
    while(fast->next != nullptr){
    slow = slow->next;
    fast = fast->next;
    }
    return slow;
}

void swapnthV2(Node **head,int n1,int n2){
    Node *headCopy = *head;
    Node *fromFirst = nullptr;
    bool flag = true;
    Node *fromLast = nullptr;
    Node *currentx;
    for(int i = 0;i<n1;i++){
        if(flag){
            fromFirst = nullptr;
            currentx = *head;
            flag = false;
        }
        else{
            fromFirst = currentx;
            currentx = currentx->next;
        }
    }

    fromLast = nthpositionreturner(headCopy,n2);
    Node *currenty;
    if(fromLast == nullptr){
        currenty = *head;
    }
    else{
        currenty = fromLast->next;
    }

    if(fromFirst!=nullptr){
        fromFirst->next = currenty;
    }
    else{
        *head = currenty;
    }

    if(fromLast!=nullptr){
        fromLast->next = currentx;
    }
    else{
        *head = currentx;
    }


    Node *temp = currenty->next;
    currenty->next = currentx->next;
    currentx->next = temp;
}


//6. Delete the nth node from last (Completed)
void deleteNthNodeFromLast(Node **head,int n){
    if(*head == nullptr){
        cout<<"List empty";
        return;
    }

    Node *fast = *head;
    Node *slow = *head;

    for (int i = 0; i < n; i++){
        fast = fast->next;
    }
    if(fast == nullptr){
        Node *temp = slow;
        *head = slow->next;
        delete temp;
        return;
    }
    while(fast->next != nullptr){
    slow = slow->next;
    fast = fast->next;
    }
    
    Node *temp = new Node;
    temp = slow->next;
    slow->next = slow->next->next;
    delete(temp); 
}

//circular
void displayCircular(Node *last){
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

void merge1(Node **even,Node **odd,Node **merge1){
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
//circular end here

int main(){
    // struct Node *even = new Node;
    // struct Node *odd = new Node;
    // struct Node *merge = new Node;
    // merge = nullptr;
    struct Node *head = new Node;
    head = nullptr;
    // even = nullptr;
    // odd = nullptr;

    
    // struct Node *list1 = new Node;
    // struct Node *list2 = new Node;
    // list1 = nullptr;
    // list2 = nullptr;

    // insertAtEnd(&even,32);
    // insertAtEnd(&even,44);
    // insertAtEnd(&even,34);
    // insertAtEnd(&even,22);
    // insertAtEnd(&even,18);

    // insertAtEnd(&odd,33);
    // insertAtEnd(&odd,83);
    // insertAtEnd(&odd,13);
    // insertAtEnd(&odd,5);

    // append(&list1,33);
    // append(&list1,44);
    // append(&list1,56);
    // append(&list1,34);
    // append(&list1,35);

    // append(&list2,42);
    // append(&list2,86);
    // append(&list2,44);
    // append(&list2,33);
    // append(&list2,30);


    append(&head,33);
    append(&head,44);
    append(&head,33);
    append(&head,34);
    append(&head,33);
    append(&head,355);
    append(&head,346);
    append(&head,332);
    swapnthV2(&head,2,2);
    displayList(head);

//     bool flag = true;
    
//    do
//    {
//         menu();
//         cout <<endl;

//         cout << "Enter choice:"<< endl;
//         int choice;
//         cin >> choice;
//         if (choice == -1){
//             flag = false;
//         } 

//         switch (choice)
//         {
//         case 0:
//             displayList(head);
//             break;
//         case 1:
//             printReverseListUsingIteration(head);
//             cout <<endl << "\n";
//             break;
//         case 2:
//             reverseListElements(&head);
//             cout << endl << "\n";
//             break;
//         case 3:
//             removeDuplicatesV2(head);
//             cout << endl << "\n";
//             break;
//         case 4:
//             intersection(list1,list2);
//             cout << endl << "\n";
//             break;
//         case 5:
//             int n;
//             cout<<"Enter nth index from last";
//             cin>>n;
//             deleteNthNodeFromLast(&head,n);
//             cout << endl << "\n";
//             break;
//         case 6:
//             int n1;
//             cout << "Enter nth node from start: ";
//             cin>>n1;
//             int n2;
//             cout << "Enter nth node from end: ";
//             cin >> n2;
//             swapnthV2(&head,n1,n2);
//             cout <<endl<< "\n";
//         case 7:
//             cout<<"Merge two lists(even & odd) into one(swapping)"<<endl;
//             cout<<"Even:"<<endl;
//             displayCircular(even);
//             cout<<"Odd:"<<endl;
//             displayCircular(odd);
//             merge1(&even,&odd,&merge);
//             cout<<"Merge:"<<endl;
//             displayCircular(merge);
//             cout<<endl;
//             break;
//         default:
//             break;
//         }
//    } while (flag);
}