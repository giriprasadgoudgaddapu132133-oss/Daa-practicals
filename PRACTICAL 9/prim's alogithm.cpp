
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cost[10][10];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    int visited[10] = {0};
    visited[0] = 1;

    int edges = 0, total = 0;

    cout << "Minimum Spanning Tree:\n";

    while (edges < n - 1) {
        int min = 999;
        int a = -1, b = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] != 0 &&
                        cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (a == -1) {
            cout << "Spanning tree not possible";
            return 0;
        }

        cout << a << " - " << b << " : " << min << endl;

        visited[b] = 1;
        total += min;
        edges++;
    }

    cout << "Minimum Cost = " << total;

    return 0;
}
