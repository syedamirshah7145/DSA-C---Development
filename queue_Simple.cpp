#include <iostream>

using namespace std;

//using singly linked list
struct NodeSingly{
    int data;
    NodeSingly *next;
};

class QueueSingly{
    public:
    NodeSingly *front,*rear;
    QueueSingly(){
        front = rear = nullptr;
    }

    void enqueue(int data){
        NodeSingly *temp = new NodeSingly;
        temp->data = data;
        temp->next = nullptr;
        if(isEmpty()){
            front = rear = temp;
        }
        else{
            rear->next = temp;
            rear = temp;
        }
    }

    bool isEmpty(){
        if(front == nullptr){
            return true;
        }
        return false;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Already Empty!"<<endl;
        }
        else{
            NodeSingly *temp = front;
            front = front->next;
            delete(temp);
        }
    }

    void display(){
        
        if(isEmpty()){
            cout<<"Nothing to Display!"<<endl;
        }
        else{
            NodeSingly *temp = front;
            while(temp != nullptr){
            cout<<temp->data<<endl;
            temp = temp->next;
            }
        }
    }
};



class QueueArray{
    public:
    int size;
    int *p;
    int front;
    int rear;

    QueueArray(){
        size = 100;
        p = new int[size];
        front = -1;
        rear = -1;
    }

    QueueArray(int x){
        int size = x;
        p = new int[size];
        front = -1;
        rear = -1;
    }

    void Enqueue(int x){
        if(isFull()){
            cout<<"No space"<<endl;
        }
        else{
            if(isEmpty()){       
                front = 0;
            }
            p[++rear] = x;
        }
    }

    void display(){
        if(isEmpty()){
            cout<<"Already empty!"<<endl;
        }
        else{
            for (int i = 0; i <= rear; i++){
                cout<<p[i]<<endl;
            }
        }
    }

    int Dequeue(){
        if(isEmpty()){
            cout<<"Already Empty!"<<endl;
        }
        else{
            int x = p[front];
            if(front == rear){
                front = rear = -1;
            }
            else{
                for (int i = 0,j = 1; i <= rear; i++,j++)
                {
                    p[i] = p[j];
                }
                rear--;               
            }
            return x;
        }
    }

    bool isEmpty(){
        if(rear == -1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(){
        if(rear == size-1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    QueueSingly q1;
    q1.enqueue(4);
    q1.dequeue();
    cout<<q1.isEmpty();
    q1.display();

}