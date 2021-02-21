#include<iostream>
#include<vector>
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

void preorderTraversal(Node* root){

    if (root == NULL) 
        return; 
    cout << root->data << " "; 
    preorderTraversal(root->left); 
    preorderTraversal(root->right); 

}

Node* construct(int start, int end, vector<int> const &preorder, int &pIndex, unordered_map<int,int> &map)
{
    if (start > end) {
        return nullptr;
    }
 
    Node *root = newNode(preorder[pIndex++]);
 
    int index = map[root->key];
 
    root->left = construct(start, index - 1, preorder, pIndex, map);
 
    root->right = construct(index + 1, end, preorder, pIndex, map);
 
    return root;
}
 
Node* construct(vector<int> const &inorder, vector<int> const &preorder)
{
    int n = inorder.size();
    unordered_map<int,int> map;
    for (int i = 0; i < n; i++) {
        map[inorder[i]] = i;
    }
 
    int pIndex = 0;
 
    return construct(0, n - 1, preorder, pIndex, map);
}

int main(){

    vector<int> inorder = { 4, 2, 1, 7, 5, 8, 3, 6 };
    vector<int> preorder = { 1, 2, 4, 3, 5, 7, 8, 6 };

    Node* root = construct(inorder, postorder);

    //Traverse Tree Inorder
    inorderTraversal(root);

    cout << "\n";

    postorderTraversal(root);

    return 0;
}