#include <iostream>
#include <vector>
using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

struct Position {
    int hasMarble;
    char dir;
};

void print(vector<vector<Position>> matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j].hasMarble << " ";
        }
        cout << endl;
    }
    cout << "----------------------------------" << endl;
}

int getMarbleNum(int t, int n, int m, vector<pair<int, int>> pos, vector<char> dir) {

    vector<vector<Position>> matrix(n, vector<Position>(n, {0, ' '}));
    
    for (int i = 0; i < pos.size(); i++) {
        matrix[pos[i].first - 1][pos[i].second - 1] = {1, dir[i]};
    }

    int r, c, dirNum;
    char d;

    for (int time = 0; time < 1000; time++) {
        vector<vector<Position>> tempMatrix(n, vector<Position>(n, {0, ' '}));

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col].hasMarble == 1) {
                    d = matrix[row][col].dir;
                    if (d == 'L') {
                        dirNum = 2;
                    }
                    else if (d == 'R') {
                        dirNum = 3;
                    }
                    else if (d == 'U') {
                        dirNum = 0;
                    }
                    else if (d == 'D') {
                        dirNum = 1;
                    }
                    int ny = dy[dirNum] + row;
                    int nx = dx[dirNum] + col;

                    if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
                        if (d == 'L') d = 'R';
                        else if (d == 'R') d = 'L';
                        else if (d == 'U') d = 'D';
                        else if (d == 'D') d = 'U';
                        ny = row;
                        nx = col;
                    }

                    tempMatrix[ny][nx].hasMarble += 1;
                    tempMatrix[ny][nx].dir = d;
                }
            }
        }

        for (int e = 0; e < n; e++) {
            for (int f = 0; f < n; f++) {
                if (tempMatrix[e][f].hasMarble >= 2) {
                    tempMatrix[e][f].hasMarble = 0;
                }
            }   
        }
        matrix = tempMatrix;
    }

    int result = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result += matrix[i][j].hasMarble;
        }
    }
    

    return result;
    
}

int main() {
    
    int t, n, m, r, c;
    char d;

    cin >> t;

    vector<int> numMarble;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> pos;
        vector<char> dir;

        for (int i = 0; i < m; i++) {
            cin >> r >> c >> d;
            pos.push_back({r, c});
            dir.push_back(d);
        }

        int result = getMarbleNum(t, n, m, pos, dir);
        numMarble.push_back(result);
    }

    for (int num : numMarble) {
        cout << num << endl;
    }

    return 0;
}