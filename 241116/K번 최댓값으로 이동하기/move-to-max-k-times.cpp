#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k, r, c;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

vector<vector<int>> matrix;
vector<vector<bool>> visited;
vector<vector<bool>> visitedCopy;

bool inRange(int row, int col, int num, vector<vector<bool>> visit) {
    return row >= 0 && row < n && col >= 0 && col < n && !visit[row][col] && matrix[row][col] < num;
}

int getNextMaxNumber(int num) {
    int maxNum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] < num) {
                maxNum = max(maxNum, matrix[i][j]);
            }
        }
    }

    return maxNum;
}

pair<int, int> getPosNextMaxNumber(int num) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (num != 0 && matrix[i][j] == num) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

bool reachable(int row, int col, int num, pair<int, int> pos, vector<vector<bool>> visit) {

    if (row == pos.first && col == pos.second) {
        return true;
    }

    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + row;
        int nx = dx[i] + col;

        if (inRange(ny, nx, num, visit)) {
            visit[ny][nx] = true;
            if (reachable(ny, nx, num, pos, visit)) {
                return true;
            }
        }
    }

    return false;
}

pair<int, int> bfs(int row, int col) {

    pair<int, int> result = {row, col};
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = true;
    int num = matrix[row][col];
    int numLoop = 0;

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if (numLoop == k) {
            return {row, col};
        }

        int nextNum = getNextMaxNumber(num);
        pair<int, int> nextPos = getPosNextMaxNumber(nextNum);
        if (nextPos.first == -1) break;
        
        while (!reachable(row, col, num, nextPos, visited)) {
            num = nextNum;
            nextNum = getNextMaxNumber(num);
            nextPos = getPosNextMaxNumber(nextNum);
        }

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