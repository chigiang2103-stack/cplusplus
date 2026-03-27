#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void pushBack(Node*& head, int x) {
    Node* p = createNode(x);
    if (head == NULL) {
        head = p;
        return;
    }
    Node* cur = head;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = p;
}

void print(Node* head) {
    if (head == NULL) return;
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) cout << "->";
        head = head->next;
    }
    cout << endl;
}
// 1 2 3 4 2 3 

Node* longest(Node* head) {
    if (head == NULL) return NULL;

    Node *bestStart = head, *curStart = head;
    int bestLen = 1, curLen = 1;

    Node* cur = head;
    while (cur->next != NULL) {
        if (cur->next->data > cur->data) {
            curLen++;
        } else {
            if (curLen > bestLen) {
                bestLen = curLen;
                bestStart = curStart;
            }
            curStart = cur->next;
            curLen = 1;
        }
        cur = cur->next;
    }

    if (curLen > bestLen) {
        bestLen = curLen;
        bestStart = curStart;
    }

    Node* res = NULL;
    for (int i = 0; i < bestLen; i++) {
        pushBack(res, bestStart->data);
        bestStart = bestStart->next;
    }
    return res;
}

void deleteNegative(Node*& head) {
    while (head != NULL && head->data < 0) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }

    Node* cur = head;
    while (cur != NULL && cur->next != NULL) {
        if (cur->next->data < 0) {
            Node* tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
        } else {
            cur = cur->next;
        }
    }
}
Node* gettail(Node*head) {
    Node*p=head;
    while(p->next) {
        p=p->next;
    }
    return p;
}
Node* partitionList(Node* head, int x) {
    Node* lessList = new Node;
    Node* graterList = new Node;
    lessList = createNode(0);
    graterList = createNode(0);

    Node* lesshead = lessList ; 
    Node * greaterhead = graterList;


    Node* cur = head;
    while (cur) {
        if (cur->data < x) {
            lesshead->next = cur;
            lesshead=lesshead->next;
        }
        else {
            greaterhead->next = cur;
            greaterhead = greaterhead->next;
        }
        cur=cur->next;
    }
    greaterhead->next = NULL;
    lesshead->next = graterList->next;
    head = lessList->next;
    return  head;

}
int main() {
    Node* head = NULL;
    int x;
    pushBack(head,1);
    pushBack(head,4);
    pushBack(head,3);
    pushBack(head,2);
    pushBack(head,5);
    pushBack(head,2);

    partitionList(head,3);
    print(head);

    return 0;
}