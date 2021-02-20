#include<iostream>
#include<vector>
using namespace std;

void previousSmaller(vector<int> v, int n)
{
    cout << "_, ";
    for(int i = 1; i < n; i++){
        int j;
        for(int j = i - 1; j >= 0; j--){
            if(v[j] < v[i]){
                cout << v[j] << ", ";
                break;
            }
        }

        if(j == -1){
            cout << "_, ";
        }
    }
}

int main(){

    vector<int> v = {1, 2, 0, 8, 9};
    int n = v.size();

    previousSmaller(v, n);

    return 0;
}