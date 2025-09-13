#include<iostream>
using namespace std;
int main () {
    int n ,m;
    cout <<"input n , m : "; cin >> n >> m ;
    int ** ptr = new int *[n];
    for (int i =0 ; i<n;i++) {
        ptr[i] = new int[m];
        for (int j = 0 ; j < m ; j++) {
            printf("nhập arr[%d][%d] : ",i,j);
            cin >> ptr[i][j];
        }
    }
    // 1 2 3
    // 4 5 6 
    // 7 8 9 
    float avg = 0.0;
    for (int i = 0 ; i<n;i++) {
        for (int j = 0 ; j<m ; j++) {
            avg += ptr[i][j];
            }
}
cout << avg/(m*n) <<endl;
}
