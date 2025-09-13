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
    // 8 9 4  => 1 2 3 4 5 6 7 8 9 
    // 7 6 5 
    int top=0 , bottom = n-1, letf=0 , right=m-1;
    while (top <= bottom && letf <= right) {
        for (int i =0; i<m;i++) {
            cout << ptr[top][i];
        }
        top++;
        for (int j=1;j<n;j++) {
            cout << ptr[right][j]; 
        }
        right--;
        for (int i = m-1;i>0;i++) {
            cout << ptr[bottom][m];
        }
        bottom--;
        for (int i = 1 ; i<m-1;i++) {
            cout << ptr[letf][i];
        }
        letf++;
        return 0;
    }
    return 0;
    
    


}
