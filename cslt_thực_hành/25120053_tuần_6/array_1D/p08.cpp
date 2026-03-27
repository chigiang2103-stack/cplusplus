//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 5 2 2
//         10 13 19 20 91
// Output :10 13 91 


// test Case 2 
// Input : 8 2 5
//         9 10 11 23 14 59 24 1
// OutPut : 9 10 1 

// Test Case 3 
// Input : 10 4 4
//         12 14 17 19 21 49 42 39 50 32
// Output :12 14 17 19 50 32

#include<iostream>
using namespace std;
int main() {
    int n,index,k; 
    cin >> n >> index >> k;
    int arr[1000];
    for (int i = 0 ;i<n;i++) {
        cin >> arr[i];
    }
    if (index < 0 || index > n-1 || k< 0) {
        return 0;
    }
    int tmp=index+k-1;
    if (tmp>=n) {
        tmp=n-1;
    }

    for (int i = tmp+1;i<n;i++ ) {
        arr[i-k]=arr[i];
    }
    n=n-tmp+index - 1;

    for (int i = 0 ;i<n;i++) {
        cout<< arr[i] << " ";
    }   
    cout << endl;
    return 0;
}
