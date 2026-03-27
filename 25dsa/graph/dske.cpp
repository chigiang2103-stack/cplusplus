#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int dest;
    int weight;

    Edge(int d, int w = 1) : dest(d), weight(w) {}
};

class Graph {
private:
    int V; // Số lượng đỉnh
    std::vector<std::vector<Edge>> adjList;

public:
    // TODO: Triển khai constructor để khởi tạo đồ thị với V đỉnh
    Graph(int vertices) {
       V= vertices;
       adjList = vector<vector<Edge>>(V);
    }

    // TODO: Triển khai hàm thêm cạnh có hướng từ src tới dest với trọng số weight
    void addEdge(int src, int dest, int weight = 1) {
       for (auto &k : adjList[src]) if (k.dest==dest){
        k.weight=weight;
        return ;
       } 

       adjList[src].push_back({dest, weight});

    }

    // TODO: Triển khai hàm kiểm tra xem có cạnh từ src tới dest không
    bool isEdge(int src, int dest) {
          for (auto k : adjList[src]) if (k.dest==dest) return true;
          return false;
    }

    // TODO: Triển khai hàm lấy trọng số cạnh từ src tới dest
    int getWeight(int src, int dest) {
        for (auto k : adjList[src]) if (k.dest==dest) return k.weight;
        return 0;
    }

    // TODO: Triển khai hàm in danh sách kề
    void printGraph() {
        for (int i=0;i<V;i++) {
            cout << i << ": ";
            for (auto k : adjList[i]) {
                cout << "(" << k.dest <<", "<<k.weight<<") ";
            }
            cout << endl;
        }
        // Định dạng: i: (dest1, w1) (dest2, w2)
        // Lưu ý khoảng trắng sau dấu hai chấm và giữa các cặp cạnh
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int V, Q;
    if (!(std::cin >> V >> Q)) return 0;

    Graph g(V);

    while (Q--) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int u, v, w;
            std::cin >> u >> v >> w;
            g.addEdge(u, v, w);
        } else if (type == 2) {
            int u, v;
            std::cin >> u >> v;
            std::cout << (g.isEdge(u, v) ? "true" : "false") << "\n";
        } else if (type == 3) {
            int u, v;
            std::cin >> u >> v;
            std::cout << g.getWeight(u, v) << "\n";
        } else if (type == 4) {
            g.printGraph();
        }
    }
    return 0;
}