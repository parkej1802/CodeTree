#include <iostream>
#include <vector>

using namespace std;

int n; 
vector<vector<int>> matrix;
vector<vector<int>> dp;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1 ,1};

bool inRange(int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < n;
}

int dfs(int row, int col) {

    if (dp[row][col] != -1) {
        return dp[row][col];
    }

    dp[row][col] = 1;

    for (int dir = 0; dir < 4; dir++) {
        int ny = dy[dir] + row;
        int nx = dx[dir] + col;

        if (inRange(ny, nx) && matrix[row][col] < matrix[ny][nx]) {
            dp[row][col] = max(dp[row][col], 1 + dfs(ny, nx));
        }
     }

     return dp[row][col];
}

int dynamic() {
    int maxValue = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            int result = dfs(row, col);
            maxValue = max(result, maxValue);
        }
    }
    return maxValue;
}

int main() {

    cin >> n;

    matrix.resize(n, vector<int>(n));
    dp.resize(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    int result = dynamic();

    cout << result; 

    return 0;
}