#include<iostream>
using namespace std;
int main () {
    int n; cout <<"nhập n : "; cin >>n;
    int arr[20];
    for (int i = 0 ; i< n ;i++) {
        printf("nhập giá trị %d của mảng",i);
        cin >>arr[i];
    }
    int sumarray (int arr[20], int n);
    cout << sumarray( arr, n-1 )<<endl;
}
int sumarray (int arr[20] , int n) {
    if (n==0) return arr[0];
    return arr[n] + sumarray(arr , n-1);
}