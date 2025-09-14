#include<iostream> 
using namespace std;
#define ll long long 
int main () {
    ll n ;
    cout <<""; cin >>n;
    ll find(ll n );
    ll res;
    for (int i = n - 100 ; i < n ; i++) {
        if (find(i)==n) {
            res = i;
            break;
        }
    }
    cout << res <<endl;
}
ll find(ll n ) {
    ll temp = n , res =temp;
    while (temp > 0) {
        res +=temp%10;
        temp = temp/10;
    }
    return res;
}