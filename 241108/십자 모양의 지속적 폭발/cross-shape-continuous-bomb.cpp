#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void crossExplosion(int n, int m, vector<vector<int>>& matrix, vector<int> c) {

    for (int i = 0; i < m; i++) {
        int col = c[i] - 1;
        
        int explosionRange = 0, newRow = 0;

        for (int row = 0; row < n; row++) {
            if (matrix[row][col] != 0) {
                explosionRange = matrix[row][col];
                matrix[row][col] = 0;
                newRow = row;
                break;
            }
        }

        for (int j = 1; j < explosionRange; j++) {
            for (int a = 0; a < 4; a++) {
                int nx = dx[a] * (j) + col;
                int ny = dy[a] * (j) + newRow;

                if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
                    matrix[ny][nx] = 0;
                }
            }
        }

        for (int co = 0; co < n; co++) {
            int emptyRow = n - 1;
            for (int ro = n - 1; ro >= 0; ro--) {
                if (matrix[ro][co] != 0) {
                    matrix[emptyRow][co] = matrix[ro][co];
                    if (emptyRow != ro) {
                        matrix[ro][co] = 0;
                    }
                    emptyRow--;
                }
            }
        }
    }
}

int main() {
    int n, m;

    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int col;
    vector<int> c;

    for (int i = 0; i < m; i++) {
        cin >> col;
        c.push_back(col);
    }

    crossExplosion(n, m, matrix, c);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}