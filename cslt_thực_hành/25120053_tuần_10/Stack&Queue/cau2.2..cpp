#include<iostream>
using namespace std;


struct Node{
    int data;
    Node *next;
    Node(int x) {
        this->data=x;
        this->next=NULL;
    }
};

struct Stack{
    Node *head;
    int capacity;

};

void init(Stack& s) 
{
    s.head = NULL ;
    s.capacity = 0;
}

void push (Stack &s , int x) {
    Node* newnode = new Node(x);
    if (s.head == NULL) {
        s.head = newnode;
    }
    else {
        newnode->next=s.head;
        s.head = newnode;
    }
    s.capacity++;
}
int pop(Stack& s) { 
    if (s.head==NULL) return -1;
    Node * temp = s.head;
    int val = temp->data;
    s.head = s.head ->next ;
    delete temp;
    s.capacity--;
    return val;

}
bool isEmpty (Stack& s) {
    return s.head == NULL;
}

void empty(Stack& s) {
    s.head = NULL;
}

int size(Stack& s) {
    return s.capacity;
}


void print(Stack &s) {
    Node*temp=s.head;
    while(temp!=NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

}
int main () {
    Stack s;
    init(s);
    push(s,1);
    push(s,2);
    push(s,3);

    pop(s);
    size(s);
    print(s);


    return 0;
}