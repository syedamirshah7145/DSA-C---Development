#include <iostream>

using namespace std;

class doubleSidedQue{
    public:
    int size;
    int *p;
    int front;
    int rear;

    doubleSidedQue(int s){
        size = s;
        p = new int[size];
        front = rear = -1;
    }

    bool isEmpty(){
        if(front == -1){
            return true;
        }
        return false;
    }

    bool isFull(){
        if(front == 0 && rear == size-1){
            return true;
        }
        return false;
    }

    void enqueueFront(int data){
        if(isFull()){
            return;
        }
        if(isEmpty()){
            front = rear = 0;
            p[front] = data;
        }
        else{
            if(front != 0){
                front = front-1;
                p[front] = data;
            }
            else{
                for (int i = rear; i >= front; i--){
                p[rear+1] = p[rear];
                }
                rear = rear+1;
                p[front] = data;
            }
        }
    }

    int dequeueFront(){
        if(isEmpty()){
            return 0;
        }
        if(front == rear){
            int temp = p[front];
            front = rear = -1;
            return temp;
        }
        else{
            int temp = p[front];
            front = front+1;
            return temp;
        }
    }

    void enqueueRear(int data){
        if(isFull()){
            return;
        }
        if(isEmpty()){
            front = rear = 0;
            p[front] = data;
        }
        else{
            if(rear != size-1){
                p[++rear] = data;
            }
            else{
                for (int i = front; i <= rear; i++)
                {
                    p[i-1] = p[i];
                }
                front = front-1;
                p[rear] = data;
            }
        }
    }

    int dequeueRear(){
        if(isEmpty()){
            return 0;
        }
        else{
            int temp = p[rear];
            rear = rear-1;
            return temp;
        }
    }

    void display(){
        if(isEmpty()){
            return;
        }
        else{
            int f = front;
            int r = rear;
            while(f != r){
            cout<<p[f]<<endl;
            f++;
            }
            cout<<p[f];
        }
    }
};

int main(){
    doubleSidedQue q1(100);
    q1.enqueueFront(123);
    q1.enqueueFront(234);
    q1.dequeueFront();
    q1.enqueueRear(24);
    q1.enqueueRear(34);
    q1.dequeueRear();
    q1.enqueueFront(45);
    q1.display();
}