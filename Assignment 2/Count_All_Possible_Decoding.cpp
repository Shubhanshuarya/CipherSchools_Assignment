// Using String we are trying to solve this problem
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void countAllDecoding(string num, string result){

    if(num.length() == 0){
        int count = 0;
        count += 1;
        cout << count << " ";
        return;
    }

    string first_char = num.substr(0, 1);

    int first_num = stoi(first_char);

    if(first_num != 0){
        char character = (char)('a' + first_num - 1);
        countAllDecoding(num.substr(1), result + character);
    }

    if(num.length() <= 1){
        return;
    }

    string two_char = num.substr(0,2);
    int two_num = stoi(two_char);

    if(two_num <= 26){
        char character = (char)('a' + two_num - 1);
        countAllDecoding(num.substr(2), result + character);
    }

}

int main(){

    countAllDecoding("121", "");

    return 0;
}