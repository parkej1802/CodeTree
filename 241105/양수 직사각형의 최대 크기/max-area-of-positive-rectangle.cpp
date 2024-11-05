#include <iostream>
#include <vector>

using namespace std;

int calRecArea(int startX, int startY, int endX, int endY, vector<vector<int>> matrix) {

    for (int i = startX; i <= endX; i++) {
        for (int j = startY; j <= endY; j++) {
            if (matrix[i][j] <= 0) {
                return 0;
            }
        }
    }
    
    return (endX - startX + 1) * (endY - startY + 1);
}

int getMaxRecArea(int n, int m, vector<vector<int>> matrix) {
    
    int maxArea = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int down = i; down < n; down++) {
                for (int right = j; right < m; right++) {
                    int valid = calRecArea(i, j, down, right, matrix);
                    if (valid != 0) {
                        maxArea = max(valid, maxArea);
                    }
                } 
            }
        }
    }
    return maxArea;
}

int main() {
    
    int n, m;

    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    
    int result = getMaxRecArea(n, m, matrix);

    cout << result;

    return 0;
}