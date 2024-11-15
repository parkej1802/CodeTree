#include <iostream>
#include <vector>
using namespace std;

int n;

vector<vector<int>> matrix;
vector<vector<bool>> visited;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};


int count = 1;

void dfs(int row, int col, int num) {

    visited[row][col] = true;

    for (int dir = 0; dir < 4; dir++) {
        int ny = dy[dir] + row;
        int nx = dx[dir] + col;

        if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx] && matrix[ny][nx] == num) {
            count++;
            dfs(ny, nx, num);
        }
    }
}

pair<int, int> explosionNum() {
    int maxNum = 0;
    int numPop = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                int number = matrix[i][j];
                dfs(i, j, number);
                maxNum = max(count, maxNum);
                if (count >= 4) {
                    numPop++;
                }
                count = 1;
            }
        }
    }

    return {numPop, maxNum};
}


int main() {
    cin >> n;

    matrix.resize(n, vector<int>(n));
    visited.resize(n, vector<bool>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    pair<int, int> result = explosionNum();

    cout << result.first << " " << result.second;

    return 0;
}