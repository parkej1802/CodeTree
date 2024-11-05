#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int calcRecAreaSum(int x, int y, int nx, int ny, vector<vector<int>> matrix) {
    
    int sum = 0;

    for (; x <= nx; x++) {
        for (; y <= ny; y++) {
            sum += matrix[x][y];
        }
    }

    return sum;
}
int twoRectangleSum(int n, int m, vector<vector<int>> matrix) {

    int globalMaxSum = INT_MIN;
    for (int i1 = 0; i1 < n; i1++) {
        for (int j1 = 0; j1 < n; j1++) {
            for (int down1 = i1; down1 < n; down1++) {
                for (int right1 = j1; right1 < n; right1++) {
                    
                    int firstSum = calcRecAreaSum(i1, j1, down1, right1, matrix);
                    
                    for (int i2 = 0; i2 < n; i2++) {
                        for (int j2 = 0; j2 < n; j2++) {
                            if (i2 > down1 || j2 > down1 || i2 > right1 || j2 > right1) {
                                for (int down2 = i2; down2 < n; down2++) {
                                    for (int right2 = j2; right2 < n; right2++) {
                                        if (!((i1 <= down2 && down1 >= i2) && (j1 <= right2 && right1 >= j2))) {
                                            int secondSum = calcRecAreaSum(i2, j2, down2, right2, matrix);
                                            globalMaxSum = max(globalMaxSum, firstSum + secondSum);
                                        }
                                    }
                                }
                            }
                            
                        }
                    }
                 }
             }
        }
    }

    return globalMaxSum;
}


int main() {
    int n, m;

    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> matrix[i][j];
        
    
    int result = twoRectangleSum(n, m, matrix);

    cout << result;
    
     return 0;
}