#include<iostream>
using namespace std;

int findPlatform(int arr[], int dep[], int size){

    int required_platform = 1, result = 1;
    int i = 1, j = 0;

    for(int i = 0; i < size; i++){
        // Minimum Platform
        required_platform = 1;

        for(int j = i+1; j < size; j++){
            if((arr[i] >= arr[j] && arr[i] <= dep[j]) || (arr[j] >= arr[i] && arr[j] <= dep[i])){
                required_platform++;
            }
        }

        result = max(result, required_platform);
    }

    return result;
}

int main(){

    int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << findPlatform(arr, dep, n);

    return 0;
}