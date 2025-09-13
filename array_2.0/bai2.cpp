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
    // 1 7 9     1 3 2 
    // 4 3 2 =>  4 5 8
    // 6 5 8     6 7 9 
    for (int k = 0 ; k< m ;k++) {
        int temp = ptr[0][k];
        for (int i = 1 ; i< n; i++) {
            if (ptr[i-1][k] > ptr[i][k]) {
                temp = ptr[i][k];
                ptr[i][k] = ptr[i-1][k];
                ptr[i-1][k]=temp;
            }
    }
    }
    for (int i = 0 ; i<n;i++) {
        for (int j = 0 ; j<m ; j++) {
             cout << ptr[i][j] << " ";
            }
    cout << endl;
}

}
