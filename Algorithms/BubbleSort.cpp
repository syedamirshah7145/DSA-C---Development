#include <iostream>

using namespace std;

void bubbleSort(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    } 
}

void recursiveBubbleSort(int arr[],int size){
    if (size == 1){
        return;
    }
    for (int i = 0; i < size-1; i++)
    {
        if(arr[i] > arr[i+1]){

            //swap
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
    recursiveBubbleSort(arr,size-1);
}

int main(){
    int arr[] = {9,34,2,5,1,3,6};
    // bubbleSort(arr,7);
    int size1 = sizeof(arr)/sizeof(arr[0]);
    recursiveBubbleSort(arr,size1);
    for (int i = 0; i < 7; i++)
    {
        cout<<arr[i]<<endl;
    }
    
}