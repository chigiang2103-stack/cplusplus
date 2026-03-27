//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 3 3 
//         1 2 3 
//         2 5 6
//         3 6 9
// Output : true


// test Case 2 
// Input :  3 3 
//          1 2 3
//          4 5 6
//          7 8 9
// OutPut : false


// Test Case 3 
// Input : 4 4 
        // 4 4 4 4 
        // 5 5 5 5
        // 6 6 6 6
        // 7 7 7 7
// Output :false

#include<iostream>
using namespace std;
int main() {
    int n , m;
    cin >> n >> m;
    int arr[1000][1000];
    for (int i = 0;i<n;i++) {
        for(int j = 0 ;j<m;j++) {
            cin >> arr[i][j];
        }
    }
    bool flag=true;
    for (int i = 0 ;i<n;i++) {
        for(int j=0;j<m;j++){
            if (arr[i][j]!=arr[j][i]) {
                flag=false;
                break;
            }
        }
    }
    if (!flag) {
        cout << "false" << endl;
    }
    else {
        cout << "true" << endl;
    }


    return 0;
}
