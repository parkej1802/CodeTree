#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<vector<int>> matrix;
int dp[101][101];

int dir[2][2] = {{0, 1}, {1, 0}};

bool inRange(int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < n;
}

void setDP() {
    dp[0][0] = matrix[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;

            int maxNum = INT_MIN;

            for (auto d : dir) {
                int ny = i - d[0];
                int nx = j - d[1];
                if (inRange(ny, nx)) {
                    maxNum = max(maxNum, min(dp[ny][nx], matrix[i][j]));
                }
            }
            dp[i][j] = maxNum;
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

    setDP();

    cout << dp[n - 1][n - 1];

    return 0;
}
