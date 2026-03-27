//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 2 3 3 
//         1 2 5
//         0 -1 1
//         4 0 1
//         0 1 -1
//         1 2 -2
// Output : 
//          9 12 -11
//          1 1 -1


// test Case 2 
// Input :  2 2 2 
            // 1 1  
            // 2 3
            // 5 6
            // 7 8
// OutPut : 
            // 12 14
            // 31 36
// Test Case 3 
// Input :  3 2 2
            // 4 9  
            // 9 2
            // 3 4
            // 3 1 5
            // 4 1 6 
// Output :
            // 48 13 74 
            // 35 11 57 
            // 25 7 39 

#include<iostream>
using namespace std;
int main() {
    int n , m,p;
    cin >> n >> m >> p;
    int arr_1[100][100];
    int arr_2[100][100];
    int arr_3[100][100]={0};
    for (int i = 0;i<n;i++) {
        for(int j = 0 ;j<m;j++) {
            cin >> arr_1[i][j];
        }
    }
    for (int i = 0;i<m;i++) {
        for(int j = 0 ;j<p;j++) {
            cin >> arr_2[i][j];
        }
    }

    for (int i = 0 ;i<n;i++) {
        for(int j=0;j<p;j++){
            for (int k = 0 ;k<m;k++){
                 arr_3[i][j]+=arr_1[i][k]*arr_2[k][j];
            }
        }
    }
    for (int i = 0 ;i<n;i++) {
        for(int j=0;j<p;j++){ 
            cout << arr_3[i][j]<<" ";
        }
        cout << endl;
    }


    return 0;
}
