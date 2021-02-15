// Let's Discuss about Kadane's Algorithm

/* Initialize
    max_so_far = 0
    max_ending_here = 0

    loop for each element of the array
    1. max_eneding_here = max_ending_here + a[i]
    2. if(max_so_far < max_ending_here){
        max_so_far = max_ending_here
    }
    3. if(max_ending_here < 0){
        max_ending_here = 0
    }
4. Return max_so_far;
*/

#include<iostream>
#include<climits>
using namespace std;

int maxSubArraySum(int arr[], int size){
    
    int max_so_far = INT_MIN, max_ending_here = 0;

    for(int i = 0; i < size; i++){
        max_ending_here = max_ending_here + arr[i];
        // cout << max_ending_here << " ";
        if(max_so_far < max_ending_here){
            max_so_far = max_ending_here;
        }

        if(max_ending_here < 0){
            max_ending_here = 0;
        }
    }

    
    return max_so_far;
}

int main(){

    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);

    cout << max_sum;
    return 0;
}