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

    int shared_list(linked_list &list_out , int num);


    
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

int linked_list::shared_list(linked_list &list_out , int num) {
    node* cur = head;
    node*pre=NULL;
    int count = 1;
    node*cur2 = list_out.head;

    while(cur!=NULL) {
        while(cur2!=NULL) {
            pre=cur2;
            cur2=cur2->next;
        }
        count++;
        cur=cur->next;
        if (count==num) {
            pre->next = cur;
        }
    }

    int len_1 =0;
    int len_2 =0;
    node *ptr1 = head ;
    node *ptr2 = list_out.head;


    while (ptr1!=NULL) {
        len_1++;
        ptr1=ptr1->next;
    }
    while (ptr2!=NULL) {
        len_2++;
        ptr2=ptr2->next;
    }

    if (len_1 > len_2) {
        int d= len_1-len_2;
        node* p1 = head;
        node*p2=list_out.head;
        int c1=0;
        while (p1!=NULL) {
            p1=p1->next;
            c1++;
            if (c1==d) {
                while (p1->data != p2->data ) {
                    p1=p1->next;
                    p2=p2->next;
                }
                return p1->data;
            }
        }
    }
    else {
        int d= len_2-len_1;
        node* p1 = head;
        node*p2=list_out.head;
        int c1=0;
        while (p2!=NULL) {
            p2=p2->next;
            c1++;
            if (c1==d) {
                while (p1->data != p2->data ) {
                    p1=p1->next;
                    p2=p2->next;
                }
                return p1->data;
            }
        }

    }
    return 0;
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
    int num ;
    while (!fin.eof()) {
         fin >> num;
    }
    int res ;

    res= list.shared_list(list_out , num);
    fout << res;








    fin.close();
    fout.close();


    



    return 0;
}
