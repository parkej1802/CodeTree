#include <iostream>
#include <vector>

using namespace std;

int checkRowCol(int n, int m, vector<vector<int>> matrix) {

    int result = 0;

    for (int row = 0; row < n; row++) {
        int countX = 1;

        for (int col = 1; col < n; col++) {
            if (matrix[row][col] == matrix[row][col - 1]) {
                countX++;
                if (countX == m) {
                    result++;
                    break;
                }
            }
            else {
                countX = 1;
            }
        }
    }

    for (int row = 0; row < n; row++) {
        int countY = 1;
        for (int col = 1; col < n; col++) {
            if (matrix[col][row] == matrix[col - 1][row]) {
                countY++;
                if (countY == m) {
                    result++;
                    break;
                }
            }
            else {
                countY = 1;
            }

        }
    }
    
    if (m == 1) {
        return 2 * n;
    }

    return result;
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

    int result = checkRowCol(n, m, matrix);

    cout << result;

    return 0;
}