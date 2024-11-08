#include <iostream>
#include <vector>
#include <stack>
using namespace std;

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

void explodeBombs(vector<vector<int>>& matrix, int n, int m) {

    for (int col = 0; col < n; col++) {
        stack<int> stk;
        int count = 1;
        
        for (int row = 0; row < n; row++) {
            if (!stk.empty() && stk.top() == matrix[row][col]) {
                count++;
            } 
            else {
                if (count >= m) {
                    for (int i = 0; i < count; i++) {
                        stk.pop();
                    }
                }
                count = 1;
            }
            stk.push(matrix[row][col]);
        }
        
        if (count >= m) {
            for (int i = 0; i < count; i++) {
                stk.pop();
            }
        }
        
        int idx = n - 1;

        while (!stk.empty()) {
            matrix[idx--][col] = stk.top();
            stk.pop();
        }

        while (idx >= 0) {
            matrix[idx--][col] = 0;
        }
        
    }
}


void rotateMatrix(vector<vector<int>>& matrix, int n) {

    vector<vector<int>> rotated(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotated[j][n - i - 1] = matrix[i][j];
        }
    }
    matrix = rotated;
}

int twoDimensionalExplosionGame(int n, int m, int k, vector<vector<int>>& matrix) {

    for (int times = 0; times < k; times++) {
        explodeBombs(matrix, n, m);
        rotateMatrix(matrix, n);
        applyGravity(matrix, n);
    }
    
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                result++;
            }
        }
    }
    
    return result;
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

    int result = twoDimensionalExplosionGame(n, m, k, matrix);

    cout << result;

    
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    } 
    */
    

    return 0;
}