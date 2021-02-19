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

Node* newNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* temp){
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}


Node* addTwoLinkedList(Node* a, Node* b){
    Node* dummy;
    Node* temp = dummy;
    int carry = 0;

    while(a != NULL || b != NULL || carry){
        int sum = 0;
        if(a != NULL){
            sum += a->data;
            //cout << sum;
            a = a->next;
        }

        if(b != NULL){
            sum += b->data;
            b = b->next;
        }

        sum += carry;
        carry = sum / 10;
        // cout << sum;
        Node* newNodeL = newNode(sum % 10);
        temp->next = newNodeL;
        temp = temp->next;
    }
    return dummy->next;
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
    
    // printList(a);

    push(b, 3);
    push(b, 4);
    push(b, 5);
    push(b, 6);

    // printList(b);

    Node* result = addTwoLinkedList(a, b);

    // cout << result;

    printList(result);

    return 0;
}