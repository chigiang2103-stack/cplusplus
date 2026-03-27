#include <bits/stdc++.h>
using namespace std; 

long long queryInterleave(long long n, long long m) {
    int arr1[100];
    int len_n = 0 ;
    while (n!=0) {
        arr1[len_n]=n%10;
        n=n/10;
        len_n++;
    }
    int arr2[100];
    int len_m = 0 ;
    while (m!=0) {
        arr2[len_m]=m%10;
        m=m/10;
        len_m++;
    }
    int num=0;
    if (len_n >= len_m) {
        for (int i = len_m -1; i >=0 ; i--) {
            num=num*10 + arr1[len_n-1];
            num=num*10 + arr2[i];
            len_n--;
        }
        for (int j = len_n-1;j>=0;j--) {
            num = num*10 + arr1[j];
        }
    }
    else {
        for (int i = len_n-1 ; i >=0 ; i--) {
            num=num*10 + arr1[i];
            num=num*10 + arr2[len_m-1];
            len_m--;
        }
        for (int i = len_m-1;i>=0;i--) {
            num = num*10 + arr2[i];
        }
    }
    return num;
}
int main () {
  cout << queryInterleave(32247,7147233) << endl;




    return 0;
}