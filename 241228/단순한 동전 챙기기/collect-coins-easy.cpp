#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

vector<vector<int>> matrix;

struct Coin {
    int num;
    int row;
    int col;
};

vector<Coin> coins;
vector<int> list;

int n, sr, sc, er, ec;
char c;

int minWalk = INT_MAX;

void findMinWalk() {
    int newRow = sr, newCol = sc;
    int count = 0;

    for (int i = 0; i < list.size(); i++) {
        newRow = abs(coins[list[i]].row - newRow);
        newCol = abs(coins[list[i]].col - newCol);
        count += newRow + newCol;
        newRow = coins[list[i]].row;
        newCol = coins[list[i]].col;
    }

    newRow = abs(coins[list[list.size() - 1]].row - er);
    newCol = abs(coins[list[list.size() - 1]].col - ec);
    count += newRow + newCol;

    minWalk = min(count, minWalk);
}


void backTrack(int current) {
    
    if (list.size() >= 3) {
        findMinWalk();
    }

    for (int i = current; i < coins.size(); i++) {
        list.push_back(i);
        backTrack(i + 1);
        list.pop_back();
    }
}

bool compare(Coin c1, Coin c2) {
    return c1.num < c2.num;
}

int main() {

    cin >> n;

    matrix.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            if (c == '.') {
                matrix[i][j] = -1;
            }
            else if (c == 'S') {  
                matrix[i][j] = 0;
                sr = i;
                sc = j;
            }
            else if (c == 'E') {
                matrix[i][j] = 10;
                er = i;
                ec = j;
            }
            else {
                if (isdigit(c)) {
                    int coinNum = c - '0';
                    matrix[i][j] = coinNum;
                    coins.push_back({coinNum, i, j});
                }
            }
        }
    }

    sort(coins.begin(), coins.end(), compare);

    backTrack(0);
    if (minWalk == INT_MAX) {
        cout << -1;
    }
    else {
        cout << minWalk;
    }

    return 0;
}