#include <iostream>
#include <cstring>
using namespace std;
const int maxvalue = 1e6 + 1;
const int maxN = 1e5 + 1;
int main () {
    int freq[maxvalue];
    int arr[maxN];
    for (int i = 0  ; i < maxvalue ;i++) {
        freq[i]=0;
    }
    int n ; cin >> n;
    for (int i = 0  ; i<n;i++) {
        cin >> arr[i];
    }
    for (int i = 0 ;i<n;i++) {
        freq[arr[i]]++;
    }
    int ans1=0;
    for (int i =0 ;i<maxvalue;i++) {
        if (freq[i] > 0) {
            ans1++;
        }
    }
    cout << ans1 << endl;
    int ans2=0;
    for (int i = 0 ;i<maxvalue;i++) {
        if (ans2 < freq[i]) {
            ans2=freq[i];
        }
    }
    for (int i = 0 ;i<maxvalue;i++) {
        if (ans2 == freq[i]) {
            cout << i <<" ";
        }
    }
    cout << endl;
    cout << ans2 << endl;


}