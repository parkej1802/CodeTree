#include <iostream>
#include <vector>
using namespace std;

void fallingBlock(int n, int m, int k, vector<vector<int>>& matrix) {

    bool touch = false;

    for (int i = 0; i < n; i++) {
        for (int j = k - 1; j < k + m - 1; j++) {
            if (i + 1 < n) {
                if (matrix[i + 1][j] == 1) {
                    touch = true;
                }
            }
            if (touch) {
                for (int blockSize = k - 1; blockSize < k + m - 1; blockSize++) {
                    matrix[i][blockSize] = 1;
                }
                break;
            }
        }
        if (touch) {
            break;
        }
    }
}

int main() {
    int n, m, k;

    cin >> n >> m >> k;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    fallingBlock(n, m, k, matrix);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    } 

    return 0;
}