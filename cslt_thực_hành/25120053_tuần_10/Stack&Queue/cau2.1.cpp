#include<iostream>
using namespace std;

struct Stack{
    int *data; // dynamic array
    int top; // index of top element
    int capacity; // size of stack
};
void init(Stack &s , int capacity) {

    s.data = new int[capacity];
    s.capacity = capacity;
    s.top = -1;
}
bool isEmpty (Stack &s) {
    return s.top ==-1 ;
}
void push(Stack &s , int x) {
    if (s.top == s.capacity -1) cout << "full" << endl;
    else {
        s.top++;
        s.data[s.top] = x;
    }

}

int pop(Stack &s) {
    if (isEmpty(s)) return -1;
    return s.data[s.top--];
}

void empty(Stack &s ) {
    s.top = -1;
    s.capacity = 0;
}
int size(Stack&s) {
    return s.top+1;
}


int main () {
    Stack s;
    init(s,5);
    push(s,1);
    push(s,5);
    push(s,2);
    push(s,3);
    push(s,4);
    cout << pop(s) << endl;
    cout << size(s) << endl;



    return 0;
}