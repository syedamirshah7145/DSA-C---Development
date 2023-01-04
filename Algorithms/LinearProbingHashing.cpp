#include <iostream>
#include <stdio.h>
#include <stdlib.h> 

using namespace std;

#define SIZE 20

class linearProbing{
    public:
    int p[SIZE];

    linearProbing(){
        for (int i = 0; i < SIZE; i++)
        {
            p[i] = -1;
        }
        
    }

    void insert(int key){
        int hash_key = key%SIZE;
        for (int i = 0; i < SIZE; i++)
        {
            int index = (hash_key+i)%SIZE;
            if(p[index] == -1){
                p[index] = key;
                break;
            }
            if(i == SIZE){
                cout<<"Value can't be inserted!";
                break;
            }
        }
    }

    void search(int key){
        int hash_key = key%SIZE;
        for (int i = 0; i < SIZE; i++)
        {
            int index = (hash_key+i)%SIZE;
            if(p[index] == key){
                cout<<"Value found at index:"<<index<<endl;
                break;
            }
            if(i == SIZE){
                cout<<"Value not found!";
                break;
            }
        }
    }
};

int main(){
    linearProbing *l = new linearProbing;
    l->insert(12);
    l->insert(3);
    l->insert(23);
    l->search(12);
    l->search(23);
    l->search(3);
    

}