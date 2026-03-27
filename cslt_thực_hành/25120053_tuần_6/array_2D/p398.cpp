//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 3 3 
//         1 2 3
//         4 5 6
//         7 8 9 
// Output : 4 1 2
//          7 5 3
//          8 9 6

// test Case 2 
// Input :  4 3
//          1 2 3
//          6 5 4
//          7 6 5
//          8 7 6
// OutPut : 6 1 2
//          7 5 3
//          8 6 4
//          7 6 5

// Test Case 3 
// Input : 5  5
        // 9 8 7 6 5
        // 8 7 6 5 4
        // 7 6 5 4 3
        // 6 5 4 3 2
        // 5 4 3 2 1
// Output :
        // 8 9 8 7 6 
        // 7 7 6 5 5 
        // 6 6 5 4 4 
        // 5 5 4 3 3 
        // 4 3 2 1 2 


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
    int temp1;
    int temp2;
    int temp3;
    int temp4;
    int bottom =n , top=0 ,  right=m ,left=0;
    for (int i = top ;i<bottom-1 ;i++) {
        temp1= arr[i][left];
        arr[i][left]=arr[i+1][left];
        arr[i+1][left]=temp1;
    }
    for (int i =left+1;i<right;i++) {
        temp2=arr[bottom-1][i];
        arr[bottom-1][i]=arr[bottom-1][i-1];
        arr[bottom-1][i-1]=temp2;
    }
    for (int i = bottom-1;i>top;i--) {
        temp3=arr[i-1][right-1];
        arr[i-1][right-1]=arr[i][right-1];
        arr[i][right-1]=temp3;
    }
    for (int i =right-1;i>left+1;i--) {
        temp4=arr[top][i-1];
        arr[top][i-1]=arr[top][i];
        arr[top][i]=temp4;
    }
    cout << endl;
    for (int i = 0 ;i<n;i++) {
        for (int j=0;j<m;j++)  {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

