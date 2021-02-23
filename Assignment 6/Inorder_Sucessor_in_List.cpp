#include<iostream>
using namespace std;
 
class Node {
    public:
        int data;
        Node* left;
        Node* right;
        Node* parent;
};
 
Node* minValue(Node* node){
    Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}
 
Node* inOrderSuccessor(Node* root, Node* n)
{
    if (n->right != NULL){
        return minValue(n->right);
    }

    Node* p = n->parent;
    while (p != NULL && n == p->right) {
        n = p;
        p = p->parent;
    }
    return p;
}

Node* newNode(int data)
{
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
 
    return (node);
}

Node* insert(Node* node, int data)
{
    if (node == NULL){
        return (newNode(data));
    }else {
        Node* temp;
        if (data <= node->data) {
            temp = insert(node->left, data);
            node->left = temp;
            temp->parent = node;
        }
        else {
            temp = insert(node->right, data);
            node->right = temp;
            temp->parent = node;
        }
        return node;
    }
}

int main()
{
    Node *root = NULL, *temp, *succ, *min;
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);
    temp = root->left->right->right;
 
    succ = inOrderSuccessor(root, temp);
    if (succ != NULL){
        cout << temp->data << " and " << succ->data;
    }else{
        cout << "Not Exist";
    }
    return 0;
}