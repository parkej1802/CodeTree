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

    for (int i = 0; i < 2; i++) {
        int ny = dy[i] + row;
        int nx = dx[i] + col;
        if (ny >= 0 && ny < n && nx >= 0 && nx < n && matrix[ny][nx] == 1 && !visited[ny][nx]) {
            if (ny == n - 1 && nx == m - 1) {
                return escape++;
            }
            visited[ny][nx] = true;
            dfs(ny, nx);

        }
    }

    return escape;

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

    int result = dfs(0, 0);

    cout << result;

    
    return 0;
}