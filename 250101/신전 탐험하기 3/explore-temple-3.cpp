#include <iostream>
#include <vector>

using namespace std;

int n, m;

vector<vector<int>> list;
vector<vector<int>> dp;
int maxResult = 0;

void getMaxValue() {

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= m; k++) {
                if (j != k) {
                    dp[i][j] = max(dp[i][j], list[i][j] + dp[i - 1][k]);
                    maxResult = max(maxResult, dp[i][j]);
                }
            }
        }
    }

    cout << maxResult;
}

int main() {
    cin >> n >> m;

    list.resize(n + 1, vector<int>(m + 1, 0));
    dp.resize(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> list[i][j];
        }
    }

    for (int i = 1; i <= m; i++) {
        dp[1][i] = list[1][i];
    }

    getMaxValue();

    return 0;
}