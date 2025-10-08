#include <iostream>
using namespace std;
using ll = long long;
#include<vector>
bool isPrime(ll n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    ll limit = sqrt(n);
    for (ll i = 3; i <= limit; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    for (ll x : a) {
        ll candidate = x;
        while (!isPrime(candidate)) candidate++;
        cout << candidate << "\n";
    }
}
