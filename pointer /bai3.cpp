#include<iostream>
using namespace std;
int main() {
    int n; 
    cout << "input n : "; cin >>n;
    int *ptr = new int [n]; // cấp n bộ nhớ cho mảng
    for (int i = 0 ; i < n ; i++) {
        printf("input value of %d : ",i);
        cin >> *(ptr + i);
    }
    for (int i = n-1 ; i>=0;i--) {
        cout << *(ptr + i ) << " ";
    }
    cout << endl;
}