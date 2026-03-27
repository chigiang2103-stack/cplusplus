#include<iostream>
#include<vector>
#define ll long long

using namespace std;
ll dist[105][105];

int main () {
    int n ; cin >> n;
    for (int i = 1 ; i <= n;i++) {
        for (int j=1;j<=n;j++) {
            cin >> dist[i][j];
        }
    }
    for (int k = 1;k<=n;k++) {
        for (int i = 1 ; i <= n;i++) {
            for (int j = 1 ; j<= n;j++) {
                dist[i][j] = min ( dist[i][j] ,dist[i][k] + dist[k][j]);
            }
        }
    }
      for (int i = 1 ; i <= n;i++) {
        for (int j=1;j<=n;j++) {
            cout << dist[i][j]<<" ";
        }
        cout << endl;
    }




    return 0;
}



