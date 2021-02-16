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

void insertNode(Node* head, int data){

    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;

}


void deleteNode(Node* head){

    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next = NULL;
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

    //Insert a Node at the end
    insertNode(head, 4);
    
    // Again Traversing
    printList(head);

    // delete from end
    deleteNode(head);

    cout << "\n";

    // Again Traversing
    printList(head);


    return 0;
}