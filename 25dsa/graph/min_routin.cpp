#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 2e5+1;

vector<vector<int>> adj(maxn);
vector<int> dis(maxn,-1);
vector<int> pre(maxn,-1);

void bfs(int s) {
    queue<int>q;
    q.push(s);
    dis[s]=0;
    while (q.size()) {
        int u= q.front(); q.pop();
        for (int v : adj[u]) {
            if (dis[v]==-1) {
                dis[v]=dis[u]+1;
                pre[v]=u;
                q.push(v);
            }
        }
    }
}
int main ()  {

    int n , m; cin >> n>> m;

    while (m--) {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }       
    int s, t;cin >> s >> t;
    bfs(s);
    if (dis[t]==-1) {
        cout << -1 << endl;
    }
    else {
        cout << dis[t] << endl;
        vector<int>ans;
        while (t!=-1) {
            ans.push_back(t);
            t=pre[t];
        }
        for (int i = ans.size()-1;i>=0;i--) {
            cout << ans[i] << " ";
        }
    }


    





    return 0;
}