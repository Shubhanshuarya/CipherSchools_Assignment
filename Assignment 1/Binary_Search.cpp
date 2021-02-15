#include<iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int element){
    
    while( start <= end){
        int m = start + (end - start) / 2;

        // Check element is present at mid
        if(arr[m] == element){
            return m;
        }



        // If element is greater, ignore left half
        if(arr[m]  < element){
            start += m;
        }else{
            end = m - start;
        }

    }

    // If we reach here, then element was not preseent
    return -1;

}

int main(){

    int arr[] = { 2, 3, 4, 10, 40 }; 

    int x = 10; 

    int n = sizeof(arr) / sizeof(arr[0]); 

    int result = binarySearch(arr, 0, n - 1, x); 

    if(result == -1){
        cout << "Element is not Present";
    }else{
        cout << "Element is present at index " << result;
    }

    return 0;
}