#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

#define MAX_NAME 150
#define MAX_LOC  50
#define MAX_CAT  50
const int Max=100;



struct University {
char institution[MAX_NAME]; 
char location[MAX_LOC]; 
float academic;
float employer;
float citations;
float h;
char category[MAX_CAT];
};




struct Node { 
    University val;
    Node* next;
};


Node* createNode(University u) {
    Node *newnode = new Node ;

    newnode->val = u;

    newnode->next = NULL;

    return newnode;

}
void addLast(Node*& head, University u) {
    Node*temp=head;

    if (head==NULL) {
        head=createNode(u);
    }
    else {
        while(temp->next!=NULL) {
            temp=temp->next;
        }
        temp->next=createNode(u);
    }


}

int readFromFile(const char* filename, Node*& head) {
    int n=0;
    ifstream fin("universities.txt");
    char line[Max];

    fin.getline(line,Max);
    
    while(fin.getline(line,Max)) {
            University u;
            strcpy(u.institution, strtok(line,","));
            strcpy(u.location, strtok(NULL,","));
            u.academic=atof(strtok(NULL,","));
            u.employer=atof(strtok(NULL,","));
            u.citations=atof(strtok(NULL,","));
            u.h=atof(strtok(NULL,","));
            strcpy(u.category, strtok(NULL,"*"));
            addLast(head, u);
            n++;
    }
    fin.close();
    return n;



}
void printList(Node* head) {
    Node*temp=head;
    while(temp!=NULL) {
        cout << temp->val.institution << endl;
        temp=temp->next;
    }
}

void findByLocation(Node* head, const char* location) {
    Node *cur =head;
    while(cur!=NULL) {
        if (!strcmp(cur->val.location , location)) {
            cout << cur->val.institution << endl;
        }
        cur=cur->next;
    }
}

float averageScore(const University& u) {
    return (u.academic + u.employer + u.citations + u.h)/4;
}
void sortByAcademicDesc(Node*& head) {
    Node*cur=head;
    while (cur!=NULL) {
        Node*nxt=cur->next;
        while (nxt!=NULL) {
            if (cur->val.academic < nxt->val.academic) {
                swap(cur->val , nxt->val);
            }
            nxt=nxt->next;
        }
        cur=cur->next;
    }
}








int main () {
    Node *head=NULL;

    int n =readFromFile("universities.txt",head);

    findByLocation( head, "Taiwan");
    sortByAcademicDesc(head);
    printList(head);



    return 0;
}