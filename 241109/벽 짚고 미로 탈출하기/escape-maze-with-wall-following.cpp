#include <iostream>
#include <vector>
using namespace std;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int getMazeTime(int n, int ro, int co, vector<vector<char>> matrix) {
    
    bool escape = false;
    int time = 0;

    int row = ro - 1;
    int col = co - 1;

    int dir = 0;
    
    while (!escape) {
        int rightDir = (dir + 3) % 4;

        int rightRow = row + dy[rightDir];
        int rightCol = col + dx[rightDir];

        if (rightRow < 0 || rightRow >= n || rightCol < 0 || rightCol >= n || matrix[rightRow][rightCol] == '#') {
            int nextRow = row + dy[dir];
            int nextCol = col + dx[dir];

            if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= n) {
                time++;
                escape = true;
                break;
            }
            if (matrix[nextRow][nextCol] != '#') {
                row = nextRow;
                col = nextCol;
                time++;
            } 
            else {
                dir = (dir + 1) % 4;
            }
        } 
        else {
            dir = rightDir;
            row += dy[dir];
            col += dx[dir];
            time++;
        }

        if (time >  n * n) {
            return -1;
        }
    }

    return time;
}

int main() {
    
    int n, col, row;

    cin >> n >> row >> col;
    
    vector<vector<char>> matrix(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int result = getMazeTime(n, row, col, matrix);

    cout << result;

    return 0;
}