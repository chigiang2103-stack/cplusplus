#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 1e5+1;

vector<vector<int>> adj(maxn);
vector<int> vis(maxn,0);

void bfs(int x, int id) {
    vis[x]=id;
    queue<int>q;
    q.push(x);
    while (q.size()) {
        int s = q.front();
        q.pop();
        for (int v : adj[s]) {
            if (!vis[v]) {
                vis[v]=id;
                q.push(v);
            }
        }
    }
    
}
int main ()  {

    int n , m,q; cin >> n>> m>>q;

    while (m--) {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }     
    int id = 1;  
    for (int i = 1 ; i <=n;i++) {
       if (!vis[i]) {
        bfs(i,id);
        id++;
    }
    }
    while (q--){
        int x , y; cin >> x >> y;
        if (vis[x]==vis[y]) cout << "YES\n";
        else cout << "NO\n";
    }



    return 0;
}