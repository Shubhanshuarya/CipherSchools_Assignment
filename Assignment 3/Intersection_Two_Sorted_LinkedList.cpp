#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void push(Node* head, int data){

    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;

}

void IntersectionLL(Node* a, Node* b){
    Node* start;
    while(a != NULL && b != NULL){
        if(a->data == b->data){
            push(start, b->data);
            a = a->next;
            b = b->next;
        }
        else if(a -> data < b->data){
            a = a->next;
        }else{
            b = b ->next;
        }
    }
    while(start != NULL){
        cout << start->data << " ";
        start = start->next;
    }
}

void printList(Node* temp){
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main(){

    Node* a = new Node();
    Node* b = new Node();

    a->data = 0;
    a->next = NULL;

    b->data = 0;
    b->next = NULL;

    push(a, 1);
    push(a, 2);
    push(a, 3);
    push(a, 4);
    push(a, 5);
    push(a, 6);
 
    push(b, 3);
    push(b, 4);
    push(b, 5);
    push(b, 6);

    IntersectionLL(a, b);

    return 0;
}