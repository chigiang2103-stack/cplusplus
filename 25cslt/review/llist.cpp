#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next ;
    Node (int data) {
        this->data = data;
        this->next = NULL;
    }
};
struct List {
    Node*phead ;
    Node*ptail;
    List () {
        phead = NULL;
        ptail= NULL;
    }   
};
void pushBack(List &mylist,int x) {
    Node* newnode = new Node(x);
    Node*p = mylist.phead;
    if (mylist.phead == NULL) mylist.phead=newnode;
    else {
        while(p->next) {
            p=p->next;
        }
        p->next=newnode;
   }

}

bool checkprime(int x) {
    for (int i = 2; i <= sqrt(x);i++) {
        if (x%i==0) return false;
    }
    return x>=2;
}
// void removeprimenumber(List &mylist) {
//     Node*p = mylist.phead;
//     Node* pre = NULL;
//     while (p) {
//         if (checkprime(mylist.phead->data)) {
//             mylist.phead= p->next;
//             delete p;
//             p=mylist.phead;
//         }
//         else {
//                 if (checkprime(p->data)) {
//                     pre->next = p->next;
//                     delete p;
//                     p = pre->next;
//                 }
//                 else {
//                     pre = p;
//                     p=p->next;
//                 }
//         }
//     }
// }
// int count(List mylist, int x) {
//     int count = 0;
//     Node*p = mylist.phead ;
//     while(p) {
//         if (p->data == x) count++;
//         p=p->next;
//     }
//     return count;
// }
// int countUniqueCode(List mylist) {
//     Node*p = mylist.phead;
//      int res = mylist.phead->data;
//     while (p) {
//         if (count(mylist,p->data) > count(mylist,res)) {
//             res=p->data;
//         }
//         p=p->next;
//     }
//     for (Node*p = mylist.phead ; p ; p=p->next) {
//         if (p->data!=res && count(mylist,p->data) == count(mylist,res)) {
//             return 0;
//         }
//     }
//     return res;

// }
void print(List mylist) {
    for (Node*p = mylist.phead ; p ; p=p->next) {
        cout << p->data <<" ";

    }
}
// 1 2 3 4 5 6
void reverselist(List &mylist) {
    Node* p = mylist.phead;
    Node* pre = NULL;
        
    while (p) {
        Node* nxt = p->next;
        p->next= pre;
        pre =p ;
        p = nxt;
    }
    mylist.phead = pre;
}
void reducelist(List &mylist , int k ) {
    Node* p =mylist.phead;
    Node* pre = NULL;
    while (p) {
        p->data = p->data - k;
        if (p->data <= 0) {
            if (p==mylist.phead) {
                mylist.phead = p->next;
                delete p ;
                p= mylist.phead;
            }
            else {
                pre->next = p->next;
                delete p;
                p=pre->next;
            }
        }
        else {
            pre = p;
            p=p->next;
        }
    }
}
bool isprime(int n ) {
    for (int i = 2; i*i <= n;i++) {
        if (n%i==0) return false;
    }
    return n >= 2;
}
void reducepirme(List &mylist ) {
    Node*p = mylist.phead;
    Node*pre = NULL;
    while (p) {
        if (!isprime(p->data)) {
            if (p==mylist.phead) {
                mylist.phead = p->next;
                delete p;
                p =mylist.phead; 
            }
            else {
                pre->next = p->next;
                delete p;
                p = pre->next;
            }
        }
        else {
            pre = p;
            p=p->next;
        }
      
    }
}
void reducel(List &list1) {
    Node*p=list1.phead;
    Node*pre=NULL;
    while (p) {
        if (p->next) {
            pre=p;
            p=p->next;
        }
        else {
            if (pre) {
                int val = abs(p->data - pre->data);
                delete p;
                pre->data=val;
                pre->next=NULL;
                p=list1.phead;
                pre=NULL;
            }
            else {
                return ;
            }
        }
    }
}
void mergelientiep(List &list1) {
    Node*p=list1.phead;
    Node*pre=NULL;
    while(p) {
        if (isprime(p->data)) {
            pre=p;
            Node*q=p->next;
            int sum = p->data;
            while (q) {
                if (isprime(q->data)) {
                    sum+=q->data;
                    pre->data=sum;
                    pre->next=q->next;
                    delete q;
                    q=pre->next;
                }
                else {
                    break;
                }
            }
        }
        else {
            pre=p;
        }
        p=p->next;
    }
}
int main () {  
    List list1;
    int n ; cin >> n;
    for (int i = 0 ; i < n ; i++) {
        int x; cin >> x;
        pushBack(list1,x);
    }
    mergelientiep(list1);
    print(list1);






    return 0;
}