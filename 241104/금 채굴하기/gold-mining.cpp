#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int kCost(int k) {
    return k * k + (k + 1) * (k + 1);
}

int coverK(vector<vector<int>> matrix, int row, int col, int k, int n, int m) {

    int count = 0;
    int maxGold = 0;

    for (int i = 0; i <= k; i++) {
        
        int bottomSide = row + i;
        int topSide = row - i;
        int leftSide = col - i;
        int rightSide = col + i;
        
        if (i == 0) {
            if (matrix[row][col] == 1) count++;
        }

        else {
            if (bottomSide < n && matrix[bottomSide][col] == 1) {
                count++;
                if (rightSide < n && matrix[bottomSide - 1][rightSide] == 1) {
                    count++;
                }
                if (leftSide > 0 && matrix[bottomSide - 1][leftSide] == 1) {
                    count++;
                }
            }
            if (topSide > 0 && matrix[topSide][col] == 1) {
                count++;
                if (rightSide < n && matrix[topSide + 1][rightSide] == 1) {
                    count++;
                }
                if (leftSide > 0 && matrix[topSide + 1][leftSide] == 1) {
                    count++;
                }
            }
            if (rightSide < n && matrix[row][rightSide] == 1) {
                count++;
                if (bottomSide < n && matrix[bottomSide][rightSide - 1] == 1) {
                    count++;
                }
                if (topSide > 0 && matrix[topSide][rightSide - 1] == 1) {
                    count++;
                }
            }
            if (leftSide > 0 && matrix[row][leftSide] == 1) {
                count++;
                if (bottomSide < n && matrix[bottomSide][leftSide + 1] == 1) {
                    count++;
                }
                if (topSide > 0 && matrix[topSide][leftSide + 1] == 1) {
                    count++;
                }
            }
        }
        
        if (maxGold < count && kCost(i) < count * m) {
            maxGold = count;
        }
             
        count = 0;

    }
    return maxGold;
}

int digGold(int n, int m, vector<vector<int>> matrix) {
    int maxGold = INT_MIN;
    int result;

    for (int k = 0; k < n; k++) {
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                result = coverK(matrix, row, col, k, n, m);
                maxGold = max(maxGold, result);
            }
        }
    }
    

    return maxGold;
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

    int result = digGold(n, m, matrix);

    cout << result;

    return 0;
}