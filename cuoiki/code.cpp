#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data=data;
        this->next = NULL;
    }
};
void pushFront(Node* &head, int x) {
    Node *newNode = new Node(x);
    newNode->next = head;
    head = newNode;
}

void pushBack(Node* &head, int x) {
    Node *newNode = new Node(x);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node *p = head;
    while (p->next != nullptr) p = p->next;
    p->next = newNode;
}

void popFront(Node* &head) {
    if (head == nullptr) return;
    Node* tmp = head;
    head = head->next;
    delete tmp;
}

void popBack(Node* &head) {
    if (!head) return;
    if (!head->next) { delete head; head = nullptr; return; }

    Node *p = head, *pre = nullptr;
    while (p->next) {
    pre = p;
    p = p->next;
    }
    pre->next = nullptr;
    delete p;
}

int Size(Node* head) {
    int sz = 0;
    for (Node* p = head; p; p = p->next)
    sz++;
    return sz;
}

void InsertAtK(Node* &head, int x, int k) {
    if (k == 0) {
    pushFront(head, x);
    return;
    }
    if (k >= Size(head)) {
    pushBack(head, x);
    return;
    }

    Node *newNode = new Node(x);
    Node *p = head;
    for (int i = 1; i < k; i++) p = p->next;

    newNode->next = p->next;
    p->next = newNode;
}

void deleteAtK(Node* &head, int k) {
    if (k < 0 || k >= Size(head)) return;

    if (k == 0) { popFront(head); return; }

    Node *p = head, *pre = nullptr;
    for (int i = 0; i < k; i++) {
        pre = p;
        p = p->next;
    }

    pre->next = p->next;
    delete p;
    p = nullptr;
}

void Reverse(Node* &head) {
    Node *prev = nullptr, *cur = head;
    while (cur) {
    Node *nxt = cur->next;
    cur->next = prev;
    prev = cur;
    cur = nxt;
        }
    head = prev;
}

void print(Node*head) {
    Node*p=head;
    while(p) {
        cout << p->data ;
        if (p->next!=NULL) {
            cout <<"->" ;
        }
        p=p->next;
    }
    cout << endl;
}

void clearList(Node* &head) {
    while (head != nullptr) popFront(head);
}


void swapnode(Node*&A , Node*&B) {
    Node* temp = B;
    B=A;
    A= temp;
}
