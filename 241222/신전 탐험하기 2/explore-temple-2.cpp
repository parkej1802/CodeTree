#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<vector<int>>> dp;
vector<vector<int>> list;

void explor() {

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j != k) {
                    for (int m = 0; m < 3; m++) {
                        dp[i][j][m] = max(dp[i][j][m], list[i][j] + dp[i - 1][k][m]);
                    }
                }
            }
        }
    }
    
    int maxResult = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != j) {
                maxResult = max(maxResult, dp[n - 1][j][i]);
            }
        }
    }

    cout << maxResult;
}

int main() {
    cin >> n;

    dp.resize(n, vector<vector<int>>(3, vector<int>(3, 0)));
    list.resize(n, vector<int>(3));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> list[i][j];
        }
    } 


    for (int i = 0; i < 3; i++) {
        dp[0][i][i] = list[0][i];
    }
    

    explor();

    return 0;
}