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

void addLast(Node*& head, int x) {
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

void printList(Node* head) {
    if (head == NULL) return;
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) cout << "->";
        head = head->next;
    }
    cout << endl;
}

Node* longestIncreasingSublist(Node* head) {
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
        addLast(res, bestStart->data);
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

int main() {
    Node* head = NULL;
    int x;

    while (cin >> x && x != 0) {
        addLast(head, x);
    }

    Node* rows[100];
    int rowCount = 0;
    Node* cur = head;

    while (cur != NULL) {
        rows[rowCount] = NULL;
        int cnt = 0;
        while (cur != NULL && cnt < 5) {
            addLast(rows[rowCount], cur->data);
            cur = cur->next;
            cnt++;
        }
        rowCount++;
    }

    for (int i = 0; i < rowCount; i++) {
        Node* lis = longestIncreasingSublist(rows[i]);
        deleteNegative(lis);
        if (lis != NULL)
            printList(lis);
    }

    return 0;
}