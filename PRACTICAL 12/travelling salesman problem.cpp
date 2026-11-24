
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 999999

int n, cost[10][10];
int dp[1 << 10][10];

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        return cost[pos][0];
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;

    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newCost = cost[pos][city] +
                          tsp(mask | (1 << city), city);

            ans = min(ans, newCost);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    cout << "Minimum travelling cost: "
         << tsp(1, 0) << endl;

    return 0;
}
