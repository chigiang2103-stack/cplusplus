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
    void remove_x (int x);
    void list_to_file(ofstream& fout);
    void pop_front () {
        if (head==NULL) return;
        node*temp=head;
        head=head->next;
        delete temp;
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


void linked_list::remove_x(int x) {
    node* temp = head;
    node* pre = NULL;

    while (temp != NULL) {
        if (temp->data == x) {
            if (pre==NULL) {
                temp=temp->next;
                pop_front();
            }
            else {
                pre->next = temp->next; 
                delete temp;           
                temp = pre->next;      
            }                   
        } else {
            pre = temp;            
            temp = temp->next;      
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


   
    list.remove_x(x);
    list.list_to_file(fout);






    fin.close();
    fout.close();


    



    return 0;
}
