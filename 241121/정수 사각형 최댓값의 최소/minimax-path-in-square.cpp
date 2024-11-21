#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<vector<int>> matrix;

int dir[2][2] = {{1, 0}, {0, 1}};

int dp[100][100];

bool inRange(int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < n;
}

int maxMinRect() {

    dp[0][0] = matrix[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int maxNum = INT_MAX;
            if (i == 0 && j == 0) continue;
            
            for (auto d : dir) {
                int ny = i - d[0];
                int nx = j - d[1];

                if (inRange(ny, nx)) {
                    maxNum = min(maxNum, max(dp[ny][nx], matrix[i][j]));
                }
            }
            dp[i][j] = maxNum;
        }
    }

    return dp[n - 1][n - 1];
}

int main() {
    cin >> n;

    matrix.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int result = maxMinRect();

    cout << result;

    return 0;
}