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
    int temp = *(ptr+0);
    for (int i = 1 ; i<n; i++) {
        if (temp < *(ptr +i )) {
            temp = *(ptr+i);
        }
    }
    cout << "max : " <<temp <<endl;
}