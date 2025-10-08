#include <iostream>
using namespace std;
#include<vector>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<long long > > a(m+1, vector<long long>(n+1, 0));
    vector<vector<long long > > sum(m+1, vector<long long>(n+1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            sum[i][j] = a[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }

    long long ans = 0;
    for (int i = 1; i <= m-k+1; i++) {
        for (int j = 1; j <= n-k+1; j++) {
            int x2 = i + k - 1;
            int y2 = j + k - 1;
            long long S = sum[x2][y2] - sum[i-1][y2] - sum[x2][j-1] + sum[i-1][j-1];
            ans = max(ans, S);
        }
    }
    cout << ans << "\n";
    return 0;
}
