#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

// TODO: Viết hàm xoay trái ma trận 90 độ
void rotateLeft(int a[MAXN][MAXN], int m, int n, int res[MAXN][MAXN]) {
    for (int i = 0;i<m;i++) {
        for (int j = 0 ; j<n;j++) {
            res[n - 1 - j][i] = a[i][j];
        }
    }
}

// TODO: Viết hàm xoay phải ma trận 90 độ
void rotateRight(int a[MAXN][MAXN], int m, int n, int res[MAXN][MAXN]) {
    for (int i = 0;i<m;i++) {
        for (int j = 0 ; j<n;j++) {
            res[j][m - 1 - i] = a[i][j];
        }
    }
}

void printMatrix(int a[MAXN][MAXN], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

int main() {

    int m, n;
    cin >> m >> n;
    int a[MAXN][MAXN];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    cout <<"— Original matrix —" << endl;
    printMatrix(a, m, n);

    int left[MAXN][MAXN], right[MAXN][MAXN];

    cout <<"— Rotate LEFT 90 degrees —" << endl;
    rotateLeft(a, m, n, left);
    printMatrix(left, n, m);

    cout << "— Rotate RIGHT 90 degrees —" << endl;
    rotateRight(a, m, n, right);
    printMatrix(right, n, m);

    return 0;
}
