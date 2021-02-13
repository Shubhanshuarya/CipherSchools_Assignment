#include<iostream>
using namespace std;

// This function will return index of key which is present in given array, otherwise return -1
int search(int arr[], int l, int r, int key){

    if(l > r){
        return -1;
    }

    // Calculate mid of the array
    int mid = (l + r) / 2;

    // Check whether key is present at mid point of array, then return the mid value
    if(arr[mid] == key){
        return mid;
    }

    // if arr[l...mid] is sorted
    if(arr[l] <= arr[mid]){

        // as this subarray is sorted, we can quickly check if key lies in half or other half
        if(key >= arr[l] && key <= arr[mid]){
            return search(arr, l, mid-1, key);
        }
        /* If key not lies in first half subarray, dvide other half into two subarrays, such thta we can
        quickly check if key liews in other half*/
        return search(arr, mid+1, r, key);
    }

    // If arr[l...mid] first subarray is not sorted, then arr[mid...r] must be sorted subarray*/
    if(key >= arr[mid] && key <= arr[r]){
        return search(arr, mid+1, r, key);
    }

    return search(arr, l, mid-1, key);
}

int main(){
    int arr[] = { 4, 5, 6, 7, 8, 9, 1, 2, 3 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int key = 6; 
    int i = search(arr, 0, n - 1, key); 

    if(i != -1){
        cout << "Index: " << i << endl;
    }else{
        cout << "Key not Found";
    }
    return 0;
}

// T.C. => O(log n)