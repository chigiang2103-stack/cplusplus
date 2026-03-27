    #include<iostream>
    #include<vector>
    #include<queue>
    using namespace std;
    const int maxn = 2e5+1;

    vector<vector<int>> adj(maxn);
    vector<int> vis(maxn,0);
    bool ans = true;
    // 0 là chưa tô 
    // 1 là tô màu loại 1 
    // 2 là tô màu loại 2

    void dfs(int u , int cur) {
        vis[u]=cur;
        for (int v : adj[u]) {
            if (vis[v] ==0 ) dfs(v , 3 -cur);
            else if (vis[v] == vis[u]) {
                ans = false;
                break;
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
        for (int i = 1;i<=n;i++) {
            if (!vis[i]) dfs(i,1);
        }
        if (ans) cout << "YES\n";
        else cout << "NO\n";

        





        return 0;
    }