#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1 ,1};

int countBombs(int n, int m, int r, int c) {

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    int row = r - 1;
    int col = c - 1;

    matrix[row][col] = 1;

    for (int sec = 1; sec <= m; sec++) {
        vector<vector<int>> temp = matrix;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                if (matrix[i][j] == 1) {
                    for (int dir = 0; dir < 4; dir++) {
                        int ny = dy[dir] * pow(2, sec - 1) + i;
                        int nx = dx[dir] * pow(2, sec - 1) + j;

                        if (ny >= 0 && ny < n && nx < n && nx >= 0 && temp[ny][nx] != 1) {
                            temp[ny][nx] = 1;
                        }
                    } 
                }
            } 
        }
        matrix = temp;
    }

    int result = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result += matrix[i][j];
        }
    }
    return result;
}

int main() {
    int n, m, r, c;

    cin >> n >> m >> r >> c;

    int result = countBombs(n, m, r, c);

    cout << result;

    return 0;
}