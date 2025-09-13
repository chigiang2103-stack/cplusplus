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
        // print hàng tren cùng 
        for (int i =letf; i<= right ;i++) {
            cout << ptr[top][i];
        }
        top++;
        // print hàng ngoài cùng bên phải 
        for (int j=top;j<=bottom;j++) {
            cout << ptr[j][right]; 
        }
        right--;
          // print hàng dứoi cùng 
          if (top <= bottom ) {
            for (int i = right;i>=letf;i--) {
                cout << ptr[bottom][i];
            }
        bottom--;
          }
          //print hàng ngoài cùng bên trái 
          if (letf <= right) {
        for (int i = bottom ; i>=top;i--) {
            cout << ptr[i][letf];
        }
        letf++;
          }
    }
    cout <<endl;
    return 0;
    
    


}
