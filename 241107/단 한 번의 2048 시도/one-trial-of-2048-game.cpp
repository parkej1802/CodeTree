#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void moveMerge(vector<int>& line) {

    int n = line.size();
    vector<int> newLine(n, 0);

    int index = n - 1;
    int lastNum = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (line[i] != 0) {
            if (lastNum == line[i]) {
                newLine[index + 1] *= 2; 
                lastNum = 0;
            } else {
                newLine[index--] = line[i];
                lastNum = line[i];
            }
        }
    }
    line = newLine;
}

void twoZeroFourEight(vector<vector<int>>& board, char dir) {
   
    for (int i = 0; i < 4; i++) {
        vector<int> line(4);

        if (dir == 'R') {
            line = board[i];
            moveMerge(line);
            board[i] = line;
        } 
        else if (dir == 'L') {
            line = board[i];
            reverse(line.begin(), line.end());
            moveMerge(line);
            reverse(line.begin(), line.end());
            board[i] = line;
        } 
        else if (dir == 'D') {
            for (int j = 0; j < 4; j++) {
                line[j] = board[j][i];
            }
            moveMerge(line);
            for (int j = 0; j < 4; j++) {
                board[j][i] = line[j];
            }
        } 
        else if (dir == 'U') {
            for (int j = 0; j < 4; j++) {
                line[j] = board[j][i];
            }
            reverse(line.begin(), line.end());
            moveMerge(line);
            reverse(line.begin(), line.end());
            for (int j = 0; j < 4; j++) {
                board[j][i] = line[j];
            }
        }
    }
}

int main() {
    vector<vector<int>> board(4, vector<int>(4));
    
    for (int i = 0; i < 4; i++) 
        for (int j = 0; j < 4; j++) 
            cin >> board[i][j];

    char dir; 
    cin >> dir;

    twoZeroFourEight(board, dir);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}