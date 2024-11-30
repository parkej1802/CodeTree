#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int n, k, u, d;

vector<vector<int>> matrix;
priority_queue<int> pq;
vector<pair<int, int>> btList;
vector<vector<bool>> visited;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool inRange(int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < n && !visited[row][col];
}

struct city {
    int row, col;
    int count;
};

int bfs(int row, int col) {

    queue<city> q;
    q.push({row, col, 1});
    visited[row][col] = true;
    int maxCount = 1;

    while (!q.empty()) {

        int r = q.front().row;
        int c = q.front().col;
        int count = q.front().count;
        
        q.pop();

        for (auto di : dir) {
            int ny = r + di[0];
            int nx = c + di[1];

            if (inRange(ny, nx)) {
                int diff = abs(matrix[ny][nx] - matrix[r][c]);
                if (diff <= d && diff >= u) {
                    visited[ny][nx] = true;
                    q.push({ny, nx, count + 1});
                    maxCount++;
                }
            }
        }
    }

    return maxCount;
}

void print() {

    for (auto p : btList) {
        cout << p.first << " " << p.second << " ";
    }
    cout << endl;
}

int maxCity = 0;
void backTracking(int current, int count) {

    if (current == k) {
        int sumNum = 0;
        visited.assign(n, vector<bool>(n, false));
        for (auto p : btList) {
            sumNum += bfs(p.first, p.second); 
        }
        maxCity = max(maxCity, sumNum);
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = count; j < n; j++) {
            btList.push_back({i, j});
            backTracking(current + 1, count + 1);
            btList.pop_back();
        }
    }


}

int main() {
    cin >> n >> k >> u >> d;

    matrix.resize(n, vector<int>(n));
    visited.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    backTracking(0, 0);
    
    cout << maxCity;

    return 0;
}