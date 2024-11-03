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

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for (int i = 0; i <= k; i++) {
        
        int bottomSide = row + i;
        int topSide = row - i;
        int leftSide = col - i;
        int rightSide = col + i;
        

        if (bottomSide < n && !visited[bottomSide][col] && matrix[bottomSide][col] == 1) {
            count++;
            visited[bottomSide][col] = true;
            if (rightSide < n && !visited[bottomSide - 1][rightSide] && matrix[bottomSide - 1][rightSide] == 1) {
                count++;
            }
            if (leftSide > 0 && !visited[bottomSide - 1][leftSide] && matrix[bottomSide - 1][leftSide] == 1) {
                count++;
            }
        }
        if (topSide > 0 && !visited[topSide][col] && matrix[topSide][col] == 1) {
            count++;
            visited[topSide][col] = true;
            if (rightSide < n && !visited[topSide + 1][rightSide] && matrix[topSide + 1][rightSide] == 1) {
                count++;
            }
            if (leftSide > 0 && !visited[topSide + 1][leftSide] && matrix[topSide + 1][leftSide] == 1) {
                count++;
            }
        }
        if (rightSide < n && !visited[row][rightSide] && matrix[row][rightSide] == 1) {
            count++;
            visited[row][rightSide] = true;
            if (bottomSide < n && !visited[bottomSide][rightSide - 1] && matrix[bottomSide][rightSide - 1] == 1) {
                count++;
            }
            if (topSide > 0 && !visited[topSide][rightSide - 1] && matrix[topSide][rightSide - 1] == 1) {
                count++;
            }
        }
        if (leftSide > 0 && !visited[row][leftSide] && matrix[row][leftSide] == 1) {
            count++;
            visited[row][leftSide] = true;
            if (bottomSide < n && !visited[bottomSide][leftSide + 1] && matrix[bottomSide][leftSide + 1] == 1) {
                count++;
            }
            if (topSide > 0 && !visited[topSide][leftSide + 1] && matrix[topSide][leftSide + 1] == 1) {
                count++;
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