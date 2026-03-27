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
    void insert_even_num();
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



void linked_list::insert_even_num() {
   int i = 2;
   node* current = head;
   node*pre = NULL;

   while (current != NULL) {
        node* newnode = new node(i);
        if (current == head) {
            newnode->next = current;
            head=newnode;
            pre=current;
            current=current->next;
        }
        else {
            pre->next=newnode;
            newnode->next = current;
            pre = current ;
            current = current->next;
        }
        i=i+2;

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

    ifstream fin("input.txt"); 
    ofstream fout("output.txt");

    while (!fin.eof()) {
        int n;
        fin >> n;
        if (n==0) break;
        list.push_back(n);
    }
    list.insert_even_num();
    list.list_to_file(fout);






    fin.close();
    fout.close();


    



    return 0;
}
