#include <iostream>

using namespace std;

class stack{
    public:
    int front,rear;
    int *p;
    int size;
    stack(){
        size = 100;
        p = new int[size];
        front = rear = -1;
    }
    stack(int x){
        size = x;
        p = new int[size];
        front = rear = -1;
    }

    bool isEmpty(){
        if(front == -1 || rear == -1){
            return true;
        }
        return false;
    }

    bool isFull(){
        if(rear == size-1){
            return true;
        }
        return false;
    }

    void push(int x){
        if(isFull()){
            return;
        }
        else if(isEmpty()){
            front = rear = 0;
            p[rear] = x;
        }
        else{
            p[++rear] = x;
        }
    }

    int pop(){
        if(isEmpty()){
            return 0; 
        }
        else{
            int temp = p[rear];
            rear--;
            return temp;
        }
    }

    void display(){
        if(rear>=0) {
            cout<<"Stack elements are:"<<endl;
            for(int i=rear; i>=0; i--){
            cout<<p[i]<<endl;
            cout<<endl;
            }
        } 
    }
};

class queueUsingStack{
    public:
    stack s1;
    stack s2;

    void enqueue(int data){
        s1.push(data);
    }

    int dequeue(){
        while(!s1.isEmpty()){
            s2.push(s1.pop());
        }
        int temp = s2.pop();
        while(!s2.isEmpty()){
            s1.push(s2.pop());
        }
        return temp;
    }

    void display(){
        s1.display();
    }
};

int main(){
    queueUsingStack q1;
    q1.enqueue(5);
    q1.enqueue(6);
    cout<<q1.dequeue();
    cout<<q1.dequeue();
    q1.dequeue();
    q1.display();

}