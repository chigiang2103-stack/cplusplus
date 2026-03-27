//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 5 
//         10 13 19 20 91
// Output :20


// test Case 2 
// Input : 8
//         9 10 11 23 14 59 24 1
// OutPut : 24

// Test Case 3 
// Input : 10 
//         12 14 17 19 21 49 42 39 50 32
// Output :49

#include<iostream>
using namespace std;
int main() {
    int n; 
    cin >> n ;
    int arr[1000];
    for (int i = 0 ;i<n;i++) {
        cin >> arr[i];
    }
    int max_2 = arr[0];
    for (int i = 1 ;i<n;i++) {
        if (max_2 < arr[i]) {
            max_2=arr[i];
        }
    }
    int temp = max_2 - arr[0];
    int j=1;
    while (temp==0 && j < n) {
        temp=max_2-arr[j];
        j++;
    }
    for (int i = 1;i<n;i++) {
        if (temp > max_2-arr[i] && max_2-arr[i]!=0) { 
            temp=max_2-arr[i];
        }
    }
    cout << max_2-temp;
    cout << endl;
    return 0;
}
