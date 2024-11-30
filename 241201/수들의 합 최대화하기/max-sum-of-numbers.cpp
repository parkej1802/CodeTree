#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> matrix;
vector<bool> visited;
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

void backTrack(int current, int count) {

    if (current == n) {
        maxSum();
        return;
    }

    for (int i = count; i < n; i++) {
       
        if (visited[i]) continue;

        visited[i] = true;
        list.push_back({current, i});
        backTrack(current + 1, 0);
        list.pop_back();
        visited[i] = false;
        
    }
}

int main() {
    
    cin >> n;

    matrix.resize(n, vector<int>(n));
    visited.resize(n, false);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    backTrack(0, 0);

    cout << maxNum;

    return 0;
}