#include<iostream>
#include<stack>
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

Node* reverseKgroup(Node* head, int k){

    stack<Node*> s;
    Node* current = head;
    Node* prev = NULL;

    while(current != NULL){

        int count = 0;
        // Taking loop for k groups

        while(current != NULL && count < k){
            s.push(current);
            current = current->next;
            count++;
        }

        while(s.size() > 0){
            if(prev == NULL){
                prev = s.top();
                head = prev;
                s.pop();
            }else{
                prev->next = s.top();
                prev = prev->next;
                s.pop();
            }
        }
    }

    prev->next = NULL;

    return head;

}

int main(){

    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    Node* fourth = NULL;
    Node* fifth = NULL;
    Node* sixth = NULL;
    Node* seventh = NULL;

    // Alloctaes the nodes
    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();
    fifth = new Node();
    sixth = new Node();
    seventh = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = sixth;

    sixth->data = 6;
    sixth->next = seventh;

    seventh->data = 7;
    seventh->next = NULL;

    // Printing
    printList(head);


    // reveerse in K groups
    head = reverseKgroup(head, 3);

    cout << "\nreverse of LL \n";
    // Print
    printList(head);

    return 0;
}