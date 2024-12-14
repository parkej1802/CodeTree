#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<vector<int>>> dp;
int MOD = 1e9 + 7;

void gameStudio() {
    dp[1][0][0] = 1;
    dp[1][0][1] = 1;
    dp[1][1][0] = 1;

    for (int i = 2; i <= n; ++i) {
        for (int t = 0; t < 3; ++t) {
            for (int b = 0; b < 3; ++b) {
                if (dp[i - 1][t][b] > 0) {
                    dp[i][t][0] = (dp[i][t][0] + dp[i - 1][t][b]) % MOD;

                    if (b < 2) {
                        dp[i][t][b + 1] = (dp[i][t][b + 1] + dp[i - 1][t][b]) % MOD;
                    }

                    if (t < 2) {
                        dp[i][t + 1][0] = (dp[i][t + 1][0] + dp[i - 1][t][b]) % MOD;
                    }
                }
            }
        }
    }

    int result = 0;
    for (int t = 0; t < 3; ++t) {
        for (int b = 0; b < 3; ++b) {
            result = (result + dp[n][t][b]) % MOD;
        }
    }

    cout << result;
}

int main() {
    cin >> n;

    dp.resize(n + 1, vector<vector<int>>(3, vector<int>(3, 0)));

    gameStudio();

    return 0;
}