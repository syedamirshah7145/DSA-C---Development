#include <iostream>

using namespace std;

class Que{
    public:
    int *p;
    int size;
    int front;
    int rear;

    Que(int s){
        size = size;
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
        if((rear+1)%size == front){
            return true;
        }
        return false;
    }

    void Enqueue(int data){
        if(isFull()){
            return;
        }
        else{
            if(isEmpty()){
            front = rear = 0;
            }
            else{
                rear = (rear+1)%size;
            }
            p[rear] = data;
        }
    }

    int Dequeue(){
        if(isEmpty()){
            return -1;
        }
        else{
            int data = p[front];
            if(front == rear){
                front = rear = -1;
            }
            else{
                front = (front+1)%size;
            }
            return data;
        }
    }

    void display(){
        if(isEmpty()){
            return;
        }
        else{
            int f = front;
        int r = rear;
        while(f!=r){
            cout<<p[f]<<endl;
            f = (f+1)%size;
        }
            cout<<p[f];   
    }
        }
        
};

int main(){
    Que q1(5);
    q1.Enqueue(34);
    q1.Enqueue(343);
    q1.Dequeue();
    q1.Dequeue();
    q1.Dequeue();
    q1.display();

}