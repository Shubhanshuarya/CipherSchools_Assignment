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

bool isPalindrome(Node* head){

    Node* temp = head;

    stack<int> s;

    while(temp != NULL){
        s.push(temp->data);
        temp = temp->next;
    }

    while(head != NULL){
        int i = s.top();

        s.pop();

        if(head->data == i){
            return true;
        }
        head = head->next;
    }

    return false;

}

int main(){

    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    Node* fourth = NULL;

    // Alloctaes the nodes
    head = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 2;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = NULL;

    // Traversing the LL
    printList(head);

    cout << "\n";

    // Check Palindrome
    if(isPalindrome(head) == true){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}