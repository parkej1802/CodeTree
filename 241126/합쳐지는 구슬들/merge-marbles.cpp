#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n, m, t;

struct Marble{
    int row;
    int col;
    int d;
    int weight;
    int id;
};

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

unordered_map<char, int> map = {
    {'U', 0}, {'R', 1}, {'D', 2}, {'L', 3}
};

vector<Marble> marbles;

bool inRange(int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < n;
}

void moveMarble() {

    for (auto& mar : marbles) {

        int ny = mar.row + dir[mar.d][0];
        int nx = mar.col + dir[mar.d][1];

        if (inRange(ny, nx)) {
            mar.row = ny;
            mar.col = nx;
        }
        else {
            mar.d = (mar.d + 2) % 4;
        }
    }
}

bool compare(Marble m1, Marble m2) {
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
            if (matrix[i][j].size() > 0) {
                for (int k = 1; k < matrix[i][j].size(); k++) {
                    matrix[i][j][0].weight += matrix[i][j][k].weight;
                }
                // 맨밑에 깔려있는 마블에 위에 마블들의 무게를 더해준다.

                // 맨밑에 깔려있는 마블만 뉴 마블로 저장해둔다.
                newMarble.push_back(matrix[i][j][0]);
            }
        }
    }
    marbles = newMarble;
}

void simulate() {

    moveMarble();
    collision();
}

int main() {

    cin >> n >> m >> t;

    for (int i = 0; i < m; i++) {
        int tr, tc, tw;
        char td;
        cin >> tr >> tc >> td >> tw;
        marbles.push_back({tr - 1, tc - 1, map[td], tw, i});
    }

    while (t--) {
        simulate();
    }

    int maxWeight = 0;
    for (auto& hea : marbles) {
        maxWeight = max(maxWeight, hea.weight);
    }

    cout << marbles.size() << " " << maxWeight;

    return 0;
}