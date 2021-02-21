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

// Let's Calculate first Height
int height(Node* root){

    if(root == NULL){
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if(leftHeight > rightHeight){
        return (leftHeight + 1);
    }else{
        return (rightHeight + 1);
    }
}

// Level by Level printing 
void printGivenLevel(Node* root, int level){
    if(root == NULL){
        return;
    }
    if(level == 1){
        cout << root->data << " ";
    }
    else if(level > 1){
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

// Calling w.r.t levels
void levelOrderTraversal(Node* root){
    int heightTopBottom = height(root);
    for(int i = 1; i <= heightTopBottom; i++){
        printGivenLevel(root, i);
    }
}

int main(){

    Node *root = new Node(10); 
    root->left = new Node(20); 
    root->right = new Node(30); 
    root->left->left = new Node(40); 
    root->left->right = new Node(50); 

    levelOrderTraversal(root); 

    return 0;
}