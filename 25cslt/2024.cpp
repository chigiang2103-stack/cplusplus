#include <bits/stdc++.h>
using namespace std;


void printmuti(int range ,int num ) {
    for (int i = 1; i <= range ;i++) {
        cout << num << " * " << i << "=" << num*i << endl;
    }
}
int findPartitionIndex(int* nums ,int size) {
    int l =0 , r = size -1;
    int sum_l = nums[l];
    int sum_r = nums[r];
    while (l < r- 1) {
        if (sum_l <= sum_r) {
            sum_l += nums[++l];
        }
        else {
            sum_r += nums[--r];
        }
    }
    if (sum_l == sum_r) {
        return l;
    }
    return -1;

}
int findNumberKTimesPerRow(int a[][100] , int m , int n , int k ) {
    
    for (int j = 0 ; j < n;j++) {
        int count = 0;
        int temp = a[0][j];
        for (int i = 0 ; i < n ; i++) {
            if (temp == a[0][i]) {
                count++;
            }
        }
        if (count == k) {
            return temp;
        }
    }
    return 1;
}
struct Node {
    int data;
    Node* next;
    Node (int x) {
        this->data = x;
        this->next = NULL;
    }
};
struct List {
    Node* head;
    List () {
        head=NULL;
    }
};
void pushBack(List &L , int x){
    Node *newnode = new Node(x);
    if (L.head==NULL) {
        L.head=newnode;
        return;
    }
    Node*p=L.head;
    while (p->next) {
        p=p->next;
    }
    p->next = newnode;

}
void moveOdd2lEven2r(List &L) {
    Node* p =L.head;
    Node*Oddhead , *Oddtail , *EvenHead , *EvenTail;
    Oddhead= Oddtail = EvenHead = EvenTail = NULL;
    while (p) {
        Node* nxt = p->next;
        p->next = NULL;
        if (p->data%2==1) {
            if (Oddhead == NULL) {
                Oddhead=Oddtail = p;
            }
            else {
                Oddtail->next = p;
                Oddtail = Oddtail->next;
            }
        }
        else {
            if (EvenHead==NULL) {
                EvenHead=EvenTail=p;
            }
            else {
                EvenTail->next=p;
                EvenTail=EvenTail->next;
            }
        }
        p=nxt;
    }
    if (Oddhead != NULL) {
        L.head = Oddhead;
        Oddtail->next = EvenHead;
    } else {
        L.head = EvenHead;
    }


    Node*q = L.head;
    while (q) {
        cout << q->data << " ";
        q=q->next;        
    }
}
void print(List mylist) {
    for (Node*p = mylist.head ; p ; p=p->next) {
        cout << p->data <<" ";

    }
}


void unique (List &L) {
    Node*p = L.head;
    Node*pre=NULL;
    while (p && p->next) {
        Node*q=p->next;
        pre=p;
        while(q) {
            if (q->data==p->data) {
                pre->next = q->next;
                delete q;
                q=pre->next;
            }
            else {
                pre=q;
                q=q->next;
            }
        }
        p=p->next;
     }

}
int countUnicode(List &L) {
    Node*p=L.head;
    Node*pre=NULL;
    int res=0;
    while(p && p->next) {
        Node*nxt=p->next;
        pre=p;
        bool flag=true;
        while(nxt) {
            if (p->data== nxt->data) {
                flag=false;
                pre->next=nxt->next;
                delete nxt;
                nxt=pre->next;
            }
            else {
                pre=nxt;
                nxt=nxt->next;
            }
        }
        if (flag) res++;

        p=p->next;
    }
    return res;
}
int main () {
    List L;
    int n ; cin >> n;
    for (int i = 0 ; i < n ; i++) {
        int x; cin >> x;
        pushBack(L,x);
    }
    cout << countUnicode(L);
    


    return 0;
}

