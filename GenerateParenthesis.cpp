#include<iostream>
using namespace std;

void generate(int left, int right, string str){

    if(left > right){
        return;
    }

    if(left == 0 && right == 0){
        cout << str << endl;
    }

    if(left > 0){
        generate(left-1, right, str + "(");
    }

    if(right > 0){
        generate(left, right-1, str + ")");
    }
}

int main(){

    generate(2, 2, "");
    return 0;
}