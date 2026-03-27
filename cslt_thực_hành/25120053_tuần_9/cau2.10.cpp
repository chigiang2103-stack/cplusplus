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
    unsigned long long list_to_num();

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

unsigned long long linked_list::list_to_num() {
    node* cur = head;
    node*pre=NULL;
    unsigned long long num = 0;
    while (cur!=NULL) {
        num = num*10 + (cur->data); 
        cur=cur->next;
    }
    return num;


}


int main () {
    linked_list list;


    ifstream fin("input.txt"); 
    ofstream fout("output.txt");

    while (!fin.eof()) {
        int n; fin >>n;
        if (n< 0) {
            break;
        }
        list.push_back(n);
    }
    unsigned long long num ;
    num = list.list_to_num();
    fout << num ;
 





    fin.close();
    fout.close();


    



    return 0;
}
