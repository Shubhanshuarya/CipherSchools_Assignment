#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
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

void inorderTraversal(Node* root){

    if (root == NULL) 
        return; 
    inorderTraversal(root->left); 
    cout << root->data << " "; 
    inorderTraversal(root->right); 

}

void postorderTraversal(Node* root){

    if (root == NULL) 
        return; 
    postorderTraversal(root->left); 
    postorderTraversal(root->right); 
    cout << root->data << " "; 

}

Node* construct(int start, int end, vector<int> postorder, int pIndex, unordered_map<int,int> map)
{
    if (start > end) {
        return nullptr;
    }
 
    Node *root = newNode(postorder[pIndex--]);
 
    int index = map[root->key];
 
    root->right = construct(index + 1, end, postorder, pIndex, map);
 
    root->left = construct(start, index - 1, postorder, pIndex, map);
 
    return root;
}

Node* constructTree(vector<int> inorder, vector<int> postOrder){

    int n = inorder.size();
    unordered_map<int,int> map;
    for (int i = 0; i < inorder.size(); i++) {
        map[inorder[i]] = i;
    }
    int pIndex = n - 1;
    return construct(0, n - 1, postorder, pIndex, map);
}

int main(){

    vector<int> inorder = { 4, 2, 1, 7, 5, 8, 3, 6 };
    vector<int> postorder = { 4, 2, 7, 8, 5, 6, 3, 1 }; 

    Node* root = constructTree(inorder, postorder);

    //Traverse Tree Inorder
    inorderTraversal(root);

    cout << "\n";

    postorderTraversal(root);

    return 0;
}