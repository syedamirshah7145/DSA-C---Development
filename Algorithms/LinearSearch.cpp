#include <iostream>

using namespace std;


//using iterative approach
int linearSearch(int arr[4],int key,int size){
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

//using recursive approach
int recursiveLinearSearch(int arr[],int key,int size){
    if(size == -1){
        return -1;
    }
    else if(key == arr[size-1]){
        return size-1;
    }
    else{
        return recursiveLinearSearch(arr,key,size-1);
    }
}

int main(){
    int arr[] = {2,4,2};
    int key = 4;
    int size = sizeof(arr)/4;
    cout<<recursiveLinearSearch(arr,key,size);

}