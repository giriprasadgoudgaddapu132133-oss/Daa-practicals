
#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<int> adj[], vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int i : adj[node]) {
        if (!visited[i]) {
            DFS(i, adj, visited);
        }
    }
}

int main() {
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<int> adj[n];

    cout << "Enter edges:\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);

    cout << "DFS Traversal: ";
    DFS(0, adj, visited);

    return 0;
}
