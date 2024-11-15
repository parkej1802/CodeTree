#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k, r, c;
vector<vector<int>> matrix;
vector<vector<bool>> visited;
vector<pair<int, int>> pos;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool inRange(int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < n && !visited[row][col] && matrix[row][col] == 0;
}

int bfs(int row, int col) {

    int count = 1;
    if (visited[row][col]) count = 0;
    
    queue<pair<int, int>> q;
    q.push({row, col});

    visited[row][col] = true;

    while(!q.empty()) {

        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + row;
            int nx = dx[i] + col;

            if (inRange(ny, nx)) {
                q.push({ny, nx});
                count++;
                visited[ny][nx] = true;
            }
        }
    }

    return count;
}

int main() {
    cin >> n >> k;

    matrix.resize(n, vector<int>(n));
    visited.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        pos.push_back({r - 1,c - 1});
    }

    int result = 0;

    for (int i = 0; i < k; i++) {
        int row = pos[i].first;
        int col = pos[i].second;
        result += bfs(row, col);
    }

    cout << result;

    return 0;
}