#include<bits/stdc++.h>
using namespace std;
#define Node ListNode 

struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data=data;
        this->next = NULL;
    }



};
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
bool isPre (Node*A , Node*B) {
    for (Node*p =A ; p ; p=p->next) {
        if (p->next==B) return true;
    }
    return false;
}
void swapnode(Node*&A , Node*&B) {
    Node* temp = B;
    B=A;
    A= temp;
}
void swaplist(Node*&head , Node* A , Node *B) {
    if (A==B) return;
    Node* preA , *preB , *nxtA , *nxtB;

    if (isPre(B,A)) {
        swapnode(A,B);
    }
    preA=preB=NULL;
    if (A!= head) {
        preA=head;
        while (preA->next!=A) preA=preA->next;
    }
    if (B!=head) {
        preB=head;
        while(preB->next!=B) preB=preB->next;
    }
    nxtA=A->next;
    nxtB=B->next;   
    if (A==head) {
        if (nxtA == B) {
            B->next = A;
            A->next = nxtB;
            head= B;
        }
        else {
            head = B; 
            B->next = nxtA;
            preB->next =A;
            A->next = nxtB;

        }
    }
    else {
        if (nxtA == B) {
            preA->next = B;
            B->next = A;
            A->next = nxtB;
        }
        else {
            preA->next = B;
            B->next = nxtA;
            preB->next =A;
            A->next = nxtB;
      }
    }
 

}
int size(ListNode*head) {
    int len=0;
    for (ListNode*p=head ; p ; p=p->next) {
        len++;
    }
    return len;
}
Node* getat(Node*head , int index) {
    Node *p = head;
    for (int i = 1; i<index;i++) {
        p = p->next;
    }
    return p;
}

int main() {
    Node* head = NULL;
    string inputLine; 
    getline(cin, inputLine);
    stringstream ss(inputLine);
    int x;
    while (ss >> x) {
        if (x >= 0 && x <=9) {
            pushBack(head,x);
        }
    }
    swaplist(head ,getat(head,3), getat(head,1));       
    
    
    print(head);


    return 0;
}