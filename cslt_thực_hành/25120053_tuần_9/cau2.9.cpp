#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
struct node {
    int data;
    node *next ;


    node (int data) {
        this->data=data;
        this->next=NULL;
    }
};
struct linked_list {
    node* head ;
    linked_list () {
        head=NULL;
    }
    void push_back (int x );
    void list2_to_1(linked_list &list_out);
    void list_to_file(ofstream& fout);


    
};

void linked_list::push_back (int x ) {
    node* newnode = new node(x);
    node* temp =head;
    if (head==NULL) {
        head=newnode;
    }
    else {
        while (temp->next!=NULL) {
        temp=temp->next;
        }
        temp->next=newnode;
    }
    }

void linked_list::list2_to_1(linked_list &list_out) {
    node* cur = head;
    node*pre=NULL;

    node*temp = list_out.head;

    // 10 30 50 70 90 110 0
    // 20 40 60 0
    while (cur!= NULL) {
        pre=cur;
        cur = cur->next;
    }
    if (temp!=NULL) {
        pre->next = temp;
    }
    }

void linked_list::list_to_file(ofstream& fout) {
    node*temp=head;
    while(temp!=NULL) {
        fout << temp->data <<" " ;
        temp=temp->next;
    }
    fout <<0 ;
}
int main () {
    linked_list list;
    linked_list list_out;

    ifstream fin("input.txt"); 
    ofstream fout("output.txt");

    while (!fin.eof()) {
        int n; fin >>n;
        if (n==0) {
            break;
        }
        list.push_back(n);
    }
    while (!fin.eof()) {
        int n; fin >>n;
        if (n==0) {
            break;
        }
        list_out.push_back(n);
    }

    list.list2_to_1(list_out);
    list.list_to_file(fout);







    fin.close();
    fout.close();


    



    return 0;
}
