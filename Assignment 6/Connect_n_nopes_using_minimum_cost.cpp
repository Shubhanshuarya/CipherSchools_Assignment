#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 
int minimumCost(vector<int> vec, int n)
{
    priority_queue<int, vector<int>, greater<int>> pq(vec, vec.size());
    int res = 0;
 
    while (pq.size() > 1) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        res += first + second;
        pq.push(first + second);
    }
    return res;
}
 
int main()
{
    vector<int> vec = {4, 3, 2, 6};
    int size = vec.size();
    cout << minimumCost(vec, size);
    return 0;
}