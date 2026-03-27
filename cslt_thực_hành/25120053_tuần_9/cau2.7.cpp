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
    void list1_to_2(linked_list &list_out);
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

void linked_list::list1_to_2(linked_list &list_out) {
    node* cur = head;
    node*pre=NULL;
    int temp =0;
    int count=0;
    while (cur!= NULL) {
        if (pre==NULL || count%2==0) {
            pre=cur;
            cur=cur->next;
            count++;
        }
        else{
            temp=cur->data;
            list_out.push_back(temp);
            pre->next=cur->next;
            delete cur;
            cur = pre->next;
            count++;
        }
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

    list.list1_to_2(list_out);
    list.list_to_file(fout);
    fout <<"\n";
    list_out.list_to_file(fout);






    fin.close();
    fout.close();


    



    return 0;
}
