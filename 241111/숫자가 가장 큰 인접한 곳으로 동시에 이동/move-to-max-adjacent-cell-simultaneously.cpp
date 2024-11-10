#include <iostream>
#include <vector>
using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void print(vector<vector<int>> matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int moveToLargestNum(int n, int m, int t, vector<vector<int>> matrix, vector<pair<int, int>> marbles) {
    int result = 0;
    int maxVal = 0, val = 0;
    bool moved = false;
    vector<vector<int>> temp(n, vector<int>(n, 0));

    for (int i = 0 ; i < m; i++) {
        auto [mRow, mCol] = marbles[i];
        temp[mRow - 1][mCol - 1] = 1;
    }

    for (int sec = 0; sec < t; sec++) {
        vector<vector<int>> nextTemp(n, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            maxVal = 0;
            auto [mRow, mCol] = marbles[i];
            mRow -= 1;
            mCol -= 1;
            int row = mRow, col = mCol;

            for (int d = 0; d < 4; d++) {
                int ny = dy[d] + mRow;
                int nx = dx[d] + mCol;

                if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
                    if (matrix[mRow][mCol] < matrix[ny][nx]) {
                        val = matrix[ny][nx];
                        if (maxVal < val) {
                            moved = true;
                            maxVal = val;
                            row = ny;
                            col = nx;
                        }
                    }
                }
            }
            if (moved) {
                nextTemp[row][col] += 1;
            }
           
            marbles[i] = {row + 1, col + 1};
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (nextTemp[i][j] >= 2) {
                    nextTemp[i][j] = 0;
                }
            }
        }
        temp = nextTemp;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result += temp[i][j];
        }
    }
    
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