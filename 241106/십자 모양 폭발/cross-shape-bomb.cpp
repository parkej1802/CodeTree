#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void crossExplosion(int n, vector<vector<int>>& matrix, int r, int c) {

    int row = r - 1, col = c - 1;
    int loop = matrix[row][col] - 1;

    matrix[row][col] = 0;

    for (int i = 0; i < loop; i++) {
        for (int j = 0; j < 4; j++) {
            int ny = dy[j] * (i + 1) + row;
            int nx = dx[j] * (i + 1) + col;

            if (ny < n && ny >=0 && nx < n && nx >= 0) {
                matrix[ny][nx] = 0;
            }
        }
    }
}

void applyGravity(int n, vector<vector<int>>& matrix) {
    for (int col = 0; col < n; col++) {
        int emptyRow = n - 1;

        for (int row = n - 1; row >= 0; row--) {
            if (matrix[row][col] != 0) {
                matrix[emptyRow][col] = matrix[row][col];
                if (emptyRow != row) matrix[row][col] = 0;
                emptyRow--;
            }
        }
    }
}

int main() {
    int n, r, c;

    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];

    cin >> r >> c;

    crossExplosion(n, matrix, r, c);
    applyGravity(n, matrix);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}