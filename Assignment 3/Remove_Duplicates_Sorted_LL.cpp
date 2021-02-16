#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void removeDuplicates(Node* temp){
    Node* current = temp;

    while(current->next != NULL){
        if(current->data == current->next->data){
            current->next = current->next->next;
        }else{
            current = current->next;
        }
    }
}

void printList(Node* temp){
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main(){

    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    Node* fourth = NULL;
    Node* fifth = NULL;
    Node* sixth = NULL;


    // Alloctaes the nodes
    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();
    fifth = new Node();
    sixth = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 2;
    third->next = fourth;

    fourth->data = 3;
    fourth->next = fifth;

    fifth->data = 3;
    fifth->next = sixth;

    sixth->data = 6;
    sixth->next = NULL;

    //printing 
    printList(head);

    removeDuplicates(head);

    cout << "\n";

    //printing 
    printList(head);


    return 0;
}