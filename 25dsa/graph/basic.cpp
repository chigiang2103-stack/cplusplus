#include <iostream>
#include <vector>
using namespace std;
struct Graph {
    int V; // Số lượng đỉnh
    std::vector<std::vector<int>> adjMatrix;

    // TODO: Triển khai constructor để khởi tạo đồ thị với V đỉnh
    Graph(int vertices) {
        V =vertices;
        adjMatrix = vector<vector<int>>(V,vector<int>(V,0));
    }

    // TODO: Triển khai hàm thêm cạnh có hướng từ src tới dest với trọng số weight
    void addEdge(int src, int dest, int weight = 1) {
        adjMatrix[src][dest] = weight;
    }

    // TODO: Triển khai hàm kiểm tra xem có cạnh từ src tới dest không
    bool isEdge(int src, int dest) {
        return adjMatrix[src][dest];
    }

    // TODO: Triển khai hàm lấy trọng số cạnh từ src tới dest
    int getWeight(int src, int dest) {
        return adjMatrix[src][dest];
    }

    // TODO: Triển khai hàm in ma trận kề
    void printGraph() {
        // In ma trận kề theo định dạng: các số trên cùng dòng cách nhau khoảng trắng
        // Mỗi dòng của ma trận là một dòng mới
        for (int i = 0 ; i < V;i++) {
            for (int j = 0 ; j < V; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Tối ưu nhập xuất cho bài tập lớn
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