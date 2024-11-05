#include <iostream>
#include <vector>
using namespace std;

void move(int m, int row, vector<vector<int>>& matrix, char& d) {

    if (d == 'L') {
        int rightSide = matrix[row][m - 1];
        for (int j = m - 1; j > 0; j--) {
            matrix[row][j] = matrix[row][j - 1];
        }
        matrix[row][0] = rightSide;
        d = 'R';
    }
    else {
        int leftSide = matrix[row][0];
        for (int j = 0; j < m - 1; j++) {
            matrix[row][j] = matrix[row][j + 1];
        }
        matrix[row][m - 1] = leftSide;
        d = 'L';
    }
}

void oneDimensionalWind(int n, int m, vector<vector<int>>& matrix, vector<int> r, vector<char> d, int q) {

    for (int numWind = 0; numWind < q; numWind++) {

        int row = r[numWind] - 1;
        char tempD = (d[numWind] == 'L') ? 'R' : 'L';

        move(m, row, matrix, d[numWind]);

        for (int i = r[numWind]; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i - 1 >= 0) {
                    if (matrix[i - 1][j] == matrix[i][j]) {
                        move(m, i, matrix, d[numWind]);
                        break;
                    }
                }
            }
        }

        d[numWind] = tempD;
        
        if (row - 1 >= 0) {
            for (int i = row - 1; i >= 0; i--) {
                for (int j = 0; j < m; j++) {
                    if (i + 1 < n) {
                        if (matrix[i + 1][j] == matrix[i][j]) {
                            move(m, i, matrix, d[numWind]);
                            break;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int n, m, q;
    char d; 

    cin >> n >> m >> q;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];


    vector<int> row;
    vector<char> dir;
    for (int i = 0; i < q; i++) {
        int r;
        char d;
        cin >> r >> d;
        row.push_back(r);
        dir.push_back(d);
    }

    oneDimensionalWind(n, m, matrix, row, dir, q);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}