#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<vector<int>> matrix;
vector<bool> visited;
int minCost = INT_MAX;

void backTrack(int current, int count, int cost) {
    if (count == n) {
        if (matrix[current][0] > 0) {
            minCost = min(minCost, cost + matrix[current][0]);
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && matrix[current][i] > 0) {
            visited[i] = true;
            backTrack(i, count + 1, cost + matrix[current][i]);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n;

    matrix.resize(n, vector<int>(n));
    visited.resize(n, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    visited[0] = true;
    backTrack(0, 1, 0);

    cout << minCost;

    return 0;
}
