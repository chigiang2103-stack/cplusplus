#include<iostream>
using namespace std;
struct node {
    int data;
    node* pNext;
    node () {
        data=0;
        pNext=NULL;
    }
    node(int data){
        this->data=data;
        this->pNext=NULL;
    }
};
struct list {
    node* head;
    list() {
        head=NULL;
    }
    void insertNode(int data);
    void MoveOdd2leftEven2Right(list &l);
    void printlist();
};
void list::insertNode(int data) {
    node* newnode = new node(data);
    if (head==NULL) {
        head=newnode;
        return;
    }
    node* temp=head;
    while(temp->pNext!=NULL) {
        temp=temp->pNext;
    }
    temp->pNext=newnode;
}
void list::printlist() {
    node* temp = head;
    while (temp !=NULL) {
        cout << temp->data << " ";
        temp=temp->pNext;
    }
    cout << endl;
}
void list::MoveOdd2leftEven2Right(list &l) {
    // 1->2->3->4->5->NULL
    // 1->3->5->2->4
    node* oddhead = NULL; // đầu lẽ
    node* oddtail = NULL; // đuôi lẽ
    node* evenhead=NULL; // đầu chẳn
    node* eventail =NULL; // đuôi chẳn
    node* temp = head;
    while (temp!=NULL) {
        if (temp->data%2!=0) { // value của temp là lẽ
            if (oddhead==NULL) { 
                oddhead=oddtail=temp;
            }
            else {
                oddtail->pNext=temp;
                oddtail=temp;
            }
        }
        else {
            if(evenhead==NULL){
                evenhead=eventail=temp;
            }
            else {
                eventail->pNext=temp;
                eventail=temp;
            }
        }
        temp=temp->pNext;
    }
    if (oddtail!=NULL) {
        oddtail->pNext=evenhead;
    }
    if (eventail!=NULL) {
        eventail->pNext=NULL;
    }

}
int main() {
    list l;
    l.insertNode(1);
    l.insertNode(2);
    l.insertNode(3);
    l.insertNode(4);
    l.insertNode(5);
    l.MoveOdd2leftEven2Right(l);
    l.printlist();

    return 0;
}


