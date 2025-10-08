#include<iostream> 
using namespace std;
#define ll long long 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ; 
    cin >> n;
    ll arr[n];
    ll fibonaci(ll n);
    for (int i = 0;i<n;i++) {
        cin >> arr[i];
    }
    for (int i = 0 ; i<n;i++) {
        cout << fibonaci(arr[i])%10 << endl;
    }
    return 0;

}
ll fibonaci(ll n ){
    if (n==1 || n ==2 ) return n;
    return fibonaci(n-1) + fibonaci(n-2);
}


