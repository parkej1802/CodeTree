#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, m;
vector<vector<int>> matrix;
vector<vector<int>> dp;

int maxIncreasingSeq() {
    dp[0][0] = 1;
    int result = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (row == 0 && col == 0) continue;

            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {

                    if (matrix[row][col] > matrix[i][j]) {
                        dp[row][col] = max(dp[row][col], dp[i][j] + 1);
                        result = max(result, dp[row][col]);
                    }
                }
            }
        }
    }
    return result;
}

int main() {
    
    cin >> n >> m;

    matrix.resize(n, vector<int>(n));
    dp.resize(n, vector<int>(n, 1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int result = maxIncreasingSeq();

    cout << result;

    return 0;
}