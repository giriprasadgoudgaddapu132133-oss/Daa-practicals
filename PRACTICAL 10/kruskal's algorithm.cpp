#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

int parent[1000];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    parent[find(x)] = find(y);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), compare);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int cost = 0, count = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    for (auto e : edges) {
        int a = find(e.u);
        int b = find(e.v);

        if (a != b) {
            cout << e.u << " - " << e.v
                 << " : " << e.w << "\n";

            unite(a, b);
            cost += e.w;
            count++;
        }

        if (count == n - 1)
            break;
    }

    if (count != n - 1)
        cout << "Spanning tree not possible\n";
    else
        cout << "Minimum Cost = " << cost << "\n";

    return 0;
}
