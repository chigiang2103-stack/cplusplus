#include <bits/stdc++.h>
using namespace std;
vector<int>nums;
vector<int>cur;
vector<vector<int>>ans;
int sum (vector<int> s ) {
    int tong=0;
    for (int i = 0 ; i < s.size();i++) tong+=s[i];
    return tong;
}
void gen(int step , int target) {

    ans.push_back(cur);

    for (int i = step ; i < nums.size();i++) {
        if (i > step && nums[i] == nums[i-1]) {
            continue;
        }
        cur.push_back(nums[i]);
        gen(i+1 , target);
        cur.pop_back();
    }
}

int main() {
    int n , target;
    cin >> n >> target;

    nums.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin() , nums.end());
    gen(0,target);
    cout << ans.size() << endl;

    for (auto v : ans) {
        for (auto k : v) {
            cout << k << " ";
        }
        cout << endl;
    }
    

    return 0;
}