//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 5 
//         10 13 19 20 91
// Output :19 20 21


// test Case 2 
// Input : 8
//         1 2 4 5 7 8 9 11
// OutPut : 1 2 
//          4 5 
//          7 8 9 

// Test Case 3 
// Input : 8
//         1 2 1 2 3 4 5 6
// Output : 1 2 
//          1 2 3 4 5 6

#include<iostream>
using namespace std;
int main() {
    bool check(int arr[] ,int i ,int n );
    int n; 
    cin >> n ;
    int arr[1000];
    for (int i = 0 ;i<n;i++) {
        cin >> arr[i];
    }
    //7 3 4 5 12 67 45 46 47 678 
    for (int i = 0;i<n;i++) {
        if (check(arr,i,n)) {
            cout << arr[i] <<" ";
        }
        if (check(arr,i,n)==true && check(arr,i+1,n)==false) {
            cout << endl;
        }
        if (check(arr,i,n) && check(arr,i+1,n) && arr[i+1]-arr[i] != 1) {
            cout << endl;
        }
    }
    return 0;
}
bool check(int arr[] ,int i ,int n ) {
    if (i > 0 || i < n) {
        if (arr[i+1]-arr[i]==1 || arr[i]-arr[i-1]==1) {
            return true;
        }
    }
    if (i==0) {
        if (arr[i-1]-arr[i]==1) {
            return true;
        } 
    }
    if (i==n-1) {
        if (arr[i]-arr[i-1]==1) {
            return true;
        }
    }
    return false;
}
