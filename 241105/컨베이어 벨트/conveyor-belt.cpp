#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> belt(int n, int t, vector<vector<int>> matrix) {

    for (int i = 0; i < t; i++) {
        int tempTopRight = matrix[0][n - 1];
        int tempBottomRight = matrix[1][n - 1];
       
        for (int j = n - 1; j > 0; j--) {
            matrix[0][j] = matrix[0][j - 1];
        }
        matrix[0][0] = tempBottomRight;

        for (int j = n - 1; j > 0; j--) {
            matrix[1][j] = matrix[1][j - 1];
        }
        matrix[1][0] = tempTopRight;

    }
    return matrix;


}

int main() {
    
    int n, t;

    cin >> n >> t;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++) 
            cin >> matrix[i][j];

    vector<vector<int>> result = belt(n, t, matrix);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}