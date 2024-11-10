#include <iostream>
#include <vector>
using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, -1, 0, 1};

int pinBall(int n, vector<vector<int>> matrix) {
    int maxTime = 0;

    int row = 0;
    int col = 0;
    int start = 0;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            start = 0;
            int dirNum = i;
            int time = 0;
            bool escape = false;

            if (i == 0) {
                row = 0;
                col = j;
            }
            else if (i == 1) {
                row = j;
                col = n - 1;
            }
            else if (i == 2) {
                row = n - 1;
                col = j;
            }
            else if (i == 3) {
                row = j;
                col = 0;
            }

            while(!escape) {
                int ny = dy[dirNum] * start + row;
                int nx = dx[dirNum] * start + col;
                start = 1;
                time++;

                if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
                    if (matrix[ny][nx] == 1) {
                        if (dirNum == 0) {
                            dirNum = 1;
                        }
                        else if (dirNum == 1) {
                            dirNum = 0;
                        }
                        else if (dirNum == 2) {
                            dirNum = 3;
                        }
                        else if (dirNum == 3) {
                            dirNum = 2;
                        }   
                    }
                    else if (matrix[ny][nx] == 2) {
                        if (dirNum == 0) {
                            dirNum = 3;
                        }
                        else if (dirNum == 1) {
                            dirNum = 2;
                        }
                        else if (dirNum == 2) {
                            dirNum = 1;
                        }
                        else if (dirNum == 3) {
                            dirNum = 0;
                        }
                    }
                    row = ny;
                    col = nx;
                }
                else {
                    maxTime = max(time, maxTime);
                    escape = true;
                }
            }
        }    
    }
    return maxTime;
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

    int result = pinBall(n, matrix);

    cout << result;
    return 0;
}