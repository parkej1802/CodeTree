#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int getMaxCoin(int n, vector<vector<int>> matrix) {
    
    int maxCount = INT_MIN;
    int count = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (row + i < n && col + j < n) {
                        if (matrix[row + i][col + j] == 1) {
                            count++;
                            
                        }
                        
                    }
                }
                
            }
            maxCount = max(maxCount, count);
            count = 0;
        }
    }
    return maxCount;
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

    int result = getMaxCoin(n, matrix);

    cout << result;
    return 0; 
}