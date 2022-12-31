#include <iostream>

using namespace std;

// Only works on sorted array
// Getting middle element and moving left and right according to value greater or lesser
// int convert double value to lesser value like 2.4 to 2
int BinarySearch(int arr[], int key, int s, int e)
{
    int mid = (s + e) / 2;
    while (s <= e)
    {
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            e = mid - 1;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        mid = (s + e) / 2;
    }
    return -1;
}

int recursiveBinarySearch(int arr[], int s, int e, int key)
{
    if (s > e) {
        return -1;
    }
    int mid = (s + e) / 2;
    if (key == arr[mid]){
        return mid;
    }
    else if (key < arr[mid]){
        return recursiveBinarySearch(arr, s, mid - 1, key);
    }
    else {
        return recursiveBinarySearch(arr, mid + 1, e, key);
    }
}

int main()
{
    int arr[] = {1, 2, 4, 7, 8, 9, 12, 13, 16, 17};
    cout << recursiveBinarySearch(arr, 0, 10, 2);
}