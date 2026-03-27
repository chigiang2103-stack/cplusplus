#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 int List_to_num(ListNode* l1) {
    int ans =0;
    ListNode* p =  l1;
    while (p) {
        ans = ans*10 + p->val;
        p=p->next;
    }
    return ans;
 }
void pushback (ListNode* l1 , int x) {
     ListNode*p = l1;
     ListNode*newnode = new ListNode(x);
    if (l1==NULL) {
        l1=newnode;
        return;
    }
    while (p->next) {
        p=p->next; 
    }
    p = newnode;
    
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l = NULL;
        int num1 = List_to_num(l1);
        int num2 = List_to_num(l2);
        int ans = num1 + num2;
        while (ans!=0) {
            pushback(l , ans%10);
            ans/=10;
        }
        return l;
}

int main () {   

        















    return 0;

}