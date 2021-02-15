// 1. Create an array arr3[] with size of n1+n2
// 2. Simultaneously traverse arr1[] and arr2[]
// Pick smaller of cuurent elements in arr1[] and arr2[], copy
// this smaller element to next posiition in arr3[] and move
// ahead in arr3[] and the array whose element is picked
// 3. If there are remaining elements in arr1[] or arr2[], copy them also in arr3[]

#include<iostream>
using namespace std;

mergeArrays(int arr1[], int arr2[], int n1, int n2, int arr3[]){

    int i = 0, j = 0, k = 0;

    // Traversing both arrays
    while(i < n1 && j < n2){

        // Check if current elemt of first array is smaller the current element of second arra
        // if yes, store first array element and increment first array index. 
        // Otherwise, do same with second array
        if(arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }

    // Store remaining elements of first array
    while(i < n1){
        arr3[k++] = arr1[i++];
    }

    // store remaining elements of second array
    while(j < n2){
        arr3[k++] = arr2[j++];
    }

}

int main() 
{ 
    int arr1[] = {1, 3, 5, 7}; 
    int n1 = sizeof(arr1) / sizeof(arr1[0]); 
  
    int arr2[] = {2, 4, 6, 8}; 
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[n1+n2];
    mergeArrays(arr1, arr2, n1, n2, arr3);

    cout << "Arrau after merging" << endl;

    for (int i=0; i < n1+n2; i++) 
        cout << arr3[i] << " "; 

    return 0;

}