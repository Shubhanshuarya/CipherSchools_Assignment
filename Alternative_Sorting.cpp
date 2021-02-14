// First element is first maximum and second element is first minimum and so on
#include<iostream>
#include<algorithm>
using namespace std;

void alternateSort(int arr[], int size){

    //1. Sort the given array
    sort(arr, arr+size);

    // 2. Printing last element of array as first and then first element and then second last element and then second element and so on

    int i = 0, j = size-1;

    while(i < j){

        cout << arr[j--] << " " << arr[i++] << " ";
    }

    // 3. If the total element in array is odd thenprint the last middle element
    if(size % 2 != 0){
        cout << arr[i];
    }

}

int main(){
    int arr[] = {1, 12, 4, 6, 7, 10}; 

    int n = sizeof(arr)/sizeof(arr[0]); 

    alternateSort(arr, n); 
    
    return 0;
}

// T.C. => O(n log n)