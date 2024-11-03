#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int trimino(int n, int m, vector<vector<int>> matrix) {

    int maxValue = INT_MIN;
    int value = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
        
            if (col + 2 < m) {
                value = matrix[row][col] + matrix[row][col + 1] + matrix[row][col + 2];
                maxValue = max(maxValue, value);
            }

            if (row + 2 < n) {
                value = matrix[row][col] + matrix[row + 1][col] + matrix[row + 2][col];
                maxValue = max(maxValue, value);
            }

            if (col + 1 < m && row + 1 < n) {
                value = matrix[row][col] + matrix[row + 1][col] + matrix[row][col + 1];
                maxValue = max(maxValue, value);
            }

            if (col - 1 >= 0 && row - 1 >= 0) {
                value = matrix[row][col] + matrix[row - 1][col] + matrix[row][col - 1];
                maxValue = max(maxValue, value);
            }

            if (col + 1 < m && row - 1 >= 0) {
                value = matrix[row][col] + matrix[row - 1][col] + matrix[row][col + 1];
                maxValue = max(maxValue, value);
            }

            if (row + 1 < n && col - 1 >= 0) {
                value = matrix[row][col] + matrix[row + 1][col] + matrix[row][col - 1];
                maxValue = max(maxValue, value);
            }
        }
    }

    return maxValue;
}

int main() {
    
    int n, m;

    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int result = trimino(n, m, matrix);

    cout << result;
    return 0;
}