#include<iostream>
using namespace std;

int getMissingNumber(int arr[], int n){

    // Sum of Number using formula
    int total = (n + 1) * (n + 2) / 2;
    for(int i = 0; i < n; i++){
        total = total - arr[i];
    }
    return total;
}

int main(){

    int arr[] = {1, 2, 4, 5 , 6};
    int n = sizeof(arr)/sizeof(int);
    int miss = getMissingNumber(arr, n);
    cout << "Missing Value : " << miss;
    return 0;
}