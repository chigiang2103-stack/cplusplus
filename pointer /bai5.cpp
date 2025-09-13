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
    // 8 9 3 1 => 8 9 3 1 => 3 9 8 1 => 1 9 8 3 => 1 8 9 3=> 1 3 8 9
    int temp;
    for (int i =0;i<n-1;i++) {
        for (int j = i +1;j<n;j++) {
            if (*(ptr+i) > *(ptr+j)) {
                temp = *(ptr+i);
                *(ptr+i) = *(ptr+j);
                *(ptr+j)=temp;
            }
        }
    }
    for (int i =0 ; i< n ;i++) {
        cout << *(ptr+i) <<" ";
    }
    cout << endl;
}