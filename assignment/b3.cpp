#include<bits/stdc++.h>
using namespace std;
int main () {
    vector<int>a;
    int arr[9] = {1,8,6,2,5,4,8,3,7};
    // 7 x 7 = 49
    // value [r] > value [l] => value [l] x (r-l)
    int res = 0;
    for (int i = 0 ; i< 9-1 ; i++) {
        for (int j = i+1 ; j< 9;j++) {
            if (arr[j] > arr[i]) {
                res = arr[i]*(j-i) ;
                a.push_back(res);
            }
            else {
                res= arr[j]*(j-i);
                a.push_back(res);
            }
        }
    }
    int r=0;
    for (int x : a) {
        r= max(x,r);
    }
    cout << r << endl;
    return 0;
}