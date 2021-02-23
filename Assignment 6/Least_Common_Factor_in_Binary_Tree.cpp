#include <iostream>
using namespace std;
 
class Node
{
    public:
        int data;
        Node *left, *right;
};
 
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
Node* findLCA(Node* root, int n1, int n2)
{
    if (root == NULL) return NULL;
 
    if (root->data == n1 || root->data == n2)
        return root;
 
    Node *left_lca  = findLCA(root->left, n1, n2);
    Node *right_lca = findLCA(root->right, n1, n2);
 
    if (left_lca && right_lca){
        return root;
    }
    if(left_lca != NULL){
        return left_lca;
    }else{
        return right_lca;
    }
}
 
int main()
{
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->data;
    cout << "nLCA(4, 6) = " << findLCA(root, 4, 6)->data;
    cout << "nLCA(3, 4) = " << findLCA(root, 3, 4)->data;
    cout << "nLCA(2, 4) = " << findLCA(root, 2, 4)->data;
    return 0;
}