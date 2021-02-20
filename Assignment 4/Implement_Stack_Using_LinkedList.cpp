#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

Node* top;

void push(int data){

    Node* temp = new Node();

    if(!temp){
        cout << "\n Overflow";
        exit(1);
    }

    temp->data = data;
    temp->next = top;
    top = temp;
}

int isEmpty(){
    return top == NULL;
}

void display(){

    Node* temp;
    if(top == NULL){
        cout << "\n Stack Underflow";
        exit(1);
    }else{
        temp = top;
        while(temp != NULL){

            cout << temp->data << "-->";

            temp = temp ->next;
        }
    }

}

int peek(){
    if(!isEmpty()){
        return top->data;
    }else{
        exit(1);
    }
}

void pop(){

    Node* temp;
    if(top == NULL){
        cout << "\n Stack Underflow" << endl;
        exit(1);
    }else{
        temp = top;
        top = top->next;
        temp->next = NULL;
    }
}

int main(){

    push(10);
    push(20);
    push(30);
    push(40);

    display();

    cout << "\nTop Element " << peek();

    cout << "\n";

    pop();
    pop();

    display();
    return 0;
}