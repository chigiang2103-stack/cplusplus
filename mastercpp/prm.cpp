#include <iostream>
#include <cmath>
using namespace std;

// TODO: Viết hàm kiểm tra số nguyên tố
bool isPrime(int x) {
    if (x<2) return false;
    if (x==2) return true;
    if (x%2==0) return false;
    int l = sqrt(x);
    for (int i = 3 ; i<=l;i=i+2) {
        if (x%i==0) {
            return false;
        }
    }
    return true;
}

// TODO: Đếm số phần tử âm trong mảng
int countNegative(int a[], int n) {
    int count = 0;
    for (int i = 0 ; i < n ;i++) {
        if (a[i]<0) {
            count++;
        }
    }
    return count;
}

// TODO: Đếm số phần tử nguyên tố trong mảng
int countPrime(int a[], int n) {
    int count = 0;
    for (int i = 0 ;i<n;i++) {
        if(isPrime(a[i])) {
            count++;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int a[1005];
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << "Negative numbers: " << countNegative(a, n) << "." << endl;
    cout << "Prime numbers: " << countPrime(a, n) << "." << endl;

    return 0;
}
