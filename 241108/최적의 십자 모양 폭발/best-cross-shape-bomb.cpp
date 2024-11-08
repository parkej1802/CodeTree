#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void applyGravity(vector<vector<int>>& matrix, int n) {

    for (int col = 0; col < n; col++) {
        int emptyRow = n - 1;
        for (int row = n - 1; row >= 0; row--) {
            if (matrix[row][col] != 0) {
                matrix[emptyRow][col] = matrix[row][col];
                if (emptyRow != row) {
                    matrix[row][col] = 0;
                }
                emptyRow--;
            }
            
        }
    }
}

int countPair(vector<vector<int>>& matrix, int n) {

    int count = 0;

    for (int col = 0; col < n; col++) {
        for (int row = 1; row < n; row++) {
            if (matrix[row][col] == matrix[row - 1][col] && matrix[row][col] != 0) {
                count++;
            }
        }
    }

    for (int row = 0; row < n; row++) {
        for (int col = 1; col < n; col++) {
            if (matrix[row][col] == matrix[row][col - 1] && matrix[row][col] != 0) {
                count++;
            }
        }
    }
    return count;
}

int bestCrossExplosion(int n, vector<vector<int>>& matrix) {
    vector<vector<int>> save(n, vector<int>(n));
    
    save = matrix;

    int result = INT_MIN;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            matrix = save;
            
            int explosionRange = matrix[row][col] - 1;
            matrix[row][col] = 0;

            for (int i = 1; i <= explosionRange; i++) {
                for (int j = 0; j < 4; j++) {
                    int ny = dy[j] * i + row;
                    int nx = dx[j] * i + col;

                    if (ny >= 0 && ny < n && nx < n && nx >= 0) {
                        matrix[ny][nx] = 0;
                    }
                }
            }

            applyGravity(matrix, n);
            int count = countPair(matrix, n);
            result = max(result, count);
            
        }
    }
    return result;
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

    int result = bestCrossExplosion(n, matrix);

    cout << result;

    return 0;
}