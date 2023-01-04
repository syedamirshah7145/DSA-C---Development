#include <iostream>

using namespace std;

void selectionSort(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        int minIndex = i;
        for (int j = i; j < size; j++)
        {
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        //swapping part
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    } 
}


int minIndex(int arr[],int starting,int ending){
    if(starting == ending){
        return starting;
    }
    int k = minIndex(arr,starting+1,ending);
    return (arr[starting]< arr[k]) ? starting : k;
}

void recursiveSelectionSort(int arr[],int index,int size){
    if(index == size){
        return;
    }

    int k = minIndex(arr,index,size-1);

    if(k != index){
        int temp = arr[index];
        arr[index] = arr[k];
        arr[k] = temp;
    }

    recursiveSelectionSort(arr,index+1,size);
}



int main(){
    int arr[] = {1,4,2,3,7,9,6};
    // selectionSort(arr,7);
    recursiveSelectionSort(arr,0,7);
    for (int i = 0; i < 7; i++)
    {
        cout<<arr[i]<<endl;
    }
    

}