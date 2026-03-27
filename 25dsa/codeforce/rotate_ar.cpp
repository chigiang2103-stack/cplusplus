#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 7 8 9 1 2 3 4 5 6 
// x = 8

int binarySearchNearest(const vector<int>& a, int n, int x) {
    int l = 0 ; 
    int r = n-1;
    while (l <= r) {
        int mid = (l+r)/2;
        if (a[mid]==x) return mid;
        
        if (a[l] <= a[mid]) {
            if (a[mid] > x && x >= a[l]) {
                r = mid -1;
            } else l = mid+1;
        }
        else {
            if (a[mid] < x && x <= a[r]) {
                l = mid +1;
            }else r = mid -1;

        }
    }
    return -1;
    
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
    while (q--) {
        int x;
        cin >> x;
        int nearest = binarySearchNearest(vals, n, x);
        cout << nearest << endl;
    }

    return 0;
}