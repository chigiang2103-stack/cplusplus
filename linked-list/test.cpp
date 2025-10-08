#include<bits/stdc++.h>
using namespace std;

class node { // khởi tạo node
    public :
    int data ;
    node* next; // tạo node next = null
    node() { // constructor  hàm khởi tạo
        data=0;
        next = NULL ;
    }
    node(int data ) { // hàm khởi tạo khi tạo node mới 
        this->data=data;
        this->next=NULL;
    }
};
class linked_list { // tạo linked list
    node*head; // tạo node head 
    public:
    linked_list() { // gán head = null
        head =NULL;
    }
    void insertNode(int); // hàm khởi tạo node mới
    void printlist(); // hàm in list
    void deleteNode(int); // hàm xoá node 
};
void linked_list::insertNode(int data) { // hàm khởi tạo node mới 
    node* newnode = new node(data); // tạo newnode chứa data
    if (head == NULL) { // kiểm tra head 
        head = newnode; // gán head = newnode nếu head = null
        return ;
    }
    node* temp = head; // tạo node tạm = head
    while (temp -> next != NULL) { // duyệt cái ô kề head 
        temp = temp -> next; // duyệt tới khi ô next = null
    }
    temp -> next = newnode ; // gán newnode = ô đang null
}
void linked_list::printlist() { // hàm in list
    node* temp = head; // tạo node tạm = head
    if (head == NULL) { // check list trống
        cout <<"List empty "<<endl;
        return;
    }
    while (temp != NULL) { // in data
        cout << temp->data <<" ";
        temp = temp->next;
    }
}
void linked_list::deleteNode(int index_nodeoff) { // hàm xoá node
    node*temp1 = head , *temp2 = NULL ; // khởi tạo 2 node tạm 
    int listlen = 0; // list origin = 0

    if (head == NULL) { // check list trống
        cout <<"empty"<<endl;
        return ;
    }
    while (temp1 != NULL) { // tính độ dài list
        temp1 = temp1 ->next;
        listlen++;
    }
    if (listlen < index_nodeoff) { // check nằm ngoài phạm vi list
        cout <<"out of range " << endl;
        return ;
    }

    temp1 = head;
    if (index_nodeoff == 1) {
        head = head->next;
        delete temp1;
        return ;
    }
    // head ( node 1) -> node 2->node 3->node 4 -> ... -> null
    // index = 3 // temp2 = head ( node 1 ) , temp1 -> next (node 2), index =2 , temp2 = next(node 2) , temp1->next(node3)
    // temp2 là ô trước ô của temp1
    // temp2 node 2 // temp1 node 3

    while (index_nodeoff > 1) {
        temp2 = temp1;
        temp1 = temp1->next;
        index_nodeoff--;
    }
    temp2->next = temp1->next;
    // temp2 (node 2) trỏ đến node next của temp1 (node4)
    delete temp1; // xoá temp1 (node3)
}
int main() {
    linked_list list ;
    list.insertNode(1);
    list.insertNode(9);
    list.insertNode(3);
    list.insertNode(4);
    cout <<"element of list : ";
    list.printlist();
    cout << endl;


    list.deleteNode(2);
    cout << "element of list :";
    list.printlist();
    cout<< endl;

    return 0;
}
