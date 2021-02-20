#include<iostream>
using namespace std;

class stack{
    int top;

    public:
        int a[1000];
        stack(){
            top = -1;
        }
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
};

bool stack:: push(int x){
    if(top >= (1000) - 1){
        cout << "\nStack Overflow";
        return false;
    }else{
        a[++top] = x;
        cout << "Pushed\n";
        return true;
    }
}

int stack::pop(){
    if(top < 0){
        cout << "Stack Underflow";
        return 0;
    }else{
        int x = a[top - 1];
        cout << "Popped";
        return x;
    }
}

int stack::peek(){
    if(top < 0){
        cout << "Stack is empty";
        return 0;
    }else{
        int x = a[top];
        return x;
    }
}

bool stack::isEmpty(){
    return (top < 0);
}

int main(){

    class stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.pop();

    return 0;
}