//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 3 3 
//         1 0 9
//         2 1 3
//         3 5 1
// Output : 0

// test Case 2 
// Input :  3 3 
//          9 8 7
//          6 7 8
//          5 6 7
// OutPut : 1

// Test Case 3 
// Input : 3 3
//         2 1 3
//         10 10 1
//         3 5 2
// Output :0


#include<iostream>
using namespace std;

bool check (int arr[][1000],int n ,int yn ,int index) {
    int temp = arr[0][index];
    for (int i = 1 ;i<n;i++) { 
        if (temp > arr[i][index]) {
            temp=arr[i][index];
        }
    }
    if (temp==yn) {
        return true;
    }
    return false;
}


int main() {
    int n , m;
    cin >> n >> m;
    int arr[1000][1000];
    for (int i = 0;i<n;i++) {
        for(int j = 0 ;j<m;j++) {
            cin >> arr[i][j];
        }
    }
    int count = 0;
    int yn;
    int index=0;
    for (int i = 0;i<n;i++) {
        yn = arr[i][0];
        for(int j = 1 ;j<m;j++) {
            if (yn < arr[i][j]) {
                yn = arr[i][j];
                index=j;
            }
        }
        if (check(arr,n,yn,index)){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}

