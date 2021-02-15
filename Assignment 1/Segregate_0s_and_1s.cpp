// Use two indexes to traverse

// 1. Maintain two indexed. Initialize first index left as 0 and second index right as n-1
// 2. Run while loop left < right
// 3. Keep Incrementing the index left while there are 0s at it
// 4. Keep decrementing index right while there are 1s at it
// 5. If left < right then exchange arr[left] and arr[right]


#include<iostream>
using namespace std;

// Function to put all 0s on left and all 1s at right
void segregateNumbers(int arr[], int size){
    // Initialize left and right indexes
    int left = 0, right = size-1;

    while(left < right){

        // Increment left index while we see 0s at left
        while(arr[left] == 0 && left < right){
            left++;
        }

        // Decrement right index while we see 1s at right
        while(arr[right] == 1 && left < right){
            right--;
        }

        // if left is smaller than right then there is a 1 at left and 0 at right. 
        // Exchange arr[left] with arr[right]
        if(left < right){
            arr[left] = 0;
            arr[right] = 1;
            left++;
            right--;
        }
    }
    
}

int main(){

    int arr[] = {0, 1, 0, 1, 1, 1};  
    int i, arr_size = sizeof(arr)/sizeof(arr[0]);  
    
    segregateNumbers(arr, arr_size);

    for (i = 0; i < 6; i++)  
        cout << arr[i] << " ";

    return 0;
}