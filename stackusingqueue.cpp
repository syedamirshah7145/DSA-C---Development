#include <iostream>

using namespace std;

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

    QueueArray(QueueArray &q){
        *p = *(q.p);
        front = q.front;
        rear = q.rear;
        size = q.size;
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
            return;
        }
        else{
            for (int i = 0; i <= rear; i++){
                cout<<p[i]<<endl;
            }
        }
    }

    int Dequeue(){
        if(isEmpty()){
            return 0;
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

class stackUsingQueue{
    public:
    QueueArray q1;
    QueueArray q2;

    void push(int data){
        q1.Enqueue(data);
    }

    int pop(){
        while(!q1.isEmpty()){
            if(q1.front == q1.rear){
                break;
            }
            q2.Enqueue(q1.Dequeue());
        }
        int temp = q1.Dequeue();
        q1 = q2;
        return temp;
    }

    void display(){
        q1.display();
    }
};

int main(){
    stackUsingQueue s1;
    s1.push(23);
    s1.push(234);
    s1.push(24);
    s1.pop();
    s1.display();
    

}