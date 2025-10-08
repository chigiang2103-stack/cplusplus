#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main () {
    ll luythua (ll a , ll b);
   float x;
   cout <<"x : " ; cin >> x;
    int n ; 
   cout <<"n : "; cin >>n;
   float sum(float x , int n);
   float s;
   s=sum(x,n);
   cout << s << endl;
    return 0;
}
ll luythua (ll a , ll b) {
    if (b==0) return 1;
    ll temp = luythua(a,b/2);
    ll res = temp*temp;
    if (b%2==1) res = res*a;
    return res;
}
float sum(float x , int n) {
    ll luythua (ll a , ll b);
    float s = 0.0;
    for (int i =1 ; i <= n; i++) {
        s+= luythua(-1,i+1)*luythua(x,i);
    }
    return s;
}
