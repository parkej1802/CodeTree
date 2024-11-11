#include <iostream>
#include <vector>
using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

struct Position {
    int hasMarble;
    char dir;
    int weight;
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

pair<int, int> getMarbleNum(int t, int n, int m, vector<pair<int, int>> pos, vector<char> dir, vector<int> weight) {

    vector<vector<Position>> matrix(n, vector<Position>(n, {0, ' ', 0}));

    for (int i = 0; i < pos.size(); i++) {
        matrix[pos[i].first - 1][pos[i].second - 1] = {1, dir[i], weight[i]};
    }

    int r, c, dirNum;
    char d;
    int weig = 0;

    for (int time = 0; time < t; time++) {
        vector<vector<Position>> tempMatrix(n, vector<Position>(n, {0, ' ', 0}));
        weig = 0;
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
                    for (int a = 0; a < tempMatrix[ny][nx].hasMarble; a++) {
                        if (tempMatrix[row][col].weight >= weig) {
                            weig = tempMatrix[row][col].weight;
                            d = tempMatrix[row][col].dir;
                        }
                    }
                    tempMatrix[ny][nx].weight += matrix[row][col].weight;
                    tempMatrix[ny][nx].dir = d;
                }
            }
        }
        for (int e = 0; e < n; e++) {
            for (int f = 0; f < n; f++) {
                if (tempMatrix[e][f].hasMarble >= 2) {
                    tempMatrix[e][f].hasMarble = 1;
                }
            }   
        }
        matrix = tempMatrix;
    }

    int result = 0;
    int maxWeight = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j].hasMarble == 1) {
                result += matrix[i][j].hasMarble;
                maxWeight = max(maxWeight, matrix[i][j].weight);
            }
        }
    }

    return {result, maxWeight};
    
}

int main() {
    
    int t, n, m, r, c, w;
    char d;
    
    cin >> n >> m >> t;

    vector<pair<int, int>> pos;
    vector<char> dir;
    vector<int> weight;

    for (int i = 0; i < m; i++) {
        cin >> r >> c >> d >> w;
        pos.push_back({r, c});
        dir.push_back(d);
        weight.push_back(w);
    }

    pair<int, int> result = getMarbleNum(t, n, m, pos, dir, weight);

    cout << result.first << " " << result.second;

    return 0;
}