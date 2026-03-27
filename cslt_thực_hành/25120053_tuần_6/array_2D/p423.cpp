//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 3 3 
        // 1 2 3 
        // 4 5 6
        // 7 8 9
// Output : 
        // 1 2 3 
        // 8 9 4 
        // 7 6 5 

// test Case 2 
// Input :  3 4 
            // 1 3 2 5
            // 3 4 1 7
            // 8 7 5 2
// OutPut : 
            // 1 1 2 2 
            // 7 7 8 3 
            // 5 5 4 3 

// Test Case 3 
// Input :4 4
            // 1 2 3 4
            // 5 6 7 8
            // 9 10 11 12
            // 13 14 15 16
// Output :
            // 1 2 3 4 
            // 12 13 14 5 
            // 11 16 15 6 
            // 10 9 8 7 

#include<iostream>
using namespace std;
int main() {
    int n , m;
    cin >> n >> m;
    int  arr[1000][1000];
    int temp[100000];
    for (int i = 0;i<n;i++) {
        for(int j = 0 ;j<m;j++) {
            cin >> arr[i][j];
        }
    }
    int k=0;
    for (int i = 0;i<n;i++) {
        for(int j = 0 ;j<m;j++) {
            temp[k++]=arr[i][j];
        }
    }
    int tmp;
    for (int i = 0 ;i<k-1;i++) {
        for (int j = i+1;j<k;j++) {
            if (temp[i]>temp[j]) {
                tmp=temp[j];
                temp[j]=temp[i];
                temp[i]=tmp;
            }
        }
    }
    int t=0;
    int bottom = n,top=0,left=0,right=m;
    while(bottom-1 >= top && left <= right-1) {
        for (int i = left ; i<right;i++) {
            arr[top][i]=temp[t++];
        }
        top++;
        for (int i=top;i<bottom;i++) {
            arr[i][right-1]=temp[t++];
        }
        right--;
        if (bottom-1 >=top) {
            for (int i = right-1;i>=left;i--) {
            arr[bottom-1][i]=temp[t++];
        }
            bottom--;
        }
        if (right-1 >= left ) {
            for(int i = bottom-1;i>=top;i--) {
            arr[i][left]=temp[t++];
        }
            left++;
        }
    }
    for (int i = 0 ;i<n;i++) {
        for (int j=0;j<m;j++)  {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
