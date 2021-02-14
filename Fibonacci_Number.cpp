#include<iostream>
using namespace std;

int fibonacciNumber(int num){

    if(num <= 1){
        return num;
    }
    return fibonacciNumber(num - 1) + fibonacciNumber(num - 2);

}

int main(){

    int n = 9;
    cout << fibonacciNumber(n);

    return 0;
}