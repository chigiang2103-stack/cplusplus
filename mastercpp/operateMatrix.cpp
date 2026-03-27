#include <iostream>
using namespace std;
void my_function(int A[100][100], int M, int N, int R)

{
    for (int i = R-1  ;i<M-1;i++) {
        for (int j =0 ;j<N;j++) {
            A[i][j] =A[i+1][j];
        }
    }
}



int main () {
    int A[100][100], M, N;
    cin >> M >> N;
    for (int i = 0 ;i<M;i++) {
        for (int j = 0 ;j<N;j++) {
            cin >> A[i][j];
        }
    }
    
    return 0;
}