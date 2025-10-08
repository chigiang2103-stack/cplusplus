#include<bits/stdc++.h>
using namespace std;
int main () {
    int n ; cin >>n;
    int arr[n];
    for (int i =0 ; i<n;i++) {
        cin >> arr[i];
    }
    int l = 0,r =n-1;
    int s=0;
    while (l < r) {
        if (arr[l] < arr[r]) {
            s = arr[l]*(r-l);
            l++;
        }
        else {
            if (s<arr[r]*(r-l)) {
                s=arr[r]*(r-l);
            }
            r--;
        }
    }
    cout << s << endl;

    return 0;
}