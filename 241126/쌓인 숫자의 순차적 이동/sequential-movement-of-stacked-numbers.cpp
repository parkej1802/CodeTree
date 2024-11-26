#include <iostream>
#include <vector>

using namespace std;

int n, m;

int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

vector<vector<int>> matrix;
vector<vector<vector<int>>> order;
vector<int> list;

bool inRange(int row, int col) {
    return row >= 0 && row < n && col < n && col >= 0;
}

void moveNum() {

    for (int i = 0; i < m; i++) { 
        bool find = false;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                for (int z = 0; z < order[row][col].size(); z++) {
                    if (order[row][col][z] == list[i]) { 
                        find = true;
                        int maxNum = 0; 
                        int maxRow = row, maxCol = col;

                        for (int dir = 0; dir < 8; dir++) {
                            int ny = row + dy[dir];
                            int nx = col + dx[dir];

                            if (inRange(ny, nx) && matrix[ny][nx] != 0) {
                                if (matrix[ny][nx] > maxNum) {
                                    maxNum = matrix[ny][nx];
                                    maxRow = ny;
                                    maxCol = nx;
                                }
                            }
                        }
                        matrix[row][col] = 0;

                        if (maxRow != row || maxCol != col) {
                            order[maxRow][maxCol].insert(order[maxRow][maxCol].end(), order[row][col].begin() + z, order[row][col].end());
                            order[row][col].erase(order[row][col].begin() + z, order[row][col].end());
                        }
                     
                        break;
                    }
                }
                if (find) {
                    break;
                }
            }
            if (find) {
                break;
            }
        }
    }
}

int main() {

    cin >> n >> m;

    matrix.resize(n, vector<int>(n));
    order.resize(n, vector<vector<int>>(n));
    list.resize(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            order[i][j].push_back(matrix[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> list[i];
    }


    moveNum();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (order[i][j].empty()) {
                cout << "None" << endl;
            }
            else {
                for (int z = order[i][j].size() - 1; z << order[i][j].size() >= 0; z--) {
                    cout << order[i][j][z] << " ";
                }
                cout << endl;
            }
        }
    }


    return 0;
}