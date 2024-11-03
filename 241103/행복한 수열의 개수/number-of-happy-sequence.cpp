#include <iostream>
#include <vector>

using namespace std;

int checkRowCol(int n, int m, vector<vector<int>> matrix) {

    int result = 0;

    for (int row = 1; row < n; row++) {
        int countX = 1, countY = 1;

        for (int col = 1; col < n; col++) {
            if (matrix[row - 1][col - 1] == matrix[row - 1][col]) {
                countX++;
                if (countX == m) {
                    result++;
                }
            }
            else {
                countX = 1;
            }

            if (matrix[col - 1][row - 1] == matrix[col][row - 1]) {
                countY++;
                if (countY == m) {
                    result++;
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