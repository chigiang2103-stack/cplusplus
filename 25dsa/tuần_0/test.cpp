#include <iostream>
#include <vector>
#define ll long long

using namespace std;
long long MOD=1e9 + 7;
vector<vector<ll>>subMat(vector<vector<ll>> mat , int r ,int c) {
    int n = mat.size();
    vector<vector<ll>>ans;
    for (int i = 0 ; i < n;i++) {
        vector<ll>row;
        if (i==r) continue;
        for (int j = 0 ; j < n ; j++) {
            if (j==c) continue;
            row.push_back(mat[i][j]);
        }
        ans.push_back(row);
    }
    return ans;
}

ll Pow(int exp) {
    if (exp%2==1) return -1;
    return 1;
}

ll det(vector<vector<ll>> mat ) {
    int n = mat.size();
    if (n==1) return mat[0][0];

    ll ans = 0;
    for (int j =1;j<=n;j++) {
        ans= ((ans+MOD)%MOD+ Pow(1+j)*(mat[0][j-1]%MOD)*(det(subMat(mat,0,j-1))+MOD)%MOD)%MOD;
    }
    return ans;

}



int main() {
    int n; cin >> n;
    vector<vector<ll>>mat(n,vector<ll>(n));
    for (int i = 0 ; i < n ; i++ ) {
        for (int j=0;j<n;j++ ) {
            cin >> mat[i][j];
        }
    }

    cout << (det(mat) + MOD)%MOD << endl;





}