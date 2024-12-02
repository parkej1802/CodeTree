#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> matrix;
vector<vector<bool>> visited;
vector<pair<int, int>> nonIceList;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool inRange(int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < m && !visited[row][col] && matrix[row][col] == 0;
}

bool iceInRange(int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < m && !visited[row][col] && matrix[row][col] == 1;
}

void bfs(int row, int col) {
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = true;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        nonIceList.push_back({r, c});

        for (auto d : dir) {
            int ny = r + d[0];
            int nx = c + d[1];

            if (inRange(ny, nx)) {
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
}

void print() {
    cout << nonIceList.size() << endl;

    for (auto p : nonIceList) {
        cout << p.first << " " << p.second << endl;
    }
    cout << "-------------------------------------------" << endl;
}

void printMatrix() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------------------------------------" << endl;
}

int iceBreak() {
    int size = 0;

    for (auto p : nonIceList) {

        for (auto d : dir) {
            int ny = p.first + d[0];
            int nx = p.second + d[1];

            if (iceInRange(ny, nx)) {
                matrix[ny][nx] = 0;
                size++;
            }
        }
    }

    return size;
}

int second = 0;
int sizeResult = 0;

void findNonIcePos() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && matrix[i][j] == 0) {
                visited.assign(n, vector<bool>(m, false));
                nonIceList.clear();
                //printMatrix();
                bfs(i, j);
                //print();
                int size = iceBreak();
                if (size > 0) {
                    sizeResult = size;
                    second++;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;

    matrix.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    findNonIcePos();

    cout << second << " " << sizeResult;

    return 0;
}