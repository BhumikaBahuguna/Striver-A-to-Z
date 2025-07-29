#include <iostream>
using namespace std;

bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
    for (int k = 0; k < n; k++) {
        if (k != node && graph[k][node] == 1 && color[k] == col) {
            return false;
        }
    }
    return true;
}

bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
    if (node == N) {
        return true;
    }

    for (int i = 1; i <= m; i++) {
        if (isSafe(node, color, graph, N, i)) {
            color[node] = i;
            if (solve(node + 1, color, m, N, graph)) return true;
            color[node] = 0; // backtrack
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int N) {
    int color[101] = {0};
    return solve(0, color, m, N, graph);
}

int main() {
    int N, E, m;
    cout << "Enter number of vertices (N): ";
    cin >> N;
    cout << "Enter number of edges (E): ";
    cin >> E;

    bool graph[101][101] = {false};

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = true;
        graph[v][u] = true; // undirected graph
    }

    cout << "Enter the number of colors (M): ";
    cin >> m;

    if (graphColoring(graph, m, N)) {
        cout << "YES, the graph can be colored using " << m << " colors.\n";
    } else {
        cout << "NO, the graph cannot be colored using " << m << " colors.\n";
    }

    return 0;
}
