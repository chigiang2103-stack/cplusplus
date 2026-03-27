#include <iostream>
using namespace std;
int sumSubmatrix(int Matrix[1005][1005] , int x1 ,int x2 , int y1 , int y2 ) {
    int sum =0 ;
    for (int i = x1 ; i<=x2;i++) {
        for (int j =y1;j<=y2;j++) {
            sum+= Matrix[i][j];
        }
    }
    return sum;
}
int main() {
    int n , m,p,q ;
    int Matrix[1005][1005];
    cin >>  n >> m >> p >> q;
    for (int i =0 ; i<n;i++) {
        for (int j =0;j<m;j++) {
            cin >> Matrix[i][j];
        }
    }
    // 4 5 2 3
    // 1 2 3 4 5
    // 5 6 7 8 9
    // 1 3 2 1 0
    // 9 9 9 1 1
    int X1= 0;
    int X2 = p-1;
    int Y1 = 0;
    int Y2 = q -1;
    for (int x1 = 0;x1<n;x1++) {
        for (int y1 = 0;y1 <m;y1++) {
            for (int x2 =x1;x2<n;x2++) {
                for (int y2=y1;y2<m;y2++) {
                    if (sumSubmatrix(Matrix , x1,x2,y1,y2) > sumSubmatrix(Matrix, X1 , X2,Y1,Y2) && x2 - x1 == p-1 && y2-y1==q-1) {
                        X1=x1;
                        X2=x2;
                        Y1=y1;
                        Y2=y2;
                    }
                }
            }
        }
    }
    for (int i = X1 ; i<=X2 ; i++) {
        for (int j = Y1 ; j<=Y2;j++) {
            cout << Matrix[i][j] << " ";
        }
        cout << endl;
    }



return 0;
}