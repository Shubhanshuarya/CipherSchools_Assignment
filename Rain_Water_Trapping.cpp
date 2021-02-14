// Approach

/*
    1. Traverse the array from start to end
    2. For every element, traverse the array from start to that index 
    and find the maximum height(a) and traverse the array from the current
    index to end and find the maximum height(b)
    3. The amount of water that will be stored in this column is min(a, b) - array[i],
    add this value to total amount of water stored
    4. Print total water stored
    
*/

#include<iostream>
using namespace std;

int maxWater(int arr[], int size){

    // To store the maximum water
    int res = 0;

    // For every element of the array
    for(int i = 1; i < size; i++){

        // Find the maximum element on left side
        int left = arr[i];
        for(int j = 0; j < i; j++){
            left = max(left, arr[j]);
        }

        // FInd the maximum element on Right side
        int right = arr[i];
        for(int j = i+1; j<size; j++){
            right = max(right, arr[j]);
        }

        res = res + (min(left, right) - arr[i]);
    }

    return res;

}

int main(){

    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; 
    int n = sizeof(arr)/sizeof(arr[0]); 

    cout << maxWater(arr, n);

    return 0;
}

// T.C. => O(n * n)