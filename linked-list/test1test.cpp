#include<bits/stdc++.h>
using namespace std;


struct node {
    long long data;
    node *next;
    node (long long data){
        this->data=data;
        this->next = NULL;
    }
};
struct linked_list {
    node*head;
    linked_list() {
        head=NULL;
    }
    void push_back(long long x);
    void print_list();
    bool check_increase();
};
void linked_list::push_back(long long x) {
    node *newnode = new node(x);
    node* temp = head;
    if (head==NULL) {
        head=newnode;
    }
    else {
        while (temp->next != NULL) {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void linked_list::print_list() {
    node *temp= head;
    while (temp!=NULL) {
        cout << temp->data <<" ";
        temp=temp->next;
    }
}
bool linked_list::check_increase() {
    node*temp=head;
    node*pre=NULL;
    while (temp!= NULL) {
        if (pre!= NULL) {
            if (temp->data < pre->data) {
                return false;
            }
        }
        pre=temp;
        temp=temp->next;
    }
    return true;
    
}
int main () {
    int n ;
    cin >> n;
    linked_list l;
    for (int i = 0 ;i<n;i++) {
        long long temp;
        cin >> temp;
        l.push_back(temp);
    }
    l.print_list();
    cout<< '\n';
    if(l.check_increase()) {
        cout <<"YES"<<endl;
    }
    else {
        cout <<"NO"<<endl;
    }
    
}