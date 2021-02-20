#include<iostream>
using namespace std;

class DQueueNode{
    public:
        int data;
        DQueueNode *next;
        DQueueNode *prev;
};

class deque{
    DQueueNode *head;
    DQueueNode *tail;

    public:
        deque(){
            head = tail = NULL;
        }

        bool isEmpty(){
            if(head == NULL){
                return true;
            }
            return false;
        }

        int size(){
            if(!isEmpty()) {
                DQueueNode *temp = head;
                int len = 0;
                while(temp != NULL){
                    len++;
                    temp = temp->next;
                }
                return len;
            }
            return 0;
        }

        void insert_first(int element){

            DQueueNode *temp = new DQueueNode[sizeof(DQueueNode)];
            temp->data = element;

            if(head == NULL){
                head = tail = temp;
                temp->next = temp->prev = NULL;
            }else{
                head->prev = temp;
                temp->next = head;
                temp->prev = NULL;
                head = temp;
            }
        }

        void insert_last(int element)
        {
            DQueNode* temp = new DQueNode[sizeof(DQueNode)];
            temp->value = element;
            if (head == NULL) {
                head = tail = temp;
                temp->next = temp->prev = NULL;
            }
            else {
                tail->next = temp;
                temp->next = NULL;
                temp->prev = tail;
                tail = temp;
            }
        }
 
        void remove_first()
        {
            if (!isEmpty()) {
                DQueNode* temp = head;
                head = head->next;
                head->prev = NULL;
                free(temp);
                return;
            }
            cout << "List is Empty" << endl;
        }
 
        void remove_last()
        {
            if (!isEmpty()) {
                DQueNode* temp = tail;
                tail = tail->prev;
                tail->next = NULL;
                free(temp);
                return;
            }
            cout << "List is Empty" << endl;
        }
 
        void display()
        {
            if (!isEmpty()) {
                DQueNode* temp = head;
                while (temp != NULL) {
                    cout << temp->value << " ";
                    temp = temp->next;
                }
                cout << endl;
                return;
            }
            cout << "List is Empty" << endl;
        }
    }
};

int main(){

    Stack stk;
    stk.push(7);
    stk.push(8);
    cout << "Stack: ";
    stk.display();
    stk.pop();
    cout << "Stack: ";
    stk.display();
 
    Queue que;
 
    que.enqueue(12);
    que.enqueue(13);
    cout << "Queue: ";
    que.display();
 
    que.dequeue();
    cout << "Queue: ";
    que.display();

    return 0;
}