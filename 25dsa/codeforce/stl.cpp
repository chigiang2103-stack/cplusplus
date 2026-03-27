#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quickSort(vector<int>& a, int low, int high) {
   sort(a.begin(),a.end());
}

int binarySearchNearest(const vector<int>& a, int n, int x) {
    auto it = lower_bound(a.begin(),a.end(),x);
    if (it == a.begin()) return a[0];
    else if (it == a.end()) return a[n-1];
    else {
        int val = *it;
        int vall = *(it-1);
        if (abs(vall-x) < abs(val-x)) return vall;
        else return val;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    if (n <= 0) return 0;

    vector<int> vals(n);
    for (int i = 0; i < n; ++i) {
        cin >> vals[i];
    }

    quickSort(vals, 0, n - 1);

    while (q--) {
        int x;
        cin >> x;
        int nearest = binarySearchNearest(vals, n, x);
        cout << nearest << endl;
    }

    return 0;
}