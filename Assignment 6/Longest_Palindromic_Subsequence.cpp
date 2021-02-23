#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int longestPalindrome(string X, int i, int j)
{
    if (i > j) {
        return 0;
    }
    if (i == j) {
        return 1;
    }
    if (X[i] == X[j])
    {
        return longestPalindrome(X, i + 1, j - 1) + 2;
    }
 
    return max(longestPalindrome(X, i, j - 1), longestPalindrome(X, i + 1, j));
}
 
int main()
{
    string X = "ABBDCACB";
    int n = X.length();
    cout << longestPalindrome(X, 0, n - 1);
    return 0;
}