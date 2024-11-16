#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k, m, r, c;
vector<vector<int>> matrix;
vector<vector<bool>> visited;
vector<pair<int, int>> pos;
vector<pair<int, int>> rockPos;
vector<pair<int, int>> numRockPos;
vector<vector<pair<int, int>>> allComb;
vector<vector<int>> copyMatrix;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool inRange(int row, int col, vector<vector<bool>>& visit) {
    return row >= 0 && row < n && col >= 0 && col < n && !visit[row][col] && matrix[row][col] == 0;
}

int bfs(int row, int col, vector<vector<bool>> visit) {
    vector<vector<bool>> localVisit = visit;
    queue<pair<int, int>> q;

    q.push({row, col});
    localVisit[row][col] = true;
    int result = 1;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + r;
            int nx = dx[i] + c;

            if (inRange(ny, nx, localVisit)) {
                q.push({ny, nx});
                localVisit[ny][nx] = true;
                result++;
            }
        }
    }
    return result;
}

int removeRock() {
    int maxValue = -1;
    for (int i = 0; i < allComb.size(); i++) {
        matrix = copyMatrix;
        for (int j = 0; j < m; j++) {
            matrix[allComb[i][j].first][allComb[i][j].second] = 0;
        }
        for (int a = 0; a < k; a++) {
            int rs = bfs(pos[a].first, pos[a].second, visited);
            maxValue = max(rs, maxValue);
            
        }
    }
    return maxValue;
}

void rockComb(int current, int count) {
    if (current == m) {
        allComb.push_back(numRockPos);
        return;
    }

    for (int i = count; i < rockPos.size(); i++) {
        numRockPos.push_back({rockPos[i]});
        rockComb(current + 1, i + 1);
        numRockPos.pop_back();
    }
}

void getRockPosition() {
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            if (matrix[i][j] == 1) 
                rockPos.push_back({i,j});
}

int main() {
    cin >> n >> k >> m;

    matrix.resize(n, vector<int>(n));
    visited.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
     
    copyMatrix = matrix;

    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        pos.push_back({r - 1, c - 1});
    }

    getRockPosition();
    rockComb(0, 0);
    
    int result = removeRock();
    cout << result;

    return 0;
}