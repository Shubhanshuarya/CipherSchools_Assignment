#include<iostream>
#include<vector>
using namespace std;

string allPossibleCombination(char c){
    if (c == '1') {
        return "abc";
    }
    if (c == '2') {
        return "def";
    }
    if(c == '3') {
        return "ghi";
    }
    if (c == '4') {
        return "jkl";
    }
    if (c == '5') {
        return "mno";
    }
    if(c == '6') {
        return "pqrs";
    }
    if (c == '7') {
        return "tuv";
    }
    if (c == '8') {
        return "wxyz";
    }
    return "";
}

vector<string> returnAllCombinations(string str){

    if(str.length() == 0){
        vector<string> empty_list;
        empty_list.push_back("");
        return empty_list;
    }

    string first_character_value = allPossibleCombination(str[0]);

    vector<string> smaller_problem_combination = returnAllCombinations(str.substr(1));

    vector<string> ans;

    for(int i = 0; i < first_character_value.length(); i++){
        for(int j = 0; i < smaller_problem_combination.size(); j++){
            string result = first_character_value[i] + smaller_problem_combination[j];
            ans.push_back(result);
        }
    }

    return ans;

}


int main(){

    vector<string> ans =  returnAllCombinations("2");
    for(int i = 0; i < ans.size(); i++){
        cout << i << " ";
    }
    return 0;
}