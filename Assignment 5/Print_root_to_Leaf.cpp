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

void printArray(int ints[], int len)  
{  
    for (int i = 0; i < len; i++)  
    {  
        cout << ints[i] << " ";  
    }  
    cout<<endl;  
}  

void printPathsRecurisely(Node* node, int path[], int pathLen){

    if (node == NULL)  
        return;  
      
    path[pathLen] = node->data;  
    pathLen++;  
      
    if (node->left == NULL && node->right == NULL)  
    {  
        printArray(path, pathLen);  
    }  
    else
    {  
        printPathsRecurisely(node->left, path, pathLen);  
        printPathsRecurisely(node->right, path, pathLen);  
    }  
}

void printPaths(Node* node){
    int path[100];
    printPathsRecurisely(node, path, 0);
}



int main(){

    Node *root = new Node(10); 
    root->left = new Node(20); 
    root->right = new Node(30); 
    root->left->left = new Node(40); 
    root->left->right = new Node(50); 

    printPaths(root); 

    return 0;
}