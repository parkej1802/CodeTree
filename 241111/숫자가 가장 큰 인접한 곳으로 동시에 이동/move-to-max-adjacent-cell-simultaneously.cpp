#include <iostream>
#include <vector>
using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void print(const vector<vector<int>>& matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------------------------------" << endl;
}

int moveToLargestNum(int n, int m, int t, vector<vector<int>> matrix, vector<pair<int, int>> marbles) {
    int result = 0;
    vector<vector<int>> temp(n, vector<int>(n, 0));

    for (const auto& marble : marbles) {
        int mRow = marble.first - 1;
        int mCol = marble.second - 1;
        temp[mRow][mCol] += 1;
    }

    for (int sec = 0; sec < t; sec++) {
        vector<vector<int>> nextTemp(n, vector<int>(n, 0));
        vector<pair<int, int>> newMarbles;

        for (auto& marble : marbles) {
            int maxVal = 0;
            int mRow = marble.first - 1;
            int mCol = marble.second - 1;
            int row = mRow, col = mCol;

            for (int d = 0; d < 4; d++) {
                int ny = dy[d] + mRow;
                int nx = dx[d] + mCol;

                if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
                    int val = matrix[ny][nx];
                    if (maxVal < val) {
                        maxVal = val;
                        row = ny;
                        col = nx;
                    }
                }
            }

            nextTemp[row][col] += 1;
            newMarbles.push_back({row + 1, col + 1});
        }

        marbles.clear();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (nextTemp[i][j] >= 2) {
                    nextTemp[i][j] = 0;
                } else if (nextTemp[i][j] == 1) {
                    marbles.push_back({i + 1, j + 1});
                }
            }
        }

        temp = nextTemp;
    }
    
    result = marbles.size();
    
    return result;
}

int main() {
    int n, m, t, r, c;

    cin >> n >> m >> t;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<pair<int, int>> marbles;

    for (int i = 0; i < m; ++i) {
        cin >> r >> c;
        marbles.push_back({r, c});
    }

    int result = moveToLargestNum(n, m, t, matrix, marbles);

    cout << result;

    return 0;
}