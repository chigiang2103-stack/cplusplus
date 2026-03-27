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
    void sort_list(int x);
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


void linked_list::sort_list(int x) {
    node*cur = head;
    node* newnode = new node(x);
    node*pre=NULL;
        if (head==NULL || head->data > x) {
            newnode->next = head;
            head = newnode ;
            return;
        }
        pre = cur;
        cur = cur ->next;

        while (cur != NULL && cur->data < x) {
            pre=cur;
            cur=cur->next;
        }

        pre->next = newnode;
        newnode->next = cur;


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

    ifstream fin("input.txt"); 
    ofstream fout("output.txt");

    while (!fin.eof()) {
        int n;
        fin >> n;
        if (n==0) break;
        list.push_back(n);
    }
    int x; 
    cin >> x;
    list.sort_list(x);
    list.list_to_file(fout);






    fin.close();
    fout.close();


    



    return 0;
}
