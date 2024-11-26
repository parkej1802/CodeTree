#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <set>

using namespace std;

int n, m, t, k, r, c, s;
char d;

vector<tuple<int, int, int, int, int>> marbles;

int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, 1, -1, 0};

int direction[128];

bool inRange(int row, int col) {
    return row > 0 && row <= n && col > 0 && col <= n;
}

bool compare(pair<int, int>& a, pair<int, int>& b) {
    if (a.second != b.second) {
        return a.second > b.second;
    }
    
    return a.first > b.first;
}

tuple<int, int, int, int, int> moveMarbles(tuple<int, int, int, int, int> marble) {

    int x, y, dir, speed, id;
    
    tie(y, x, dir, speed, id) = marble;

    for (int i = 1; i <= speed; i++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (inRange(nx, ny)) {
            x = nx;
            y = ny;
        }
        else {
            dir = (dir + 3) % 4;
            x = x + dx[dir];
            y = y + dy[dir];
        }
        
    }

    return make_tuple(y, x, dir, speed, id);
}

void checkCollision() {

    set<int> toRemove;
    vector<pair<int, int>> ids;

    for (int i = 0; i < m; i++) {
        int x, y, dir, speed, id;
        tie(y, x, dir, speed, id) = marbles[i];
        
        for (int j = 0; j < m; j++) {
            
            if (i == j) continue;

            int ny, nx, ndir, nspeed, nid;
            tie(ny, nx, ndir, nspeed, nid) = marbles[j];

            if (y == ny && x == nx) {
               
                ids.push_back({nid, nspeed});

            }
        }

        if (ids.empty()) continue;
        
        ids.push_back({id, speed});
        sort(ids.begin(), ids.end(), compare);
        
        if (ids.size() > k) {
            int index = 1;
            for (int j = k; j < ids.size(); j++) {
                int mid = ids[ids.size() - index++].first;
                toRemove.insert(mid);
            }
        }
        ids.clear();
        
    }
    
    for (int num : toRemove) {
        auto it = find_if(marbles.begin(), marbles.end(), [&](const tuple<int, int, int, int, int>& m) {
            return get<4>(m) == num;
        });
        
        marbles.erase(it);
        
    }
}



void simulate() {

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < marbles.size(); j++) {
            marbles[j] = moveMarbles(marbles[j]);
            
        }
        checkCollision();
    }

    cout << marbles.size(); 
}

int main() {
    direction['U'] = 0;
    direction['R'] = 1;
    direction['L'] = 2;
    direction['D'] = 3;
    
    cin >> n >> m >> t >> k;

    for (int i = 0; i < m; i++) {
        cin >> r >> c >> d >> s;
        marbles.push_back(make_tuple(r, c, direction[d], s, i));
    }

    simulate();



    return 0;
}