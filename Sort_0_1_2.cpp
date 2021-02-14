// Approach
// Count the number if 0s, 1s and 2s in the given array. then store
// all the 0s in the begining followed by all the 1s and then all the 2s.


// 1. Three counter c0, c1, c2
// 2. Traversing the array, increase the counter and once traversing gets finised
// then replace all the values for counter values

#include<iostream>
using namespace std;

void sortArr(int arr[], int n){

    int i, count_0 = 0, count_1 = 0, count_2 = 0;

    // count the number of 0s, 1s and 2s

    for(i = 0; i < n; i++){
        switch(arr[i]){
            case 0:
                count_0++;
                break;
            case 1:
                count_1++;
                break;
            case 2:
                count_2++;
                break;
        }
    }

    //Lets update array
    i = 0;

    //Store alll the 0s in the begining
    while(count_0 > 0){
        arr[i++] = 0;
        count_0--;
    }

    //Store alll the 1s in the begining
    while(count_1 > 0){
        arr[i++] = 1;
        count_1--;
    }

    //Store alll the 0s in the begining
    while(count_2 > 0){
        arr[i++] = 2;
        count_2--;
    }

    // Print the array
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 

}


int main(){
    
    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 }; 
    int n = sizeof(arr) / sizeof(int); 
  
    sortArr(arr, n);

    return 0;
}