#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

pair<int, bool> function(vector<vector<int>>& matrix, int n, int& row, int& col, int dirNum, int moveTimes, queue<pair<int, int>>& body) {
    int time = 0;
    

    for (int j = 0; j < moveTimes; j++) {
        int ny = dy[dirNum] + row;
        int nx = dx[dirNum] + col;
        time++;
        if (ny < n && ny >= 0 && nx < n && nx >= 0) {
            queue<pair<int, int>> q;
            pair<int, int> tail = body.front();
            int tempR = tail.first, tempC = tail.second;
            body.pop();
            matrix[tempR][tempC] = 0;

            if (matrix[ny][nx] == 1) {
                q.push({tempR, tempC});
                body.push({ny, nx});
                while(!body.empty()) {
                    q.push(body.front());
                    body.pop();
                }
                body = q;
                matrix[tempR][tempC] = 2;
                matrix[ny][nx] = 2;
            }
            else if (matrix[ny][nx] == 2) {
                return {time, false};
            }
            else {
                body.push({ny, nx});
                matrix[ny][nx] = 2;
            }
            row = ny;
            col = nx;
        }
        else {
            return {time, false};
        }
    }
    return {time, true};
}

int snakeLovesApple(int n, int m, int k, vector<pair<int, int>> apple, vector<pair<char, int>> move) {
    int time = 0;

    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int row = 0;
    int col = 0;

    for (int i = 0; i < m; i++) {
        matrix[apple[i].first - 1][apple[i].second - 1] = 1;
    }

    matrix[0][0] = 2;

    queue<pair<int, int>> body;

    body.push({row, col});

    for (int i = 0; i < k; i++) {
        pair<int, bool> t;
        if (move[i].first == 'R') {
            t = function(matrix, n, row, col, 3, move[i].second, body);
        }
        else if (move[i].first == 'L') {
            t = function(matrix, n, row, col, 2, move[i].second, body);
        }
        else if (move[i].first == 'U') {
            t = function(matrix, n, row, col, 0, move[i].second, body);
        }
        else if (move[i].first == 'D') {
            t = function(matrix, n, row, col, 1, move[i].second, body);
        }
        
        time += t.first;
        if (!t.second) break;
    }

    return time;
 }

int main() {
    int n, m, k;

    cin >> n >> m >> k;

    vector<pair<int, int>> apple;
    vector<pair<char, int>> move;

    int r, c, mn;
    char d;

    for (int i = 0; i < m; i++) {
        cin >> r >> c;
        apple.push_back({r, c});
    }

    for (int i = 0; i < k; i++) {
        cin >> d >> mn;
        move.push_back({d, mn});
    }

    int result = snakeLovesApple(n, m, k, apple, move);

    cout << result;

    return 0;
}