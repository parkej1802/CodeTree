#include <iostream>
#include <vector>
using namespace std;

int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void exchangeNum(int n, int m, vector<vector<int>>& matrix) {

    int endNum = n * n;
    int startNum = 1;
    int r, c;
    bool swap = false;
    vector<vector<int>> initMatrix = matrix;

    for (int t = 0; t < m; t++) {
        for (; startNum <= endNum; startNum++) {
            for (int row = 0; row < n; row++) {
                for (int col = 0; col < n; col++) {
                    int maxVal = 0;
                    
                    if (startNum == matrix[row][col]) {

                        for (int dir = 0; dir < 8; dir++) {
                            int ny = dy[dir] + row;
                            int nx = dx[dir] + col;

                            if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
                                int val = matrix[ny][nx];
                                if (val > maxVal) {
                                    maxVal = val;
                                    r = ny;
                                    c = nx;
                                }
                            }
                        }
                        initMatrix[row][col] = matrix[r][c];
                        initMatrix[r][c] = matrix[row][col];
                        swap = true;
                        break;
                    }
                }
                if (swap) {
                    swap = false;
                    break;
                } 
            }
            matrix = initMatrix;
        }
        startNum = 1;
    } 
}

int main() {
    int n, m;

    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    exchangeNum(n, m, matrix);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}