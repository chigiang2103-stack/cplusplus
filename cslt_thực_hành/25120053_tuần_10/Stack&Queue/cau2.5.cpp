#include<iostream>
using namespace std;
struct Stack{
    int *data; 
    int top; 
    int capacity; 
};
void init(Stack &s , int capacity) {

    s.data = new int[capacity];
    s.capacity = capacity;
    s.top = -1;
}
bool isEmpty (Stack &s) {
    return (s.top==-1) ;
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
void D_to_B(Stack&s, int n) {
    int temp = n;
    while (n!=0) {
        push(s,n%2);
        n=n/2;
    }
    int res =0;
    while (s.top != -1) {
        res = res*10 + pop(s);
    }
    cout << temp <<" Decimal base to binary base : " << res <<endl;
}
void B_to_D (int num) {
    int res = 0;
    int temp = num;
    int i =0;
    while (num!=0) {
        res = res + (num%10)*pow(2,i);
        num=num/10;
        i++;
    }
    cout << temp << " Binary base to decimal base :" << res << endl;
}
void D_to_H (Stack&s ,int n) {
    int temp = n;
    while (n!=0) {
        push(s,n%16);
        n=n/16;
    }
    string res = "";
    while (s.top != -1) {
        int val = pop(s) ; 
        if (val >= 10) {
            res+= (char)('A' + (val - 10));
        }
        else {
            res += (char)('0' + val);
        }
    }
    cout << temp <<" Decimal base to hex base : " << res <<endl;

}
void H_to_D (string s) {
    long long deci =0;
    int res = 0;
    string temp = s;
    int k =0;
    for (int i = s.length()-1 ;i>=0;i--) {
        char c = s[i];
        if (c >='0' && c <= '9') {
            res+= c - '0';
        }
        else if ( c >= 'A' && c <= 'F') {
            res+= c - 'A' +10;
        }
        else if ( c >= 'a' && c <= 'f') {
            res+= c - 'a' +10;
        }
        else {
            cout <<"kí tự không hợp lệ " << endl;
        }
        deci = res*pow(16,k);
        k++;
    }
    cout << temp <<" Hec base to Decimal base : " << deci <<endl;








}
int main ()
{
    Stack s;
    init(s, 100);
    cout << "input n (DB) to Binary base : " << endl;
    int n ; 
    cin >> n;
    D_to_B(s,n);
    cout << "input m (BB) to Decimal base : " << endl;
    int m;
    cin >> m;
    B_to_D(m);
    cout << "input p (DB) to hex base : " << endl; 
    int p;
    cin >> p;
    D_to_H(s,p);
    cout << "input q (HB) to Decimal base : " << endl; 
    string q;
    cin >> q;
    H_to_D(q);
    return 0;

}