#include<iostream>
using namespace std; 

int fib(int n) 
{ 
    if (n <= 1) 
    {   
        return n;
    } 
    return fib(n - 1) + fib(n - 2); 
} 
  
int countWays(int s) 
{ 
    return fib(s + 1); 
} 

int main() 
{ 
    int s = 6; 
    cout << countWays(s); 
    return 0; 
}