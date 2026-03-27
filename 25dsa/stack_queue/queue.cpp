#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int main () {
    int n; cin >> n;
    vector<long long> t(n);
    for (int i = 0 ; i < n ;i++) {
        cin >> t[i];
    }
    long long cnt =0;
    long long cur_time = 0;
    sort(t.begin(),t.end());

    for (int i = 0 ; i < n ; i++) {
        if (cur_time <= t[i]) {
            cur_time+=t[i];
            cnt++;
        }
    
    }
    cout << cnt <<"\n";






    return 0;
}