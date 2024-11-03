#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int checkRowCol(int n, int m, vector<vector<int>> matrix) {

    int result = 0;
    unordered_map<int, int> mapX;
    unordered_map<int, int> mapY;

    for (int row = 0; row < n; row++) {
        
        for (int col = 0; col < n; col++) {
            mapX[matrix[row][col]]++;
            mapY[matrix[col][row]]++;
        }
        for (int i = 0; i < mapX.size(); i++) {
            if (mapX[matrix[row][i]] == m) {
                result++;
                break;
            }
        }
        for (int j = 0; j < mapY.size(); j++) {
            if (mapY[matrix[j][row]] == m) {
                result++;
                break;
            }
        }

        
        mapX.clear();
        mapY.clear();
    }
    return result;
}

int main() {
    
    int n, m;

    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int result = checkRowCol(n, m, matrix);

    cout << result;
    return 0;
}