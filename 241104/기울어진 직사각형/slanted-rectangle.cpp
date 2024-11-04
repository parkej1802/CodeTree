#include <iostream>
#include <vector>
using namespace std;

int tiltedRectange(int n, vector<vector<int>> matrix) {

    int count = 0;
    int result = 0;
    int boundary = n - 1;

    for (int row = 0; row < n; row++) {
        for (int col = 1; col < n; col++) {

            for (int j = 0; j < row; j++) {
                if (col - j >= 0 && row + j < n) {
                    count += matrix[row + j][col - j];
                } 
                if (boundary - row + j < n && boundary - col - j > 0) {
                    count += matrix[boundary - row + j][boundary - col - j];
                }

            }

            for (int i = 1; i < boundary - col; i++) {
                if (row + i < n && col + i < n) {
                    count += matrix[row + i][col + i] + matrix[col + i][row + i];
                }
                
                
            }
            result = max(result, count);
            count = 0;
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

    int result = tiltedRectange(n ,matrix);

    cout << result;
    return 0;
}