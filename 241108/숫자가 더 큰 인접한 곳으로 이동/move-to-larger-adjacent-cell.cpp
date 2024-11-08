#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

vector<int> moveToLargerNum(int n, int r, int c, vector<vector<int>> matrix) {
    
    bool hasLargerNum = true;
    vector<int> result;
    int row = r - 1;
    int col = c - 1;

    result.push_back(matrix[row][col]);

    while (hasLargerNum) {
        hasLargerNum = false;

        for (int dir = 0; dir < 4; dir++) {
            int ny = dy[dir] + row;
            int nx = dx[dir] + col;

            if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
                if (matrix[ny][nx] > matrix[row][col]) {
                    hasLargerNum = true;
                    result.push_back(matrix[ny][nx]);
                    row = ny;
                    col = nx;
                    break;
                }
            }   
        }
    }
    return result;
}

int main() {

    int n, r, c;

    cin >> n >> r >> c;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> result = moveToLargerNum(n, r, c, matrix);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}