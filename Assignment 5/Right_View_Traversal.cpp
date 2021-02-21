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

void rightViewTraversal(Node* root, int currentLevel){
    int alreadyTraversedLevel = 0;
    if(root == NULL) {
            return;
        }

    if(currentLevel > alreadyTraversedLevel) {
        cout << root->data << " ";
        alreadyTraversedLevel = currentLevel;
    }

        rightViewTraversal(root->right, currentLevel + 1);
        rightViewTraversal(root->left, currentLevel + 1);

}

int main(){

    Node *root = new Node(10); 
    root->left = new Node(20); 
    root->right = new Node(30); 
    root->left->left = new Node(40); 
    root->left->right = new Node(50); 

    rightViewTraversal(root, 1); 

    return 0;
}