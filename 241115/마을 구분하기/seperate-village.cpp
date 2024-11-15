#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> matrix;
vector<vector<bool>> visited;
vector<int> numPeople;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int countPeople = 1;

void dfs(int row, int col) {

    visited[row][col] = true;

    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + row;
        int nx = dx[i] + col;

        if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx] && matrix[ny][nx] == 1) {
            countPeople++;
            dfs(ny, nx);
        }
    }
}

int villageNum() {
    int result = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            if (!visited[i][j] && matrix[i][j] == 1) {
                result++;
                dfs(i,j);
                numPeople.push_back(countPeople);
                countPeople = 1;
            }
        }
    }
    return result;
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


    int result = villageNum();

    cout << result << endl;

    sort(numPeople.begin(), numPeople.end());

    for (int i = 0; i < numPeople.size(); i++) {
        cout << numPeople[i] << endl;
    }


    return 0;
}