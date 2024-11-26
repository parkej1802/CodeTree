#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

int n, m, t, k;

struct Marble {
    int row, col;
    int d;
    int id;
    int speed;
};

unordered_map<char, int> map = {
    {'U', 0}, {'R', 1}, {'D', 2}, {'L', 3}
};

vector<Marble> marbles;

bool inRange(int row, int col) {
    return row >= 0 && row < n && col < n && col >= 0;
}

bool compare(Marble m1, Marble m2) {
    if (m1.speed != m2.speed) {
        return m1.speed > m2.speed;
    }
    return m1.id > m2.id;
}

void collision() {

    vector<vector<vector<Marble>>> matrix(n, vector<vector<Marble>>(n));

    sort(marbles.begin(), marbles.end(), compare);

    for (auto& mar : marbles) {
        matrix[mar.row][mar.col].push_back(mar);
    }

    vector<Marble> newMarble;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!matrix[i][j].empty()) {
                int size = min((int)matrix[i][j].size(), k);
                for (int a = 0; a < size; a++) {
                    newMarble.push_back(matrix[i][j][a]);
                }
            }
        }
    }

    marbles = newMarble;
}

void moveMarble() {

    for (auto& mar : marbles) {
        for (int i = 0; i < mar.speed; i++) {
            int ny = mar.row + dir[mar.d][0];
            int nx = mar.col + dir[mar.d][1];

            if (inRange(ny, nx)) {
                mar.row = ny;
                mar.col = nx;
            }
            else {
                mar.d = (mar.d + 2) % 4;
                ny = mar.row + dir[mar.d][0];
                nx = mar.col + dir[mar.d][1];
                mar.row = ny;
                mar.col = nx;
            }
        }
    }
}

void simulate() {
    moveMarble();
    collision();
}

int main() {
    cin >> n >> m >> t >> k;

    for (int i = 0; i < m; i++) {
        int tr, tc, ts;
        char td;

        cin >> tr >> tc >> td >> ts;

        marbles.push_back({ tr - 1, tc - 1, map[td], i, ts });
    }

    while (t--) {
        simulate();
    }

    cout << marbles.size();

    return 0;
}