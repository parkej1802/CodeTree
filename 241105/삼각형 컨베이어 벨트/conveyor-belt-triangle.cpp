#include <iostream>
#include <vector>
using namespace std;

void triangleBelt(int n, int t, vector<vector<int>>& matrix) {

    for (int i = 0; i < t; i++) {
        int topRight = matrix[0][n - 1];
        int middleRight = matrix[1][n - 1];
        int bottomRight = matrix[2][n - 1];

        for (int j = n - 1; j > 0; j--) {
            matrix[0][j] = matrix[0][j - 1];
            matrix[1][j] = matrix[1][j - 1];
            matrix[2][j] = matrix[2][j - 1];
        }

        matrix[0][0] = bottomRight;
        matrix[1][0] = topRight;
        matrix[2][0] = middleRight;

    }
}

int main() {
    
    int n, t;

    cin >> n >> t;

    vector<vector<int>> matrix(3, vector<int>(n));

    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < n; j++) 
            cin >> matrix[i][j];
 
    triangleBelt(n, t, matrix);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}