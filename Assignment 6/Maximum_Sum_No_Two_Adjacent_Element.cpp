#include<iostream>
#include<vector>
using namespace std; 

int FindMaxSum(vector<int> vec, int n) 
{ 
  int incl = vec[0]; 
  int excl = 0; 
  int excl_new; 
  int i; 
  
  for (i = 1; i < n; i++) 
  { 
     excl_new = (incl > excl) ? incl : excl; 
     incl = excl + vec[i]; 
     excl = excl_new; 
  } 
   return ((incl > excl)? incl : excl); 
} 
  
int main() 
{ 
  vector<int> vec = {5, 5, 10, 100, 10, 5}; 
  vec.size();
  cout << FindMaxSum(vec, n); 
  return 0; 
} 