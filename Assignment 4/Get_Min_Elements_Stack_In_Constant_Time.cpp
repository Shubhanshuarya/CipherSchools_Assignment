#include<iostream>
#include<stack>
using namespace std;

class NewStack{
    stack<int> s;
    int minElement;
    public:
        void getMinimum(){
            if(s.empty()){
                cout << "Stack is empty\n";
            }else{
                cout << "Minimum element " << minElement << "\n";
            }
        }

        void peek(){
            if(s.empty()){
                cout << "Stack is empty\n";
                return;
            }

            int t = s.top();
            if(t < minElement){
                cout << "Top element: " << minElement << "\n";
            }else{
                cout << "Top element: " << t << "\n";
            }
        }

        void pop(){

            if(s.empty()){
                cout << "Stack is empty\n";
                return;
            }

            cout << "Top Element Nikalo";
            int t = s.top();
            s.pop();

            if(t < minElement){
                cout << minElement << "\n";
                minElement = 2 * minElement - t;
            }else{
                cout << t << "\n";
            }
        }

        void push(int x){
            if(s.empty()){
                minElement = x;
                s.push(x);
                cout << "Number Daal Diya " << x << "\n";
                return;  
            }

            if(x < minElement){
                s.push(2*x - minElement);
                minElement = x;
            }else{
                s.push(x);
            }

            cout << "Number Daal Diya " << x << "\n";
        }
};

int main(){

    NewStack s; 
    s.push(50); 
    s.push(30);
    s.push(35); 
    s.push(40);  
    s.getMinimum(); 
    s.push(20); 
    s.push(10); 
    s.getMinimum(); 
    s.pop(); 
    s.getMinimum(); 
    s.pop(); 
    s.peek(); 
    return 0;
}