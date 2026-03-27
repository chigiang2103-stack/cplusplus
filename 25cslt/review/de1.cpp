#include <bits/stdc++.h>
using namespace std;
void printX(int n ) {
    for (int i = 1 ; i<= n ; i++) {
        for (int j =1 ; j <=n;j++) {
            if ( j ==i ||j ==n-i +1) {
                cout <<"*";
            }
            else {
                cout <<".";
            }
        }
        cout << endl;
    }
}
void printSumPair(int a[] , int n) {
    int temp =n;
    while (n!=1) {
        int index=0;
        for (int i = 0 ; i < n ;i=i+2) {
            int k ;
            if (i==n-1) {
                k = a[n-1];
                temp++;
            }
            else {
                k = a[i] + a[i+1];
            }
            a[index] = k;
            index++;
            temp--;
        }
        n = temp;
        for (int i = 0 ; i < n ;i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}
void findSaddlePoint(int a[][100], int n , int m ) {
    for (int i = 0 ; i < n ; i++) {
        int min = a[i][0];
        for (int j =0 ;j< m ;j++) {
            if (min > a[i][j]) {
                min = a[i][j]; 
            }
        }
        for (int j = 0 ;j< m ;j++) {
            if (a[i][j] == min) {
                bool flag = true;
                for (int k = 0 ; k < n;k++) {
                    if (min < a[k][j]) {
                        flag=false;
                        break;
                    }
                }
                if (flag) {
                    printf("(%d,%d)",i,j);
                }
            }
        }
    }
}
void printPascalTringle(int n) {
    int a[100][100] = {0};
    for (int i =0 ;i <n;i++) {
        a[i][0] = 1;
    }
    for (int i =1 ;i<n;i++) {
        for (int j = 1 ; j <=i;j++) {
            a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
    }
    for (int i =0 ;i<n;i++) {
        for (int j = 0 ; j <=i;j++) {
            cout << a[i][j] <<" ";
        }
        cout << endl;
    }

}

 int main() {
    string s = "abcde";
    int len =s.length();
    for (int i = 0 ; i < len ; i++) {
        s[i] = s[i] - 32;
    }
    string temp;
    int k = 0;
    for (int i = len-1 ; i >=0;i--) {
        temp[k] = s[i];
    }
    if (len <=10) {
        s = s + "_J97";
    }
    cout << s << endl;
    




    return 0;
 }