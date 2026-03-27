#include<iostream>
using namespace std;

struct Queue{
    int *data; // dynamic array
    int in;
    int out;
    int sizecurrent ;
    int capacity; // size of queue
};
void init(Queue &q , int capacity) {

    q.data = new int[capacity];
    q.capacity = capacity;
    q.sizecurrent = 0;
    q.in = 0;
    q.out =0;
}
void enqueue(Queue& q,int x ) {
    if (q.sizecurrent == q.capacity) {
        cout << "FULL" << endl;
        return ;
    }
    q.data[q.in] = x;
    q.in = (q.in + 1)%q.capacity;
    q.sizecurrent++;


}
bool isEmpty(Queue &q) {
    if (q.sizecurrent==0) return true;
    return false; 
}
int dequeue(Queue& q) {
    if (isEmpty(q)) {
        cout <<"queue trống"<< endl;
        return 0;
    }
    int value = q.data[q.out];
    q.out = (q.out + 1)%q.capacity;
    q.sizecurrent--;
    return value;
}

void empty(Queue&q) {
    q.sizecurrent = 0;
}
int size(Queue &q) {
    return q.sizecurrent ;
}
int main () {
    Queue q;
    init(q,5);
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    dequeue(q);
    int tmp = q.out;
    for (int i =0 ; i< size(q);i++) {
        cout << q.data[(tmp+i)%q.capacity] << " ";
    }   
    cout << endl;




    return 0;
}