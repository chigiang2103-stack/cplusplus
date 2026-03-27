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
unsigned long long list_to_num(Node*head) {
    Node* cur = head;
    unsigned long long num = 0;
    while (cur!=NULL) {
        num = num*10 + (cur->data); 
        cur=cur->next;
    }
    return num;

}

void newlist(Node*&head) {
    Node*p=head;
    Node*pre=NULL;
    while (p) {
        if (p->data == 0 ) {
            if (pre==NULL) {
                head=p->next;
                delete p;
                p = head;
            }
            else {
                pre->next=p->next ; 
                delete p;
                p=pre->next;
            }
        }
        pre=p;
        p=p->next;
    }
}
int main() {
    Node* head = NULL;
    // string inputLine;
    // getline(cin, inputLine);
    // stringstream ss(inputLine);
    int x;
    while (cin >> x ) {
        if (x >= 0 && x <=9) {
            pushBack(head,x);
        }
        if (cin.peek() == '\n' ) {
            break; 
        }
    }


    print(head);
    cout << list_to_num(head) << endl;
    print(head);


    return 0;
}