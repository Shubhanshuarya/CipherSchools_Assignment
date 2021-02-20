#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void printNextGreaterElement(vector<int> arr, int n){
    stack<int> s;

    s.push(arr[0]);

    for(int i = 1; i < n; i++){

        if(s.empty()){
            s.push(arr[i]);
            continue;
        }

        while(s.empty() == false && s.top() < arr[i]){
            cout << s.top() << "-->" << arr[i] << endl;
            s.pop();
        }

        s.push(arr[i]);
    }

    while(s.empty() == false){
        cout << s.top() << "-->" << -1 << endl;
        s.pop();
    }
}

int main(){

    vector<int> arr = {11, 22, 2, 55};
    int n = arr.size();

    printNextGreaterElement(arr, n);

    return 0;
}