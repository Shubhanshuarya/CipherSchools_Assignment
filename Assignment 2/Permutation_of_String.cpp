#include<iostream>
using namespace std;

void permutate(string str, int start, int end){

    if(start == end){
        cout << str << " ";
    }

    for(int i = start; i <= end; i++){
        swap(str[start], str[i]);

        permutate(str, start+1, end);
    }

}

int main(){

    string str = "ABC";

    int n = str.length();

    permutate(str, 0, n-1);

    return 0;
}