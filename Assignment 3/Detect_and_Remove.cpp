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

Node* newNode(int key){
    Node* temp = new Node();
    temp->data = key;
    temp->next = NULL;
    return temp;
}

int detectAndRemoveLoop(Node* temp){
    Node *slow = temp, *fast = temp;
    bool isLoopAvailable = false;
    while(slow != NULL && fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            cout << "Loop Exists\n";
            isLoopAvailable = true;
            break;
        }
    }
    
    if(isLoopAvailable){
        slow = temp;
        Node* prevNode = NULL;
        while(slow != fast){
            prevNode = fast;
            fast = fast->next;
            slow = slow->next;
        }
        cout << "Loop Found Node: " << slow->data;
        prevNode->next = NULL;
    }
}
int main(){

    Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
    head->next->next->next->next->next = head->next->next;

    detectAndRemoveLoop(head);

    return 0;
}