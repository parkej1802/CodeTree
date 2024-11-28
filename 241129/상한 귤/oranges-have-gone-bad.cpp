#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, k;
vector<vector<int>> matrix;
vector<pair<int, int>> rottenOrangePos;
vector<vector<int>> result;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool inRange(int row, int col, vector<vector<bool>>& visited) {
    return row >= 0 && row < n && col >= 0 && col < n && !visited[row][col] && matrix[row][col] != 0;
}

void bfs(int row, int col) {
    queue<pair<int, int>> q;
    vector<vector<bool>>visited (n, vector<bool>(n, false));
    vector<vector<int>> dist(n, vector<int>(n, 0));

    q.push({row, col});
    visited[row][col] = true;
    dist[row][col] = 0;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (auto d : dir) {
            int ny = r + d[0];
            int nx = c + d[1];

            if (inRange(ny, nx, visited) && matrix[ny][nx] == 1) {
                q.push({ny, nx});
                visited[ny][nx] = true;
                result[ny][nx] = min(dist[r][c] + 1, result[ny][nx]);
                dist[ny][nx] = dist[r][c] + 1;
                
            }
        }
    }
}


void findRottenOrange() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 2) {
                rottenOrangePos.push_back({i, j});
            }
        }
    }
}

void getResultMatrix() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                result[i][j] = -1;
            }
            if (matrix[i][j] == 2) {
                result[i][j] = 0;
            }
            if (result[i][j] == INT_MAX) {
                result[i][j] = -2;
            }
        }
    }
}

int main() {
    cin >> n >> k;

    matrix.resize(n, vector<int>(n));
    result.resize(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    findRottenOrange();

    for (int i = 0; i < k; i++) {
        int r = rottenOrangePos[i].first;
        int c = rottenOrangePos[i].second;
        bfs(r, c);
    }

    getResultMatrix();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}