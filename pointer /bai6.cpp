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
    int x ,index; 
    cout << "input x : ";cin>>x;
    for (int i = 0 ; i<n ;i++) {
        if (*(ptr+i)==x) {
            index = i;
        }
    }
    // 12345 x = 3 => 1245 i = 2
    for (int i = index ; i < n ; i++) {
        *(ptr+i) = *(ptr+i+1);
    }
    n--;
     for (int i =0 ; i< n ;i++) {
        cout << *(ptr+i) <<" ";
    }
    cout << endl;
}