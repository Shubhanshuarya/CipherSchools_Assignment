#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void printList(Node* temp){
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* reverse(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
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

    // Traversing the LL
    printList(head);

    cout << "\n";

    //Reverse the LL
    Node* rest = reverse(head);
    
    // Print List
    printList(rest);
    return 0;
}