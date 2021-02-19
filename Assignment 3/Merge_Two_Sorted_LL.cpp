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

void printList(Node* temp){
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* MergeSorted(Node* head1, Node* head2){
    Node* result = NULL;
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    if (head1->data < head2->data) {
        result = head1;
        result->next = MergeSorted(head1->next, head2);
    } else {
        result = head2;
        result->next = MergeSorted(head1, head2->next);
    }
    return result;
}

int main(){

    Node* a = new Node();
    Node* b = new Node();

    a->data = 5;
    a->next = NULL;

    b->data = 2;
    b->next = NULL;

    push(a, 10);
    push(a, 15);
    push(a, 20);
    
    // printList(a);

    push(b, 3);
    push(b, 7);
    push(b, 11);
    push(b, 13);

    // printList(b);

    cout << "Merge LL \n";

    Node* res = MergeSorted(a, b);

    printList(res);
    return 0;
}