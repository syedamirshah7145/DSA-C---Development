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

int main(){
    int arr[] = {1,4,2,3,7,9,6};
    selectionSort(arr,7);
    for (int i = 0; i < 7; i++)
    {
        cout<<arr[i]<<endl;
    }
    

}