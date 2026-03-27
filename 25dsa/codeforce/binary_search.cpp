#include <iostream>
#include <vector>

using namespace std;
vector<int>ans(100005);
void quickSort(vector<int>& a, int low, int high) {
    if (low >= high) return ;
    int pivot = a[(low + high)/2];
    int k = low;
    for (int i = low ; i <=high ;i++) {
        if (a[i] < pivot) ans[k++] = a[i];
    }
    int pivot_1 = k -1;
    for (int i = low ; i <=high ;i++) {
        if (a[i] == pivot) ans[k++] = a[i];
    }
    int pivot_2 = k;
    for (int i = low ; i <=high ;i++) {
        if (a[i] > pivot) ans[k++] = a[i];
    }
    for (int i = low ; i <=high ;i++) {
        a[i] = ans[i];
    }
    quickSort(a,low,pivot_1);
    quickSort(a,pivot_2,high);

}

int binarySearchNearest(const vector<int>& a, int n, int x) {
    int l = 0 ; 
    int r = n-1;
    int ans ;
    while (l <= r ) {
        int mid = (l+r)/2;
        if (x < a[mid]) {
            r = mid-1;
        }
        else l = mid +1;
    }
    if (abs(a[r]-x) < abs(a[l]-x)) return a[r];
    else return a[l];
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