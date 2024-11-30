#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> matrix;
vector<vector<bool>> visited;
vector<pair<int, int>> list;
unordered_map<int, int> mapY;
unordered_map<int, int> mapX;


int n;
int maxNum = 0;

void maxSum() {
    int sum = 0;
    for (auto p : list) {
        sum += matrix[p.first][p.second];
    }
    maxNum = max(maxNum, sum);
}


bool check() {
    mapY.clear();
    mapX.clear();

    for (auto p : list) {
        mapY[p.first]++;
        mapX[p.second]++;
        if (mapY[p.first] > 1) {
            return false;
        }
        if (mapY[p.second] > 1) {
            return false;
        }
    }
    
    return true;
}

void backTrack(int current, int count) {

    if (current == n) {
        if (check()) {
            maxSum();
        }
       
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = count; j < n; j++) {
            if (visited[i][j]) continue;

            visited[i][j] = true;
            list.push_back({i, j});
            backTrack(current + 1, j + 1);
            list.pop_back();
            visited[i][j] = false;
        }
    }
}

int main() {
    
    cin >> n;

    matrix.resize(n, vector<int>(n));
    visited.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    backTrack(0, 0);

    cout << maxNum;
    return 0;
}