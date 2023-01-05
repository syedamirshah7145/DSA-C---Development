#include <iostream>

using namespace std;



void merge(int arr[],int left,int mid,int right){
    int i = left;
    int j = mid+1;
    int k = left;
    int size = (right-left)+1;
    int temp[size];

    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }
        else{
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i <= mid){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j <= right){
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int n = left; n <= right; n++){
        arr[n] = temp[n];
    }
}

void mergeSort(int arr[],int left,int right){
    if(left < right){
        int mid = (left+right)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

int main(){
    int a[8] = {6,4,5,2,4,6,8,7};
    mergeSort(a,0,4);
    for (int i = 0; i < 8; i++)
    {
        cout<<a[i]<<endl;
    }
    
}