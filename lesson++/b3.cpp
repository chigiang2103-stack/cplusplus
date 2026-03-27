#include<iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
struct List {
    Node*head;
    List () {
        head=NULL;
    }
};
void pushBack(List &l , int x) {
    Node *newnode = new Node(x);
    if (l.head==NULL) {
          l.head=newnode; 
          return;
    }
    Node * p = l.head;
    while (p->next) {
        p = p->next;
    }
    p->next=newnode;
}

void print(List l) {
    Node*p=l.head;
    while(p) {
        cout << p->data ;
        if (p->next!=NULL) {
            cout <<"->" ;
        }
        p=p->next;
    }
    cout << endl;
}
// void movedd2LeftEven2Right (List &l) {
//     List newlist ;
//     Node*p = l.head;
//     while (p) {
//         if (p->data%2==1) {
//             pushBack(newlist,p->data);
//         }
//         p=p->next;
//     }
//     Node* q = l.head;
//     while (q) {
//         if (q->data%2==0) {
//             pushBack(newlist,q->data);
//         }
//         q=q->next;
//     }
//     print(newlist);
// }
void reduceList(List &l, int k) {
    int cur = l.head->data;
    int count = 2;
    Node*p=l.head->next;
    while (p) {
        cur-=p->data;
        if (count==k) {
            cur=abs(cur);
            count=1;
        } 
        Node*pre=p;
        p=p->next;
        delete pre;
        count++;
    }

    l.head = new Node(abs(cur));



}
int main() {
    List l;
    pushBack(l,1);
    pushBack(l,2);
    pushBack(l,3);
    pushBack(l,4);
    pushBack(l,5);
    reduceList(l, 3);
    print(l);
    // movedd2LeftEven2Right(l);
    return 0;
}
