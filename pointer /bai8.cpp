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
    int x ; cout<< "input x : "; cin >>x;
    *(ptr+n) = x;
    int temp;
    for (int i = 0 ;i <=n-1 ; i++) {
        for (int j = i+1;j<=n;j++) {
            if (*(ptr+i) > *(ptr+j)) {
                temp = *(ptr+i);
                *(ptr+i)= *(ptr+j);
                *(ptr+j) = temp;
            }
        }
    } 
    for (int i =0 ; i <=n  ;i++) {
    cout << *(ptr+i) <<" ";
    }
    cout << endl;


}