#include<iostream>
using namespace std;

struct ListNode {
    int val;
     ListNode *next;
    ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
 };




 class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head==NULL) return NULL ;
        if (head->next==NULL) return head;



        ListNode* slow = head;
        ListNode* fast =head;
        while (fast && fast->next) {
            slow = slow->next;
            fast =fast->next->next;
        }
        return slow;

    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * ans = NULL;
        ListNode* p = NULL;


        while (list1 && list2) {
            if (list1->val < list2->val) {
                if (ans==NULL) {
                    ans=p=list1;
                }
                else {
                    p->next= list1;
                    p=p->next;
                }
                list1=list1->next;
            }
            else {
                if (ans==NULL) ans=p=list2;
                else {
                    p->next=list2;
                    p=p->next;
                }
                list2=list2->next;
            }
        }

        while(list1) {
            if (ans==NULL) {
                    ans=p=list1;
                }
                else {
                    p->next= list1;
                    p=p->next;
                }
                list1=list1->next;
        }
        while (list2) {
             if (ans==NULL) ans=p=list2;
                else {
                    p->next=list2;
                    p=p->next;
                }
                list2=list2->next;
        }
        return ans;

        
    }
      ListNode* sortList(ListNode* head) {
        if (head==NULL) return NULL;
        ListNode* mid = middleNode(head);
        mid->next=NULL;
        ListNode* l = sortList(head);
        ListNode* r  = sortList(mid->next);
        return mergeTwoLists(l,r);

    }
};