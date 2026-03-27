#include <iostream>
#include <cstring>
using namespace std;

// TODO: Kiểm tra mảng tăng dần
bool isAscending(int a[], int n) {
    for (int i = 0 ; i < n-1;i++) {
        for (int j = i +1 ; j < n ;j++) {
            if (a[j]<a[i]) {
                return false;
            }
        }
    }
    return true;
}

// TODO: Kiểm tra mảng đối xứng
bool isSymmetric(int a[], int n) {
    int j = n-1;
    for (int i = 0 ;i<j;i++) {
        if (a[i] != a[j]) {
            return false;
        }
        j--;
    }
    return true;
}

// TODO: Kiểm tra cấp số cộng
bool isArithmeticProgression(int a[], int n) {
    int temp = a[1]-a[0];
    for (int i = 1 ; i < n-1 ;i++) {
        if (a[i+1] - a[i]!=temp) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int a[1005];
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << "Array " << (isAscending(a, n) ? "is" : "is not") << " ascending." << endl;
    cout << "Array " << (isSymmetric(a, n) ? "is" : "is not") << " symmetric." << endl;
    cout << "Array " << (isArithmeticProgression(a, n) ? "is" : "is not") << " an arithmetic progression." << endl;

    return 0;
}
