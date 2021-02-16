#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void deleteNode(Node* head){
    Node* temp = head;

    while(temp->next->next != NULL){
        temp = temp->next;
    }

    temp->next = NULL;
}

void printList(Node* head){
    
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }

}

int main(){

    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // Alloctaes the nodes
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    // Printing the Nodes
    printList(head);

    // Delete the end node
    deleteNode(head);

    cout << "\n";

    // printing
    printList(head);
    return 0;
}