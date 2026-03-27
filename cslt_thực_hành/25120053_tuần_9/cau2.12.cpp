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
    void insertlist(linked_list &list2 , int k) {
        node* cur = head;
        for (int i= 1 ;i<k;i++) {
            cur=cur->next;
        }
        node* nxt = cur->next;
        cur->next = list2.head ;

        node *temp = list2.head ; 
        node *pre = NULL;
        while (temp!=NULL) {
            pre=temp;
            temp=temp->next;
        }
        pre->next = nxt;
    } 
    void printlist() {
        node*temp=head;
        while (temp!= NULL) {
            cout << temp->data <<" ";
            temp=temp->next;
        }
        cout << endl;
    }
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



int main () {
    linked_list list;
    linked_list list2;

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
        int n ; fin >> n;
        if (n==0) break;
        list2.push_back(n);
    }



    list.insertlist(list2, 3);


    list.printlist();
    







    fin.close();
    fout.close();


    



    return 0;
}
