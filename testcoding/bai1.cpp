#include<iostream> 
#define ll long long 
using namespace std;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a , n , m;
    cin >> a >> n >> m;
    ll luythua(ll a , ll b);
    cout <<(ll)(luythua(a,n)%m)<<endl;
    return 0;
}
ll luythua (ll a , ll b) {
    if (b==0) return 1;
    ll temp = luythua(a,b/2);
    ll res = temp*temp;
    if (b%2==1) res = res*a;
    return res;
}
   