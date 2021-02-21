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

int isBST(Node* root){
    if (root == NULL)  
    return 1;  
      
    if (root->left!=NULL && max(root->left) > root->data)  
        return 0;  
        
    if (root->right!=NULL && min(root->right) < root->data)  
        return 0;  
        
    if (!isBST(root->left) || !isBST(root->right))  
        return 0;  
        
    return 1;  
}

int main(){

    Node *root = new Node(10); 
    root->left = new Node(20); 
    root->right = new Node(30); 
    root->left->left = new Node(40); 
    root->left->right = new Node(50); 

    isBST(root); 

    return 0;
}