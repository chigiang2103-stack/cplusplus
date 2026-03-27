#include<iostream>
using namespace std;
int sumsubmatrix(int arr[][100] , int x1 ,int y1 , int x2 , int y2) {
    int res = 0 ;
    for (int i = x1 ; i <= x2 ;i++) {
        for (int j = y1 ; j <=y2;j++ ) {
            res+= arr[i][j];
        }
    }
    return res;
}
int main () {
    int arr[100][100];
    int m , n ;
    cin >> m >> n;


    for (int i= 0 ; i < m ; i++) {
        for (int j = 0 ; j < n ;j++) {
            cin >> arr[i][j];
        }
    }

    int X1=0,X2=m-1,Y1=0,Y2=n-1;
    for (int x1 = 0 ; x1 < m ; x1++) {
        for (int y1 = 0 ; y1<n;y1++) {
            for (int x2 = x1 ; x2 < m ; x2++) {
                for (int y2 = y1 ; y2 < n ;y2++) {
                    if (sumsubmatrix(arr,x1,y1,x2,y2) > sumsubmatrix(arr,X1,Y1,X2,Y2)) {
                        X1=x1;
                        Y1=y1;
                        X2=x2;
                        Y2=y2;
                    }
                }
            }
        }
    }

     for (int i = X1 ; i <= X2 ;i++) {
        for (int j = Y1 ; j <=Y2;j++ ) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    







    return 0;
}