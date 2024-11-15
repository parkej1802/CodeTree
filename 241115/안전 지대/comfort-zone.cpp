#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int n, m;
vector<vector<int>> matrix;
vector<vector<bool>> visited;
vector<vector<int>> copyMatrix;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int maxGroup = INT_MIN;
int kMax = 0;

void dfs(int row, int col) {
    
    visited[row][col] = true;

    for (int dir = 0; dir < 4; dir++) {
        int ny = dy[dir] + row;
        int nx = dx[dir] + col;

        if (ny >= 0 && ny < n && nx >= 0 && nx < m && !visited[ny][nx] && matrix[ny][nx] != 0) {
            dfs(ny, nx);
        }
    }
}

void setZeroMatrix(int k) {
    matrix = copyMatrix;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] <= k) {
                matrix[i][j] = 0;
            }
        }
    }
}

void safePosition() {

    int result = 0;

    for (int k = 1; k <= m; k++) {
        setZeroMatrix(k);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && matrix[i][j] != 0) {
                    result++;
                    dfs(i, j);
                    
                }
            }
        }
        visited.assign(n, vector<bool>(m, false));
        if (result > maxGroup) {
            maxGroup = result;
            kMax = k;
        }
        
        result = 0;
    }
}

int main() {
    cin >> n >> m;

    matrix.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    copyMatrix = matrix;

    safePosition();

    cout << kMax << " " << maxGroup;

    return 0;
}