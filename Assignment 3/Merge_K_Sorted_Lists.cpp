#include<iostream>
using namespace std;

class ListNode{
    public:
        int data;
        int next;
};

ListNode mergeTwoSortedLists(ListNode A, ListNode B)
{
    if(A == NULL)
        return B;
    if(B == NULL)
        return A;
    ListNode output = NULL   
    if(A.val < B.val)
    {
        output = A;
        A = A.next;
    }
    else
    {
        output = B;
        B = B.next;
    }
    ListNode curr = output
    while(A != NULL && B!= NULL)
    {
        if(A.val > B.val)
        {
            curr.next = B;
            B = B.next;
        }
        else
        {
            curr.next = A;
            A = A.next;
        }
        curr = curr.next;
    }
    if(A!= NULL)
        curr.next = A;
    if(B!= NULL)
        curr.next = B;
    return output;
}

ListNode mergeKLists(ListNode[] lists, int k) {
    if(k==1){
        return lists[0];
    }
    if(k==0){
        return null;
    }
    ListNode head = mergeTwoSortedLists(lists[0],lists[1]);
    for (int i = 2 to k) {
        head = mergeTwoSortedLists(head,lists[i]);
    }
    return head;
}

int main(){

    int k = 3;
    int n = 4;
    Node* arr[k];
 
    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);
 
    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);
 
    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);
 
    // Merge all lists
    Node* head = mergeKLists(arr, k - 1);

    return 0;
}