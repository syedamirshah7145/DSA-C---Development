#include <iostream>

using namespace std;

class Que{
    public:
    int size;
    int *p;
    int front;
    int rear;

    Que(){
        size = 100;
        p = new int[size];
        front = -1;
        rear = -1;
    }

    Que(int x){
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
                front = rear = 0;
                p[rear] = x;
            }
            else{
                int j = rear;
                while(p[j] <= x && j >= 0){
                    p[j+1] = p[j];
                    j--;
                }
                j++;
                p[j] = x;
                rear++;
            }
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
    Que q1;
    Que q2(5);
    q1.Enqueue(5);
    q1.Enqueue(6);
    q1.Enqueue(54);
    q1.Enqueue(24);
    q1.Enqueue(24);
    q1.display();
}