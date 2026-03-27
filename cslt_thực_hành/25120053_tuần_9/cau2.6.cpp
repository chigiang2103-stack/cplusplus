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
    void list_sum(linked_list &list_out);
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


void linked_list::list_sum(linked_list &list_out) {
    node* cur = head;
    int temp =0;
    while (cur!= NULL) {
        temp += cur->data ;
        list_out.push_back(temp);
        cur=cur->next;

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
        int n;
        fin >> n;
        if (n==0) break;
        list.push_back(n);
    }

    list.list_sum(list_out);
    list_out.list_to_file(fout);






    fin.close();
    fout.close();


    



    return 0;
}
