#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;

vector<vector<int>> matrix;
vector<vector<int>> dp;

bool inRange(int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < n;
}

void Initialize() {
    dp.assign(n, vector<int>(n, INT_MAX));

    dp[0][0] = matrix[0][0];

    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], matrix[i][0]);
    }

    for (int j = 1; j < n; j++) {
        dp[0][j] = max(dp[0][j - 1],  matrix[0][j]);
    }
}

int minSub(int lowerBound) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if  (matrix[i][j] < lowerBound) {
                matrix[i][j] = INT_MAX;
            }
        }
    }

    Initialize();

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
             dp[i][j] = max(min(dp[i - 1][j], dp[i][j - 1]), matrix[i][j]);
        }
    }
    
    return dp[n - 1][n - 1];
        
}

int main() {
    cin >> n;

    matrix.resize(n, vector<int>(n));
    dp.resize(n, vector<int>(n, INT_MAX));

    int result = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    for (int i = 0; i <= 100; i++) {
        int upperBound = minSub(i);

        if (upperBound == INT_MAX) continue;

        result = min(result, upperBound - i);
    }

    cout << result;

    return 0;
}