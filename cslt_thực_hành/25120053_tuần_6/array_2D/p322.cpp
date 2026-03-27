//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 2 2 
//         2.0 5.7
//         8.7 3.5
// Output : 7.7
//          12.2

// test Case 2 
// Input :  3 3 
//          1 9 2.3
//          3 1 3.2
//          3 9 4.2
// OutPut : 
//         12.3
//         7.2
//         16.2

// Test Case 3 
// Input : 2 3
//         2 1 3.5
//         10 10 1
// Output :6.5
//         21.0

#include<iostream>
using namespace std;
int main() {
    int n , m;
    cin >> n >> m;
    double arr[1000][1000];
    for (int i = 0;i<n;i++) {
        for(int j = 0 ;j<m;j++) {
            cin >> arr[i][j];
        }
    }
    double sum=0;
    for (int i = 0;i<n;i++) {
        for(int j = 0 ;j<m;j++) {
            sum+=arr[i][j];
        }
        printf("%.1f\n",sum*1.0);
        sum=0;
    }
    return 0;
}
