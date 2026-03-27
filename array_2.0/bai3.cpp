#include<iostream>
using namespace std;
int main () {
    int n ,m;
 cin >> n >> m ;
    int ** ptr = new int *[n];
    for (int i =0 ; i<n;i++) {
        ptr[i] = new int[m];
        for (int j = 0 ; j < m ; j++) {
            cin >> ptr[i][j];
        }
    }
    // 1 2 3
    // 8 9 4  => 1 2 3 4 5 6 7 8 9 
    // 7 6 5 
    int top=0 , bottom = n-1, letf=0 , right=m-1;
    while (top < bottom && letf < right) {
        if (top < bottom) {
            for (int i = letf ; i <= right ; i++) {
                cout << ptr[top][i] <<" " ;
            }
            top++;
        }
        if (letf < right ) {
            for (int i = top ; i <= bottom ; i++) {
                cout << ptr[i][right] << " ";
            }
            right--;
        }
         if (top < bottom) {
            for (int i = right ; i >= letf ; i--) {
                cout << ptr[bottom][i] <<" " ;
            }
            bottom--;
        }
          if (letf < right ) {
            for (int i = bottom ; i >= top ; i--) {
                cout << ptr[i][letf] << " ";
            }
            letf++;
        }


    }
    cout <<endl;
    return 0;
    
    


}
