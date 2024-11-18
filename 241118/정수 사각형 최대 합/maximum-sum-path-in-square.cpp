#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> matrix;

int dp[101][101];

int dir[2][2] = {{1, 0}, {0, 1}};

bool inRange(int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < n;
}

void maxRectSum() {
    
    dp[0][0] = matrix[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int maxNum = dp[i][j];
            for (auto d : dir) {
                int ny = i - d[0];
                int nx = j - d[1];
                if (inRange(ny, nx)) {
                    maxNum = max(maxNum, matrix[i][j] + dp[ny][nx]);
            
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
    
    int result = 0;

    maxRectSum();

    for (int i = 0; i < n; i++) {
        result = max(dp[n - 1][i], result);
    }

    cout << result;

    


    
    return 0;
}