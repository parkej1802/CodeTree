#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> matrix;
vector<pair<int, int>> posList;
vector<pair<int, int>> wallPos;
vector<vector<int>> newMatrix;


int n, k, sr, sc, er, ec;
int minDist;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool inRange(int row, int col, vector<vector<bool>>& visited) {
    return row >= 0 && row < n && col >= 0 && col < n && !visited[row][col] && newMatrix[row][col] != 1;
}

int bfs(int row, int col) {

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<vector<int>> dist(n, vector<int>(n, 0));

    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = true;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (r == er - 1 && c == ec - 1) {
            return dist[r][c];
        }

        for (auto d : dir) {
            int ny = r + d[0];
            int nx = c + d[1];

            if (inRange(ny, nx, visited)) {
                q.push({ny, nx});
                visited[ny][nx] = true;
                dist[ny][nx] = dist[r][c] + 1;
            }
        }
    }
    return -1;
} 

void deleteWall() {
    newMatrix = matrix;

    for (auto pa : posList) {
        newMatrix[pa.first][pa.second] = 0;
    }
}

void backTrack(int current, int count) {

    if (k == current) {
        deleteWall();
        int distance = bfs(sr - 1, sc - 1);
        if (distance != -1) {
            minDist = min(minDist, distance);
        }

        return;
    }
    
    for (int i = count; i < wallPos.size(); i++) {
        posList.push_back(wallPos[i]);
        backTrack(current + 1, i + 1);
        posList.pop_back();
    }
}

void findWallPos() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                wallPos.push_back({i, j});
            }
        }
    }
}

int main() {
    cin >> n >> k;

    matrix.resize(n, vector<int>(n));
    minDist = n * n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < 2; i++) {
        cin >> sr >> sc >> er >> ec;  
    }

    findWallPos();
    backTrack(0, 0);

    if (minDist != n * n) {
        cout << minDist;
    }
    else {
        cout << -1;
    }

    return 0;
}