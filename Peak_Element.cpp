// What is Peak Element?

// An array element is the peak element if it is not smaller than its neighbour. 
// For Corner elements, we nee to consider the only one neighbour

#include<iostream>
using namespace std;

// Cases
// 1. If the array is in increasing order then peak element will be last one
// 2. If the array is in decreasing order then peak element will be first one
// 3. if all the elements are same, then all elements are peak elements

// Let's Discuss out approach
// 1. If first element is greater than second and last element is greater than second last element
// print the respective element otherwise terminate program
// 2. else traverse the array from second index to last second index
// 3. compare an element with its neighbour such as arr[i] > arr[i-1] && arr[i] > arr[i+1]
// then retrun the respective element and terminate the program

int findPeak(int arr[], int size){
    // if arr have one element only
    if(size == 1){
        return arr[0];
    }
    if(arr[0] >= arr[1])
        return arr[0];
    if(arr[size-1] >= arr[size-2])
        return arr[size-1];
    
    // Check all elements starting from 2nd index to last 2nd index
    for(int i = 1; i < size-1; i++){
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
            return arr[i];
        }
    }
}

int main(){ 
    int arr[] = { 1, 3, 20, 4, 1, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findPeak(arr, n);
    return 0;
}