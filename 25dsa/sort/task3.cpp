#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TODO: Cài đặt Counting Sort
void countingSort(vector<int>& a) {
    vector<int>cnt(100001,0);
    for (int v : a) {
        cnt[v]++;
    }
    vector<int>b;
    for (int i = 0 ; i <= 1e5;i++) {
        for (int j = 1 ; j <= cnt[i] ; j++) {
            b.push_back(i);
        }
    }
    a=b;
}



// TODO: Cài đặt Radix Sort
void radixSort(vector<int>& a) {
    int n = a.size();
    vector<int>ans(n);
    for (int exp = 1; exp<=1e5;exp*=10) {
        int index = 0;
        for (int digit = 0 ; digit<=9 ; digit++) {
            for (int v : a) {
                if ((v/exp)%10==digit) ans[index++]=v;
            }
        }
        a=ans; 
    }
 
}

void printArray(const vector<int>& a) {
    for (int i = 0; i < (int)a.size(); i++) {
        cout << a[i] << (i == (int)a.size() - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> original(n);
    for (int i = 0; i < n; i++) cin >> original[i];
    vector<int> a;

    // Test Counting Sort
    a = original;
    if (n > 0) countingSort(a);

    printArray(a);

    // Test Radix Sort
    a = original;
    if (n > 0) radixSort(a);
    printArray(a);

    return 0;
}
