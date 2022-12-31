#include <iostream>

using namespace std;

void insertionSort(int arr[],int size){
    int i,j;
    for (i = 1; i < size; i++)
    {
        j = i;
        while(j>0 && arr[j-1] > arr[j]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}

int main(){
    int arr[] = {1,4,7,3,9,5,10};
    insertionSort(arr,7);
    for (int i = 0; i < 7; i++)
    {
        cout<<arr[i]<<endl;
    }
    
}