#include<iostream>
#include<math.h>
using namespace std;

struct node {
    int data ;
    node* pNext;
    node() {
        data=0;
        pNext=NULL;
    }
    node(int data){
        this->data=data;
        this->pNext=NULL;
    }
};
struct list{
    node* head;
    list() {
        head=NULL;
    }
    void insertNode(int data);
    void printlist();
    void reduceList(list &l ,int k);
};
void list :: insertNode(int data){
    node* newnode =new  node(data);
    if (head=NULL) {
        head = newnode;
        return ;
    }
    node* temp= head;
    while(temp->pNext != NULL) {
        temp=temp->pNext;
    }
    temp->pNext=newnode;

}
void list ::printlist() {
    node*temp=head;

    while(temp!=NULL){
        cout << temp->data <<" ";
        temp=temp->pNext;
    }
    cout << endl;

}
void list::reduceList(list &l , int k) {
    // 1->2->3->5->6->8->NULL
    // 4->5>6->8->NULL
    // 7->8->NULL
    // 1
    node*temp=head;
    int len=0;
    while(temp!=NULL) {
        len+=1;
        temp=temp->pNext;
    }
    // k =3;
    int s1 ;
    while (k<len) {
        s1=abs((temp->data)-((temp->pNext)->data)-(((temp->pNext)->pNext)->data));
        (((temp->pNext)->pNext)->data)=s1;
        len=len-k;
    }





    


}