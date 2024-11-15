#include <iostream>
#include <vector>
using namespace std;

int dy[2] = {1, 0};
int dx[2] = {0, 1};

int n, m;
vector<vector<bool>> visited;
vector<vector<int>> matrix;

int escape = 0;

int dfs(int row, int col) {

    if (row == n - 1 && col == m - 1) {
        return 1;
    }

    for (int i = 0; i < 2; i++) {
        int ny = dy[i] + row;
        int nx = dx[i] + col;
        if (ny >= 0 && ny < n && nx >= 0 && nx < m && matrix[ny][nx] == 1 && !visited[ny][nx]) {
            visited[ny][nx] = true;
            if (dfs(ny, nx)) {
                return 1;
            }
        }
    }

    return 0;

}

int main() {

    cin >> n >> m;

    visited.resize(n, vector<bool>(m, false));
    matrix.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    visited[0][0] = true;
    int result = dfs(0, 0);

    cout << result;

    
    return 0;
}