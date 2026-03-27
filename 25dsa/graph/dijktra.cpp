#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define ll long long
const ll maxN = 1e5 +5;
int n , m , s;
const ll inf = 1e18;
ll dist[maxN];
int trace[maxN];

vector<vector<pair<int , ll >>> adj(maxN);
struct Element {
    int vertice;
    ll dist ;
    bool operator < (const Element &other) const {
        return dist > other.dist;
    }
};
void dijktra() {
    for (int i = 1 ; i <= n ; i++) {
        dist[i]=inf;
        trace[i]=-1;
     
    }
    dist[s]=0;
    priority_queue<Element>pq;
    pq.push({s,0});
    while (pq.size()) {
        int u = pq.top().vertice;
        int d = pq.top().dist;
        pq.pop();
        if (d > dist[u]) continue;
   
        for (auto it : adj[u]) {
            int v = it.first;
            ll w = it.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                trace[v] = u;
                pq.push({v , dist[v]});
            }
        }

    }

}
vector<int> getpath(int t) {
    vector<int> ans;
    while (t!=-1) {
        ans.push_back(t);
        t=trace[t];
    }
    reverse(ans.begin() , ans.end());
    return ans;
}


int main () {

    cin >> n >> m >> s;
    while (m--) {
        int u , v ;
        cin >> u >> v;
        ll w;
        cin >> w;
        adj[u].push_back({v,w});
    }
    dijktra();
    int q ; cin >> q;
    while (q--) {
        int d ; cin >> d;
        if (dist[d] == inf) cout << -1;
        else {
            cout << dist[d] << endl;
            vector<int> path = getpath(d);
            cout << path.size() << " " ;
            for (auto v : path) cout << v << " ";
            
        }
        cout << endl;
    }
    // n đỉnh đều push vào queue và đều truy xuất đến nó mỗi lần truy xuất 
    // tốn logn => tổng nlogn
    // time O(m + nlogn)


    return 0;
}