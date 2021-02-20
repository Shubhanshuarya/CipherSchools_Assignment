#include<iostream>
#include<stack>
using namespace std;

bool findDuplicateParenthesis(string str){
    stack<char> s;

    for(char ch : str){
        if(ch == ')'){
            char top = s.top();
            s.pop();

            int e = 0;
            while(top != '('){
                e++;
                top = s.top();
                s.pop();
            }

            if(e < 1){
                return 1;
            }
        }else{
            s.push(ch);
        }
    }
    return false;
}   

int main(){

    string str = "((a+(b))+(c+d))"; 
  
    if (findDuplicateParenthesis(str)) 
        cout << "Duplicate Found "; 
    else
        cout << "No Duplicates Found ";

    return 0;
}