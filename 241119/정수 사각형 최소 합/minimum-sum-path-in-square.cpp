#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<vector<int>> matrix;

int dir[2][2] = {{1, 0}, {0, -1}};

int dp[101][101];

bool inRange(int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < n;
}

void minRectSum() {
    dp[0][n - 1] = matrix[0][n - 1];
    for (int i = 0; i < n; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            if (i == 0 && j == n - 1) continue;
            int minSum = INT_MAX;
            for (auto d : dir) {
                int ny = i - d[0];
                int nx = j - d[1];
                if (inRange(ny, nx)) {
                    minSum = min(minSum, dp[ny][nx]);
                    
                }
            }
            dp[i][j] = minSum + matrix[i][j];
        }
    }
}

int main() {
    cin >> n;

    matrix.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    minRectSum();

    cout << dp[n - 1][0];

    return 0;
}