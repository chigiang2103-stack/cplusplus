#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;


};
Node* createNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void pushBack(Node*& head, int x) {
    Node* p = createNode(x);
    if (head == NULL) {
        head = p;
        return;
    }
    Node* cur = head;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = p;
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
// 1 2 3 4 2 3 
Node* longest(Node* head) {
    Node* beststart = head;
    Node* curstart=head;

    int bestlen = 1 , curlen = 1;
     Node* cur = head;

    while(cur->next!=NULL) {
        if(cur->next->data > cur->data) {
            curlen++;
        }
        else {
            if (bestlen < curlen) {
                bestlen = curlen;
                beststart=curstart;
            }
            curstart = cur->next;
            curlen=1;
        }
        cur=cur->next;
    }
    if (curlen > bestlen) {
        bestlen = curlen;
        beststart = curstart;
    }

    Node* res = NULL;
    for (int i = 0 ; i < bestlen ; i++) {
        pushBack(res , beststart->data);
        beststart=beststart->next;
    }
    return res;
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
    Node* rows[100];
    int rowCount = 0;
    Node* cur = head;

    while (cur != NULL) {
        rows[rowCount] = NULL;
        int cnt = 0;
        while (cur != NULL && cnt < 5) {
            pushBack(rows[rowCount], cur->data);
            cur = cur->next;
            cnt++;
        }
        rowCount++;
    }

    for (int i = 0; i < rowCount; i++) {
        Node* list = longest(rows[i]);
        if (list != NULL)
            print(list);
    }


    return 0;
}