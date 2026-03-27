
#include <iostream>
#include <vector>

const long long mod = 1e9 + 7;
using namespace std;
long long fun[1005];
long long f(int n) {
    if (fun[n]!=0) return fun[n]; 
    if (n==0) return 1;
    long long ans =0;
    for (int i =0  ;i <=n-1;i++) {
        ans = (ans + f(i)*f(n-1-i)%mod)%mod;
    }
    fun[n]=ans;
    return ans;
}
int main () {
    int n; cin >> n;
    cout << f(n) << endl;





    return 0;
}