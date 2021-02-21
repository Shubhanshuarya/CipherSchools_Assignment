#include<iostream>
using namespace std;

class Node 
{ 
    public:
        int data; 
        Node* left, *right; 
        Node(int data) 
        { 
            this->data = data; 
            left = right = NULL; 
        }
}; 

bool checkMirror(Node* a, Node* b) 
{ 
    if (a == NULL && b == NULL) 
        return true; 
  
    if (a == NULL || b == NULL) 
        return false; 
  
    return  a->data == b->data && checkMirror(a->left, b->right) && checkMirror(a->right, b->left); 
} 

int main(){

    Node *a = new Node(10); 
    a->left = new Node(20); 
    a->right = new Node(30); 
    a->left->left = new Node(40); 
    a->left->right = new Node(50); 

    Node *b = new Node(10); 
    b->left = new Node(30); 
    b->right = new Node(20); 
    b->right->left = new Node(50); 
    b->right->right = new Node(40); 

    if(checkMirror(a, b)){
        cout << "Yes";
    }else{
        cout << "No";
    }

    return 0;
}