#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int kCost(int k) {
    return k * k + (k + 1) * (k + 1);
}

int coverK(vector<vector<int>> matrix, int row, int col, int k, int n, int m) {

    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(row - i) + abs(col - j) <= k) {
                count += matrix[i][j];
            }
        }
    }

    return count;
}

int digGold(int n, int m, vector<vector<int>> matrix) {
    int maxGold = INT_MIN;
    int result;

    
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            for (int k = 0; k <= 2 * (n - 1); k++) {
                result = coverK(matrix, row, col, k, n, m);

                if (result * m > kCost(k)) {
                    maxGold = max(maxGold, result);
                }
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