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

void leftViewTraversal(Node* root, int level, int max_level){

    if(root == NULL){
        return;
    }

    if(max_level < level){
        cout << root->data << " ";
        max_level = level;
    }

    leftViewTraversal(root->left, level + 1, max_level);
    leftViewTraversal(root->right, level + 1, max_level);
}

void leftViewPrinting(Node* root)
{
    int max_level = 0;
    leftViewTraversal(root, 1, max_level);
}

int main(){

    Node *root = new Node(10); 
    root->left = new Node(20); 
    root->right = new Node(30); 
    root->left->left = new Node(40); 
    root->left->right = new Node(50); 

    leftViewPrinting(root); 

    return 0;
}