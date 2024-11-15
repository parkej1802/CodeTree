#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> matrix;
vector<vector<bool>> visited;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool inRange(int y, int x) {
    return x >= 0 && x < m && y < n && y >= 0;
}

int bfs(int r, int c) {
    int result = 0;

    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;

    while(!q.empty()) {

        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if (row == n - 1 && col == m - 1) {
            return 1;
        }

        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + row;
            int nx = dx[i] + col;
            if (inRange(ny, nx) && !visited[ny][nx] && matrix[ny][nx] == 1) {
                visited[ny][nx] = true;
                q.push({ny, nx});
            }   
        }
    }

    return result;
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

    int result = bfs(0, 0);

    cout << result;

    return 0;
}