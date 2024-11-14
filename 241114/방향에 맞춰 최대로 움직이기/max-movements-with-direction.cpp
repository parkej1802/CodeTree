#include <iostream>
#include <vector>

using namespace std;

int n, r, c, nSize, maxMove = 0;
vector<vector<int>> matrix;
vector<vector<int>> direction;
vector<vector<bool>> visited;
vector<int> numWays;


int dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

void backTracking(int y, int x, int current) {

    maxMove = max(current, maxMove);
    
    int currentNum = matrix[y][x];
    int d = direction[y][x] - 1;
    
    for (int i = 0; i < n; i++) {
    
        int ny = dir[d][0] + y;
        int nx = dir[d][1] + x;

        if (ny >= 0 && ny < n && nx >= 0 && nx < n  && !visited[ny][nx] && matrix[ny][nx] > currentNum) {
            visited[ny][nx] = true;
            backTracking(ny, nx, current + 1);
            visited[ny][nx] = false;
        }

        y = ny;
        x = nx;
    }
}

int main() {

    cin >> n;

    nSize = n * n - 1;
    matrix.resize(n, vector<int>(n));
    direction.resize(n, vector<int>(n));
    visited.resize(n, vector<bool>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> direction[i][j];
        }
    }

    cin >> r >> c;

    visited[r - 1][c - 1] = true;
    backTracking(r - 1, c - 1, 0);

    cout << maxMove;

    
    return 0;
}