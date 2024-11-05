#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<vector<int>> twoDimensionalWind(int n, int m, vector<vector<int>>& matrix, int q, vector<int> r1, vector<int> c1, vector<int> r2, vector<int> c2) {
    
    vector<vector<int>> initialMatrix = matrix;

    for (int numWind = 0; numWind < q; numWind++) {
        int topLeftY = r1[numWind] - 1;
        int topLeftX = c1[numWind] - 1;
        int bottomRightY = r2[numWind] - 1;
        int bottomRightX = c2[numWind] - 1;

        int temp = matrix[topLeftY][topLeftX];

        for (int i = topLeftY; i < bottomRightY; i++) {
            matrix[i][topLeftX] = matrix[i + 1][topLeftX];
        }

        for (int i = topLeftX; i < bottomRightX; i++) {
            matrix[bottomRightY][i] = matrix[bottomRightY][i + 1];
        }

        for (int i = bottomRightY; i > topLeftY; i--) {
            matrix[i][bottomRightX] = matrix[i - 1][bottomRightX];
        }

        for (int i = bottomRightX; i > topLeftX + 1; i--) {
            matrix[topLeftY][i] = matrix[topLeftY][i - 1];
        }

        matrix[topLeftY][topLeftX + 1] = temp;

        for (int i = topLeftY; i <= bottomRightY; i++) {
            for (int j = topLeftX; j <= bottomRightX; j++) {
                int sum = matrix[i][j];
                int count = 1;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = dx[dir] + j;
                    int ny = dy[dir] + i;

                    if (nx < m && ny < n && nx >= 0 && ny >= 0) {
                        sum += matrix[ny][nx];
                        count++;
                    }
                }
                int result = sum / count;
                initialMatrix[i][j] = result;
            }
        }
        matrix = initialMatrix;
    }
    return initialMatrix;
}

int main() {
    int n, m, q, r1, c1, r2, c2;

    cin >> n >> m >> q;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> x1;
    vector<int> x2;
    vector<int> y1;
    vector<int> y2;
    for (int i = 0; i < q; i++) {
        cin >> r1 >> c1 >> r2 >> c2;
        x1.push_back(r1);
        x2.push_back(r2);
        y1.push_back(c1);
        y2.push_back(c2);
    }
    

    vector<vector<int>> result = twoDimensionalWind(n, m, matrix, q, x1, y1, x2, y2);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}