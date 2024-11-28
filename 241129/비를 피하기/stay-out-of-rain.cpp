#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, h, m;

vector<vector<int>> matrix;
vector<vector<int>> numPeople;
vector<vector<int>> result;

int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

bool inRange(int row, int col, vector<vector<bool>> visited) {
    return  row >= 0 && row < n && col >= 0 && col < n && matrix[row][col] != 1 && !visited[row][col];
}

int bfs(int row, int col, vector<vector<bool>> visited) {
    
    vector<vector<int>> dist(n, vector<int>(n, 0));
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = true;
    dist[row][col] = 0;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (matrix[r][c] == 3 && m > numPeople[r][c]) {
            numPeople[r][c]++;
            return dist[r][c];
        }

        for (auto d : dir) {
            int ny = r + d[0];
            int nx = c + d[1];

            if (inRange(ny, nx, visited)) {
                visited[ny][nx] = true;
                q.push({ny, nx});
                dist[ny][nx] = dist[r][c] + 1;
            }
        }

    }
    return -1;
}

void findPlaceToHide(vector<vector<bool>> visited) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 2) {
                int distance = bfs(i, j, visited);
                result[i][j] = distance;
            }
        }
    }
}

int main() {
    cin >> n >> h >> m;

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    matrix.resize(n, vector<int>(n));
    numPeople.resize(n, vector<int>(n, 0));
    result.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    findPlaceToHide(visited);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}