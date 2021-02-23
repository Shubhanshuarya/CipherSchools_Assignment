#define R 3
#define C 3
#include<iostream>
using namespace std;

int printMinPath(int arr[R][C], int m, int n)
{
    if(m<0 || n<0)
        return POSOTIVE_INFINITY;
    if(n==0 && m==0)
        return arr[m][n]; // since array has only positive numbers
    else
    {
        int a = printMinPath(arr, m-1, n);
        int b = printMinPath(arr, m, n-1);
        int c = printMinPath(arr, m-1, n-1);
        return getMinimum(a, b, c) + arr[m][n];
    }
}

int main(){

    int arr[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };  

    printMinPath(arr[R][C], 0, 0);

    return 0;
}