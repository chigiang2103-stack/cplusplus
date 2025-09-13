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
    // 1 2 3 => 3 2 1
    int max = *ptr,mx=0;
    int min = *ptr,mn=0;

    for (int i= 1 ; i<n;i++) {
        if (max < *(ptr +i)) {
            max = *(ptr + i);
            mx = i;
        }
    }
    for (int i= 1 ; i<n;i++) {
        if (min > *(ptr +i)) {
            min = *(ptr + i);
            mn = i;
        }
    }
    int temp = *(ptr+mx);
    *(ptr+mx)=*(ptr+mn);
    *(ptr+mn)=temp;
    for (int i = 0;i<n;i++) {
        cout << *(ptr+i) << " ";
    }
    cout << endl;
    

}