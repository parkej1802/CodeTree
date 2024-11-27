#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

int t, n, x, y, w;
int minRow, minCol, maxRow, maxCol;
int lastCollision = 0;

char d;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct Marble {
    int row, col;
    int weight;
    int d;
    int id;
    bool out;
};

vector<Marble> marbles;

map<pair<int, int>, vector<Marble>> hashPos;

unordered_map<char, int> mapDir = {
    {'U', 0}, {'R', 1}, {'D', 2}, {'L', 3}
};

bool inRange(int row, int col) {
    return row >= minRow && row <= maxRow && col >= minCol && col <= maxCol;
}

bool compare(Marble m1, Marble m2) {
    if (m1.weight != m2.weight) {
        return m1.weight > m2.weight;
    }
    return m1.id > m2.id;
}

int collision(int time) {

    sort(marbles.begin(), marbles.end(), compare);
    
    hashPos.clear();
    
    for (auto& mar : marbles) {
        hashPos[{mar.row, mar.col}].push_back(mar);
        //cout << mar.row << " " << mar.col << endl;
    }

    vector<Marble> newMarble;

    //cout << hashPos.size() << endl;

    for (auto& h : hashPos) {
        pair<int, int> pos = h.first;
        vector<Marble>& vm = h.second;

        if (vm.size() > 1) {
            lastCollision = time;
            
            //cout << "collision" << endl;

            for (int i = 1; i < vm.size(); i++) {
                vm[i].out = true;
            }
        }

        newMarble.push_back(vm[0]);
    }
    
    marbles = newMarble;

    return lastCollision;
}

void moveMarble() {

    vector<Marble> newMarble;

    for (auto& mar : marbles) {
        int ny = mar.row + dir[mar.d][0];
        int nx = mar.col + dir[mar.d][1];

        if (inRange(ny, nx) && !mar.out) {
            mar.row = ny;
            mar.col = nx;
            newMarble.push_back(mar);
        }
        else {
            mar.out = true;
        }
    }
    marbles = newMarble;
}

bool collisionFinished() {

    for (auto mar : marbles) {
        if (!mar.out) {
            return false;
        }
    }

    return true; 
}

void calculateRange() {
    minRow = 4000;
    minCol = 4000;
    maxRow = 0;
    maxCol = 0;

    for (auto& mar : marbles) {
        minRow = min(mar.row, minRow);
        minCol = min(mar.col, minCol);
        maxRow = max(mar.row, maxRow);
        maxCol = max(mar.col, maxCol);
    }
}

void simulate() {
    
    int time = 0;

    calculateRange();
    
    int lc = 0;
    
    while (!collisionFinished()) {
        moveMarble();
        time++;
        lc = collision(time);
    }
        
    if (lc == 0) {
        cout << -1 << endl;;
    }
    else {
        cout << lc << endl;
    }
    
}

int main() {
    cin >> t;

    vector<int> result;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> y >> x >> w >> d;
            marbles.push_back({(x + 1000) * 2, (y + 1000) * 2, w, mapDir[d], i, false});
        }
        simulate();
        marbles.clear();
        hashPos.clear();
        lastCollision = 0;
    }

    return 0;
}