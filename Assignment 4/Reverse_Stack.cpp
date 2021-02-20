#include<iostream>
#include<stack>
using namespace std;

class StackReverse{
    stack<char> st;
    string ns;
    public:
        char insert_at_bottom(char x){
            if(st.size() == 0){
                st.push(x);
            }else{
                char a = st.top();
                st.pop();
                insert_at_bottom(x);
                st.push(a);
            }
        }

        char reverse(){
            if(st.size() > 0){
                char x = st.top();
                st.pop();
                reverse();
                insert_at_bottom(x);
            }
        }
};

int main(){

    StackReverse st;
    st.push('1'); 
    st.push('2'); 
    st.push('3'); 
    st.push('4');

    cout << "Original " << "1" << " " << "2" << " " << "3" << " " << "4" <<endl; 

    st.reverse();
    cout << "Reversed Stack";

    string ns;
    while(!st.empty()) 
    { 
        char p=st.top(); 
        st.pop(); 
        ns+=p; 
    } 
    cout << ns[3] << " " << ns[2] << " " << ns[1] << " " << ns[0] << endl; 

    return 0;
}