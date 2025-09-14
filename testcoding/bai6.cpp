#include<iostream>
using namespace std;
#define mx 100
#include<vector>
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>arr1;
    int arr[mx][mx] ;
    int n,m,k;
    cout <<""; cin >> n >> m >>k;
    for (int i =0 ; i<n;i++) {
        for (int j = 0 ; j < m ; j++) {
            cout <<"";
            cin >> arr[i][j];
        }
    }
    int sum(int arr[mx][mx] , int right , int letf , int top ,int bottom );
    int t = 0;
    int temp=0,letf =0 ,right =k -1,top =0,bottom = k -1;
    int res = 0; 
    while (right < m ) {
        temp = sum(arr , right , letf , top , bottom );
        arr1.push_back(temp);
        t++;
        temp =0;
        while (bottom < n) {
            top++;
            bottom++;
            temp = sum(arr , right , letf , top , bottom );
            arr1.push_back(temp);
            t++;
        }
        letf++;
        right++;
        if (bottom == n) {
            top =0;
            bottom=k-1;
        }
    }
    for (int x : arr1) {
        res = max(res,x);
    }
    cout << res<<endl;
}
int sum( int arr[mx][mx] , int right , int letf , int top ,int bottom ) {
    int temp=0;
    for (int i = letf ; i<= right;i++) {
            for (int j = top ; j<= bottom ;j++ ) {
                temp+=arr[i][j];
            }
        }
    return temp;
}

