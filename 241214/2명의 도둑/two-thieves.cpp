#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m, c;
vector<vector<int>> matrix;

int backTrack(vector<int>& weights, int index, int totalWeight, int totalValue) {
    if (index == weights.size()) {
        return totalValue;
    }

    int exclude = backTrack(weights, index + 1, totalWeight, totalValue);

    int include = 0;
    if (totalWeight + weights[index] <= c) {
        include = backTrack(weights, index + 1, totalWeight + weights[index], totalValue + weights[index] * weights[index]);
    }

    return max(include, exclude);
}

int getMaxValue(vector<int>& weights) {
    return backTrack(weights, 0, 0, 0);
}


int calculateMaxValueInRow(int row, int startCol) {
    vector<int> weights;
    for (int col = startCol; col < startCol + m; ++col) {
        weights.push_back(matrix[row][col]);
    }
    return getMaxValue(weights);
}

bool isOverlap(int row1, int col1, int row2, int col2) {
    return row1 == row2 && !(col1 + m <= col2 || col2 + m <= col1);
}

int main() {
    cin >> n >> m >> c;
    matrix.resize(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int maxTotalValue = 0;

    for (int row1 = 0; row1 < n; ++row1) {
        for (int col1 = 0; col1 <= n - m; ++col1) {
            int value1 = calculateMaxValueInRow(row1, col1);

            for (int row2 = 0; row2 < n; ++row2) {
                for (int col2 = 0; col2 <= n - m; ++col2) {
                    if (!isOverlap(row1, col1, row2, col2)) {
                        int value2 = calculateMaxValueInRow(row2, col2);
                        maxTotalValue = max(maxTotalValue, value1 + value2);
                    }
                }
            }
        }
    }

    cout << maxTotalValue;

    return 0;
}
