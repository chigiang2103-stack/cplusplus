#include<iostream>
using namespace std;
struct Node {
    int data;
    Node*next;
    Node(int x) {
        this->data=x;
        this->next = NULL;
    }
};
struct Queue{
    Node *head;
    Node *tail;
    int capacity;
};

void init(Queue &q) {
    q.head = NULL;
    q.tail = NULL;
    q.capacity = 0;
}
void enqueue(Queue &q , int x) {
    Node* newnode = new Node(x);
    if (q.head == NULL) {
        q.head = q.tail = newnode;
    }
    else {
        q.tail->next = newnode;
        q.tail = newnode;
    }
    q.capacity++;
}
bool isEmpty(Queue &q) {
    return q.head == NULL;
}

int dequeue(Queue &q ) {
    if (isEmpty(q)) return -1;

    Node*temp=q.head ; 
    int value = temp->data ;
    q.head = q.head->next;
    if (q.head == NULL ) q.tail=NULL;

    delete temp;
    q.capacity--;
    return value;
}

int size(Queue &q) {
    return q.capacity;
}
void empty (Queue &q) {
    q.head = NULL;
    q.tail = NULL;
}

void print(Queue &q) {
    Node*temp=q.head;
    while(temp!=NULL) {
        cout <<temp->data << " ";
        temp=temp->next;
    }
}
int main () {

    Queue q;
    init(q);
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    print(q);



    return 0;

}