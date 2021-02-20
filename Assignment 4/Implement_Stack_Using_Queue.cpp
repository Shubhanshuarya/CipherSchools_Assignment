#include<iostream>
#include<queue>
using namespace std;

class Stack{

    queue<int> q1, q2;

    int currentSize;
    public:
        Stack(){
            currentSize = 0;
        }
        void push(int x){
            currentSize++;
            q2.push(x);

            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }

            queue<int> q = q1;
            q1 = q2;
            q2 = q;
        }

        void pop(){
            if(q1.empty()){
                return;
            }
            q1.pop();
            currentSize--;
        }

        int size(){
            return currentSize;
        }

        int top(){
            if(q1.empty()){
                return -1;
            }
            return q1.front();
        }
};

int main(){

    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.size() << "\n";

    cout << s.top() << "\n";
    s.pop();

    cout << s.top() << "\n";
    s.pop();


    return 0;
}