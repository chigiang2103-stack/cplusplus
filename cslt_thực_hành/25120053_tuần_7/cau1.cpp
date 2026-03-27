#include<iostream>
using namespace std;
void my_function(float A[100][100], int M, int N)
{
    for (int i=0;i<M;i++) {
        for (int j =0 ;j<N;j++) {
            A[i][j]=round(A[i][j]);
        }
    }
}
int main() 
{
    return 0;
}
