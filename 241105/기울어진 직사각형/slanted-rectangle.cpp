#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {-1, -1, 1, 1};
int dy[4] = {1, -1, -1, 1};

int calcRectangleSum(int x, int y, int len1, int len2, const vector<vector<int>>& matrix, int n) {
    int sum = 0;
    int curX = x, curY = y;

    for (int i = 0; i < 4; i++) {
        int length = (i % 2 == 0) ? len1 : len2;
        for (int j = 0; j < length; j++) {
            if (curX < 0 || curX >= n || curY < 0 || curY >= n) {
                return 0;
            }
            sum += matrix[curX][curY];
            curX += dx[i];
            curY += dy[i];
        }
    }

    if (curX == x && curY == y) {
        return sum;
    }

    return 0;
}

int tiltedRectangle(int n, vector<vector<int>> matrix) {
    int maxSum = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            for (int len1 = 1; len1 < n; len1++) {
                for (int len2 = 1; len2 < n; len2++) {
                    int sum = calcRectangleSum(x, y, len1, len2, matrix, n);
                    maxSum = max(maxSum, sum);
                }
            }
        }
    }

    return maxSum;
}

int main() {
    int n;

    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int result = tiltedRectangle(n ,matrix);

    cout << result;
    return 0;
}