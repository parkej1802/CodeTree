#include <iostream>
#include <vector>
using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int top = 1;
int bottom = 6;
int left1 = 4;
int right1 = 3;
int front = 2;
int back = 5;

int rollLeft(int diceTopNum) {
    top = right1;
    right1 = bottom;
    bottom = left1;
    left1 = diceTopNum;
    return bottom;
}

int rollRight(int diceTopNum) {
    top = left1;
    left1 = bottom;
    bottom = right1;
    right1 = diceTopNum;
    return bottom;
}

int rollUp(int diceTopNum) {
    top = front;
    front = bottom;
    bottom = back;
    back = diceTopNum;
    return bottom;
}

int rollDown(int diceTopNum) {
    top = back;
    back = bottom;
    bottom = front;
    front = diceTopNum;
    return bottom;
}

void function(vector<vector<int>>& matrix, int n, int dirNum, int& row, int& col, int& topNum) {
    int nextRow = row + dy[dirNum];
    int nextCol = col + dx[dirNum];

    if (nextRow < n && nextRow >= 0 &&  nextCol < n && nextCol >= 0) {
        int num;
        if (dirNum == 2) {
            num = rollLeft(topNum);
        }
        if (dirNum == 3) {
            num = rollRight(topNum);
        }
        if (dirNum == 0) {
            num = rollUp(topNum);
        }
        if (dirNum == 1) {
            num = rollDown(topNum);
        }
        matrix[nextRow][nextCol] = num;
        topNum = num;
        row = nextRow;
        col = nextCol;
    }
} 

int rollingDice(int n, int m, int r, int c, vector<char> dir) {

    int row = r - 1;
    int col = c - 1;

    int diceTop = 1;

    int result = 0;

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    matrix[row][col] = 7 - diceTop;

    for (int i = 0; i < m; i++) {
        
        if (dir[i] == 'L') {
            function(matrix, n, 2, row, col, diceTop);
        }
        else if (dir[i] == 'R') {
            function(matrix, n, 3, row, col, diceTop);
        }
        else if (dir[i] == 'U') {
            function(matrix, n, 0, row, col, diceTop);
        }
        else if (dir[i] == 'D') {
            function(matrix, n, 1, row, col, diceTop);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result += matrix[i][j];
        }
    }
    return result;
}
int main() {
    int n, m, r, c;

    cin >> n >> m >> r >> c;

    vector<char> dir; 
    char d;
    for (int i = 0; i < m; i++) {
        cin >> d;
        dir.push_back(d);
    }

    int result = rollingDice(n, m, r, c, dir);

    cout << result;

    return 0;
}