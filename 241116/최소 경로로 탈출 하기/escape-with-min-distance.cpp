#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

vector<vector<int>> matrix;
vector<vector<bool>> visited;
vector<vector<int>> dist;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool inRange(int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < n && !visited[row][col] && matrix[row][col] == 1;
}

int bfs(int row, int col) {

    queue<pair<int, int>> q;
    q.push({row, col});

    visited[row][col] = true;
    dist[row][col] = 0;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (r == n - 1 && c == m - 1) {
            return dist[r][c];
        }

        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + r;
            int nx = dx[i] + c;

            if (inRange(ny, nx)) {
                q.push({ny, nx});
                visited[ny][nx] = true;
                dist[ny][nx] = dist[r][c] + 1;
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    
    matrix.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));
    dist.resize(n, vector<int>(m, 0));
        
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int result = bfs(0, 0);

    cout << result;

    return 0;
}