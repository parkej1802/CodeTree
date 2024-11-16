#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k, r, c;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

struct Pos {
    int row;
    int col;
    int num;
};

vector<vector<int>> matrix;
vector<vector<bool>> visited;

bool inRange(int row, int col, int num, const vector<vector<bool>>& visit) {
    return row >= 0 && row < n && col >= 0 && col < n && !visit[row][col] && matrix[row][col] < num;
}

pair<int, int> getNextNumPos(int row, int col, int num, const vector<vector<bool>>& visit) {
    vector<vector<bool>> localVisit = visit;
    queue<pair<int, int>> q;
    q.push({row, col});
    localVisit[row][col] = true;

    int maxValue = -1;
    int minRow = -1;
    int minCol = -1;

    while (!q.empty()) {
        int curRow = q.front().first;
        int curCol = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = curRow + dy[i];
            int nx = curCol + dx[i];

            if (inRange(ny, nx, num, localVisit)) {
                localVisit[ny][nx] = true;
                int currentValue = matrix[ny][nx];

                if (currentValue > maxValue) {
                    maxValue = currentValue;
                    minRow = ny;
                    minCol = nx;
                } else if (currentValue == maxValue && ny < minRow) {
                    minRow = ny;
                    minCol = nx;
                }
                else if (currentValue == maxValue && ny == minRow && nx < minCol) {
                    minRow = ny;
                    minCol = nx;
                }

                q.push({ny, nx});
            }
        }
    }

    return {minRow, minCol};
}

pair<int, int> bfs(int row, int col) {
    pair<int, int> result = {row, col};
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = true;
    int num = matrix[row][col];
    int numLoop = 0;

    while (!q.empty()) {
        int curRow = q.front().first;
        int curCol = q.front().second;
        q.pop();

        if (numLoop == k) {
            return {curRow, curCol};
        }

        pair<int, int> nextPos = getNextNumPos(curRow, curCol, num, visited);

        if (nextPos.first == -1) break;
  
        q.push(nextPos);
        visited[nextPos.first][nextPos.second] = true;
        result = {nextPos.first, nextPos.second};
        num = matrix[nextPos.first][nextPos.second];
        numLoop++;
    }

    return result;
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

    cin >> r >> c;

    pair<int, int> result = bfs(r - 1, c - 1);

    cout << result.first + 1 << " " << result.second + 1;

    return 0;
}
