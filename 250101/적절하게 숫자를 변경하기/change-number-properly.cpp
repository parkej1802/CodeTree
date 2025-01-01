#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
vector<int> list;
vector<vector<vector<int>>> dp;

int main() {
    cin >> n >> m;

    list.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> list[i];
    }

    dp.resize(n + 1, vector<vector<int>>(m + 1, vector<int>(5, INT_MIN)));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 1; k <= 4; k++) {
                dp[i][j][k] = INT_MIN;
            }
        }
    }

    for (int k = 1; k <= 4; k++) {
        dp[1][0][k] = (list[1] == k);
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 1; k <= 4; k++) {
                for (int l = 1; l <= 4; l++) {
                    if (l == k) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][l] + (list[i] == k));
                    }
                    if (l != k && j > 0) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][l] + (list[i] == k));
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= m; j++) {
        for (int k = 1; k <= 4; k++) {
            ans = max(ans, dp[n][j][k]);
        }
    }

    cout << ans;
}
