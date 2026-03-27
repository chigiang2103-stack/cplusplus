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
    void remove_dup();
    void list_to_file(ofstream& fout);
    void pop_front () {
        if (head==NULL) return;
        node*temp=head;
        head=head->next;
        delete temp;
    }
    bool check_val(node *cur) {
        for (node*temp=head ; temp!=cur ;temp=temp->next) {
            if (temp->data==cur->data) return true;
        }
        return false;
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



void linked_list::remove_dup() {
    node* temp = head;
    node* pre = NULL;

    while (temp != NULL) {
        if (check_val(temp)) {
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
    list.remove_dup();
    list.list_to_file(fout);






    fin.close();
    fout.close();


    



    return 0;
}
