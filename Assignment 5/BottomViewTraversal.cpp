#include<iostream>
#include<queue>
#include<map>
using namespace std;

class Node 
{ 
    public:
        int data; 
        int horizontalDistance;
        Node* left, *right; 
        Node(int data) 
        { 
            this->data = data; 
            horizontalDistance = INT_FAST32_MAX;
            left = right = NULL; 
        }
}; 

void bottomViewTravesal(Node* root){
    if (root == NULL) 
        return; 

    int horizontalDistance = 0; 

    map<int, int> m; 
  
    queue<Node *> q; 
  
    root->horizontalDistance = horizontalDistance; 
    q.push(root);  
  
    while (!q.empty()) 
    { 
        Node *temp = q.front(); 
        q.pop();    
  
        horizontalDistance = temp->horizontalDistance; 
  
        m[horizontalDistance] = temp->data; 
  
        if (temp->left != NULL) 
        { 
            temp->left->horizontalDistance = horizontalDistance-1; 
            q.push(temp->left); 
        } 
  
        if (temp->right != NULL) 
        { 
            temp->right->horizontalDistance = horizontalDistance+1; 
            q.push(temp->right); 
        } 
    } 
  
    for (auto i = m.begin(); i != m.end(); ++i) 
    {
        cout << i->second << " ";
    } 

}

int main(){

    Node *root = new Node(10); 
    root->left = new Node(20); 
    root->right = new Node(30); 
    root->left->left = new Node(40); 
    root->left->right = new Node(50); 

    bottomViewTravesal(root); 

    return 0;
}