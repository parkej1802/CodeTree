#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, m, rn, rm;
int minLadder;

int dx[2] = {-1, 1};

vector<pair<int, int>> ladder;
vector<pair<int, int>> ladderRemove;

vector<vector<int>> matrix;
vector<int> result;

void print(vector<vector<int>> matrix) {
    for (int i = 0; i < rm; i++) {
        for (int j = 0; j < rn; j++) {
            cout << matrix[i][j] << " ";
        } 
        cout << endl;
    }
}

vector<int> getLadderResult(vector<pair<int, int>> ladder, vector<vector<int>> matrix) {
    int num = 1;
    vector<int> rs;

    for (int i = 0; i < rn; i+=2) {
        matrix[0][i] = num;
        rs.push_back(num++);
    }

    for (int i = 0; i < ladder.size(); i++) {
        int num = ladder[i].first * 2 - 1;
        matrix[ladder[i].second][num] = 9;
    }

    num = 1;
    for (int j = 0; j < rn; j+=2) {
        if (matrix[0][j] == num) {
            int ay = 0, ax = j;
            
            while (ay < rm - 1) {
                bool side = false;
                for (int dir = 0; dir < 2; dir++) {
                    int ny = ay;
                    int nx = dx[dir] + ax;
                    if (ny >= 0 && ny < rm && nx >= 0 && nx < rn) {
                        if (matrix[ny][nx] == 9) {
                            side = true;
                            if (dir == 0) {
                                matrix[ny + 1][nx - 1] = num;
                                matrix[ay][ax] = 0;
                                ax -= 2;
                                ay++;
                                
                            }
                            else if (dir == 1) {
                                matrix[ny + 1][nx + 1] = num;
                                matrix[ay][ax] = 0;
                                ax += 2;
                                ay++;
                            }
                        } 
                    }
                }
                if (!side) {
                    matrix[ay][ax] = 0;
                    matrix[ay + 1][ax] = num;
                    ay++;
                }
            } 
        }
        num++;
    }
    
    rs.clear();
    for (int i = 0; i < rn; i+=2) {
        rs.push_back(matrix[rm - 1][i]);
    }

    //print(matrix);

    return rs;
}


void backTracking(int current) {

    if (current == m) {
        vector<vector<int>> matrixC(rm, vector<int>(rn, 0));
        if (result == getLadderResult(ladderRemove, matrixC)) {
            minLadder = min(minLadder, (int)ladderRemove.size());
            
        }
        return;
    }

    backTracking(current + 1);

    ladderRemove.push_back(ladder[current]);
    backTracking(current + 1);
    ladderRemove.pop_back();
}

int main() {

    cin >> n >> m;

    int x, y;

    rn = n + n - 1;
    rm = 17;
    matrix.resize(rm, vector<int>(rn, 0));

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        ladder.push_back({x,y});
    }

    minLadder = ladder.size();
    
    result = getLadderResult(ladder, matrix);

    /*
    for (int num : result) {
        cout << num << endl;
    }
    */

    backTracking(0);

    cout << minLadder;

    return 0;
}