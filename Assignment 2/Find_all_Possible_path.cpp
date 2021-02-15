#include<iostream>
#include<vector>
using namespace std;

int possiblePath(int m, int n){

    
    if(m == 0 || n == 0)
        return 1;

    return possiblePath(m - 1, n) + possiblePath(m, n-1);
}

int main(){

    int m = 3, n = 3;

    cout << possiblePath(m-1, n-1); 

    return 0;
}