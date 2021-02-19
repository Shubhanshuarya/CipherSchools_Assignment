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

Node* rearrangeEvenOdd(Node* head){

    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* odd = head;
    Node* even = head->next;

    Node* evenHead = even;

    while(even != NULL && even->next != NULL){

        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;

    }

    odd->next = evenHead;

    return head;


}

int main(){
    
    Node* a = new Node();

    a->data = 8;
    a->next = NULL;

    push(a, 1);
    push(a, 2);
    push(a, 3);
    push(a, 4);
    push(a, 5);
    push(a, 6);
    
    cout << "original LL :";
    printList(a);

    a = rearrangeEvenOdd(a);

    cout << "\nRearranged LL:";
    printList(a);
    return 0;
}