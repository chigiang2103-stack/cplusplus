#include<iostream>
using namespace std;

struct ListNode {
    int val; 
    ListNode* next;

};
int size(ListNode*head) {
    int len=0;
    for (ListNode*p = head ; p ; p=p->next) {
        len++;
    }
    return len;
}

int getValue (ListNode*head , int index) {
    ListNode * p = head;
    for (int i = 1 ; i < index ;i++) {
        p=p->next;
    }
    return p->val;
}
void reverse(ListNode*&head) {
    ListNode*p=head;
    ListNode *pre = NULL;
    while (p) {
        ListNode * nxt = p->next;
        p->next = pre;
        pre = p;
        p = nxt;
    } 
    head = pre;
}

void reverseBetween(ListNode* &head, int left, int right) {
        int i = 1;
        ListNode *p = head;
        ListNode *pre = NULL;
        ListNode* pL =NULL , *pR = NULL , *preL = NULL , *neR=NULL;
        while (p) {
            if (i==left) pL = p;
            if (i==right) pR = p;
            if (i==left-1) preL=p;
            if (i==right+1) neR =p;
            if (i>= left && i <= right) {
                ListNode * nxt = p->next;
                p->next = pre;
                pre = p;
                p = nxt;
            }
            else {
                pre = p;
                p=p->next;
            }
            i++;
        }
        pL->next = neR; 
        if (preL) preL->next = pR;
        else head = pR;
    }
int main() {
    ListNode * head;
    reverse(head);



    return 0;
}