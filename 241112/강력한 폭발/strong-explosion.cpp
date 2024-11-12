#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> matrix;
vector<vector<int>> copyMatrix;

vector<pair<int, int>> bombPos;
vector<int> comb;

int case1Y[4] = {-2, 2, 1, -1};

int case2X[4] = {-1, 1, 0, 0};
int case2Y[4] = {0, 0, -1, 1};

int case3X[4] = {-1, -1, 1, 1};
int case3Y[4] = {-1, 1, -1, 1};


int maxNum = 0;

int bombNum() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                count++;
                bombPos.push_back({i, j});
            }
        }
    }
    matrix = copyMatrix;
    return count;
}

void explosion(int current, int bombCount, int caseNum) {

    if (bombCount == comb.size()) {

        for (int j = 0; j < bombCount; j++) {
            if (comb[j] == 1) {
                for (int i = 0; i < 4; i++) {
                    int ny = case1Y[i] + bombPos[j].first;
                    int nx = 0;
                    if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
                        matrix[ny][nx] = 1; 
                    }
                }
            }
            if (comb[j] == 2) {
                for (int i = 0; i < 4; i++) {
                    int ny = case2Y[i] + bombPos[j].first;
                    int nx = case2X[i] + bombPos[j].second;
                    if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
                        matrix[ny][nx] = 1; 
                    }
                }
            }

            if (comb[j] == 3) {
                for (int i = 0; i < 4; i++) {
                    int ny = case3Y[i] + bombPos[j].first;
                    int nx = case3X[i] + bombPos[j].second;
                    if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
                        matrix[ny][nx] = 1; 
                    }
                }
            }
        }
        int bombN = bombNum();
        maxNum = max(bombN, maxNum);
        return;
    }

    for (int i = 1; i <= 3; i++) {
        comb.push_back(i);
        explosion(current + 1, bombCount, caseNum);
        comb.pop_back();
    }
}

int main() {

    cin >> n;

    matrix.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    copyMatrix = matrix;
    int bombCount = bombNum();
    explosion(1, bombCount, 1);
    cout << maxNum;
    return 0;
}