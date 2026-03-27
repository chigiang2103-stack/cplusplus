#include<iostream>
using namespace std;
int main() {
    int FindNumberKTimesPerRow(int a[][100] , int m ,int n,int k);
    int a[][100] = {{1,1,3,4,3,1,6},{2,1,1,1,3,3,9},{8,1,1,9,3,1,3}};
    int m=3,n=7,k=3;
    int res = FindNumberKTimesPerRow(a,m,n,k);
    cout << res << endl;


    return 0;
}
int FindNumberKTimesPerRow(int a[][100] , int m ,int n,int k) {
    // m =3 , n=7,k=2
    // 1 2 3 4 5 1 6
    // 2 7 1 1 3 5 9
    // 8 5 1 9 0 1 3
    // res = 1
    int count =1;
    for (int i = 0 ; i<n-1;i++) {
        for (int j = i+1;j<n;j++) {
            if (a[1][i]==a[1][j]) {
                count++;
            }
        }
        if (count == k) {
            return a[1][i];
        }
        count = 1;
    }
    return -1;
}
