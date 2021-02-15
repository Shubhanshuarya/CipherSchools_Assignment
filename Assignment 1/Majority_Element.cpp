// What is Majority Element

// A Majority Element in an array A[] of size n is an element that appears more than n/2 times
// and hence there is at most one such element.

#include<iostream>
using namespace std;

void MajorityElement(int arr[], int n){
    // 1. Create two variable for max_count = 0, count = 0, index = -1(holding the index value of the result)
    // 2. Traverse the whole array
    // 3. With the help of nested loop, we will count all the similar elements present inside the array
    // 4. if the count is greater than the max_count then update the value of max_count with count
    // and store the index in another variable
    // if the maximum count is greater than the half of the size of the array, print the element.
    // else print "No majoritty element is present"

    int max_count = 0, index = -1;
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if (arr[i] == arr[j]){
                count++;
            }
        }

        // Update max_count value if count of current element is greater
        if(count > max_count){
            max_count = count;
            index = i;
        }
    }

    // Check whether the max_count is greater thann n/2
    // return the corresponding element
    if(max_count > n/2){
        cout << arr[index];
    }else{
        cout << "No Majority Element";
    }

}

int main(){
    int arr[] = {1, 1, 2, 1, 3, 5, 1};
    int n = sizeof(arr) / sizeof(int);
    // cout << n ; ==> 7

    // fuction Calling
    MajorityElement(arr, n);

    return 0;
}


// Time Complexity :: O(n * n)