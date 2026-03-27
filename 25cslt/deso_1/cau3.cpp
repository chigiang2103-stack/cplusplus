#include <iostream>
using namespace std;
int sumSubmatrix(int **a, int x1 ,int x2 , int y1 , int y2 ) {
    int sum =0 ;
    for (int i = x1 ; i<=x2;i++) {
        for (int j =y1;j<=y2;j++) {
            sum+= a[i][j];
        }
    }
    return sum;
}
int** maxPositiveSubmatrix(int **a, int m, int n, int &rows, int &cols) {
    int X1 = 0 , X2 =0 , Y1 =0 , Y2=0;
     for (int x1 = 0;x1<m;x1++) {
        for (int y1 = 0;y1 <n;y1++) {
            for (int x2 =x1;x2<m;x2++) {
                for (int y2=y1;y2<n;y2++) {
                    if (sumSubmatrix(a, x1,x2,y1,y2) >0 && (x2-x1 +1)*(y2-y1 +1 ) > (X2-X1+1)*(Y2-Y1+1)) { 
                        X1=x1;
                        X2=x2;
                        Y1=y1;
                        Y2=y2;
                    }
                }
            }
        }
    }
    rows = X2 -X1 +1;
    cols =Y2 -Y1 +1;
    int** submat = new int *[rows];
    for (int i = 0 ;i < rows ;i++) {
        submat[i] = new int [cols];
    }
    for (int i=0;i<rows ;i++) {
        for (int j = 0 ; j<cols ;j++) {
            submat[i][j] = a[i + X1][j + Y1];
        }
    }
    return submat;
    
}
int main() {
    int m , n , rows = 0, cols=0;
    cin >> m >> n;
    int **a = new int *[m];
    for (int i = 0 ;i<m;i++) {
        a[i]=new int [n];
    }
    for (int i = 0 ;i< m ;i++) {
        for (int j= 0;j<n;j++) {
            cin >> a[i][j];
        }
    }   
    int** submat = nullptr ;
    submat = maxPositiveSubmatrix(a , m ,n ,rows ,cols);
    cout << rows << " " << cols << endl;
    for (int i = 0 ; i< rows ; i++) {
        for (int j = 0 ; j< cols;j++) {
            cout << submat[i][j] << " ";
        }
        cout << endl;
    }


return 0;
}