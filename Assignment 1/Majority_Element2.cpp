// Using Moore's Voting Algorithm

// 1. Create an Array
// 2. Calculate it's size
// 3. Function as a printMajority(a[], size) => Calling two new functions findCandidate(a[], size)
// and isMajority(a[], size, number)
// 4. Create function findCandidate(int arr[], int size)
// 5. initialize the varibles max_index = 0, count = 1
// 6. run a loop from the next element and check whether it is same then increment the count otherwise
// decrement the count
// 7. if count becomes zero, then reinitialize the variables maj_index = i; count = 1
// 8. Create a function :: isMajority(arr, size, number)
// initialize the variable count to 0
// run a for loop, and count the number how many times it is present
// 9. if count > (size/2) then return true otherwise false

#include<iostream>
using namespace std;

// Finding suitable Majority element from the array
int findCandidate(int arr[], int size){
    int max_index = 0, count = 1;
    for(int i = 1; i < size; i++){
        if(arr[max_index] == arr[i]){
            count++;
        }else{
            count--;
        }
        if(count == 0){
            max_index = i;
            count = 1;
        }
    }
    return arr[max_index];
}


// Validate the majority element
bool isMajority(int arr[], int size, int number){
    int count = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] == number){
            count++;
        }
    }
    if(count > size/2){
        return true;
    }else{
        return false;
    }
}

void printMajority(int arr[], int size){

    // Calling another function for getting majority element candidate
    int candidate = findCandidate(arr, size);

    if(isMajority(arr, size, candidate)){
        cout << candidate;
    }else{
        cout << "No Majority Element";
    }

}

int main(){
    int arr[] = {1, 3, 3, 1, 2};
    int n = sizeof(arr)/sizeof(int);

    // Calling a function
    printMajority(arr, n);

    return 0;
}

// Time Complexity :: O(n)