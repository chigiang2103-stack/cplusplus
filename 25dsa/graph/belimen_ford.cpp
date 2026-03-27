#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define ll long long
const ll maxN = 1e5 +5;
int n , m , s;
const ll inf = 1e18;
ll dist1[maxN];
ll dist2[maxN];
struct edge {
    int src;
    int dist;
    ll w;
};

vector<edge>edges(maxN);
void belimen_ford(ll dist[]) {
    for (int i = 1 ; i <= n-1;i++) {
        for (auto e : edges) {
            if (dist[e.src]!= inf) {
                if (dist[e.src] + e.w < dist[e.dist]) {
                    dist[e.dist] = dist[e.src] + e.w;
                }
            }
        }
    }
}

int main () {
    cin >> n >> m >> s;
    for (int i = 1 ; i <=m ;i++) {
        cin >> edges[i].src >> edges[i].dist >> edges[i].w ;
    }
    for (int i = 0 ; i <= n-1 ;i++) {
        dist1[i] = inf;
    }
    dist1[s] = 0 ;

    belimen_ford(dist1);
    for (int i = 0 ; i <= n -1 ;i++) {
        dist2[i] = dist1[i];
    }
    belimen_ford(dist2);
    for (int i = 0 ; i <= n-1;i++) {
        if (dist1[i]!=dist2[i]) {
            cout << "-Infinity\n";
        } else if (dist1[i] == inf) {
            cout << "Impossible\n"; 
        } else {
            cout << dist1[i] << endl;
        }
    }
    // time O(m*n)


    return 0;
}