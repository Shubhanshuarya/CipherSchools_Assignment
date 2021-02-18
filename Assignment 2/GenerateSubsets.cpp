#include<iostream>
#include<vector>
using namespace std;

void returnAllSubsets(vector<int> vec, int start, vector<int> empty_vec){

    for(int i = start; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << "\n";

    for(int i = start; i < vec.size(); i++){
        empty_vec.push_back(vec[i]);
        returnAllSubsets(vec, i+1, empty_vec);
        vec.pop_back();
    }
}

int main(){

    vector<int> vec = {1,2,3};
    vector<int> empty_vec;

    returnAllSubsets(vec, 0, empty_vec);
    return 0;
}