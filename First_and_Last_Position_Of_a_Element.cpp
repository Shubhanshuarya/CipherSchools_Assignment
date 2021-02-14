// Given sorted arrya with may be duplicates elements.

// 1. Run a loop => for i = 0 to n-1
// 2. Take first = -1 and last = -1
// 3. When we find element first time then we update first = i
// 4. We always update last = i whenever we find the element
// 5. We print the first and last

#include<iostream>
using namespace std;

void findFirstAndLast(int arr[], int n, int x){
    int first = -1, last = -1;

    for(int i = 0; i < n; i++){
        if(x != arr[i]){
            continue;
        }
        if(first == -1){
            first = i;
        }

        last = i;
    }

    if(first != -1){
        cout << "First Occurenece = " << first << " Last Occurence = " << last;
    }else{
        cout << "No Element Found";
    }
}

int main(){

    int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
    int n = sizeof(arr) / sizeof(int);
    int x = 8;

    findFirstAndLast(arr, n, x);

    return 0;
}