#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dx[8] = {-1, 1, -2, 2, 2, -2, -1, 1};

int n, m, rowStart, colStart, rowEnd, colEnd;
vector<vector<int>> matrix;
vector<vector<bool>> visited;
vector<vector<int>> dist;

int bfs(int row, int col) {
    queue<pair<int, int>> q;

    q.push({row, col});
    visited[row][col] = true;
    dist[row][col] = 0;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (r == rowEnd - 1 && c == colEnd - 1) {
            return dist[r][c];
        }

        for (int i = 0; i < 8; i++) {
            int ny = dy[i] + r;
            int nx = dx[i] + c;

            if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx]) {
                q.push({ny, nx});
                visited[ny][nx] = true;
                dist[ny][nx] = dist[r][c] + 1;
            }
        }
    }
    return -1;
    
}

int main() {
    
    cin >> n;

    matrix.resize(n, vector<int>(n, 0));
    visited.resize(n, vector<bool>(n, false));
    dist.resize(n, vector<int>(n, 0));

    cin >> rowStart >> colStart >> rowEnd >> colEnd;

    int result = bfs(rowStart - 1, colStart - 1);

    cout << result;
    

    return 0;
}