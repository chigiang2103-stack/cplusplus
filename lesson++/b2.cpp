#include<iostream>
using namespace std;

class node {
    public :
    int data;
    node*next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
class linked_list {
    node*head;
    public:
    linked_list() {
        this->head=NULL;
    }
    void insertnode(int);
    void printlist();

};
void linked_list :: insertnode(int data) {
    node* newnode = new node(data);
    if (head=NULL) {
        head =newnode;
        return ;
    }
    node*temp = head;
    while (temp->next !=NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}
void linked_list::printlist() {
    node*temp = head;
    while (temp!=NULL ) {
        cout << temp->data <<" ";
        temp =temp->next;
    }
}

