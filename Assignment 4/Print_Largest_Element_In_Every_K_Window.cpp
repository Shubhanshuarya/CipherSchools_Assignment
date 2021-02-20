#include<iostream>
#include<vector>
using namespace std;


void printKMax(vector<int> v, int n, int k){
    int max;

    for(int i = 0; i <= n - k; i++){
        max = v[i];

        for(int j = 1; j < k; j++){
            if(v[i+j] > max){
                max = v[i+j];
            }
        }
        cout << max << " ";
    }
}

int main(){

    vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
    int n = v.size();
    int k = 3;
    printKMax(v, n, k);

    return 0;
}