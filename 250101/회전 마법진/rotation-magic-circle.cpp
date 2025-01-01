#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1987654321

int n;
string a, b;
vector<vector<int>> dp;

int main() {
    cin >> n >> a >> b;

    a = " " + a;
    b = " " + b;

    dp.resize(n + 1, vector<int>(10, INF));

    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (dp[i][j] == INF) continue;

            int cur = (a[i + 1] - '0' + j) % 10;
            int target = (b[i + 1] - '0');

            int cost = (target - cur + 10) % 10;
            int nj = (j + cost) % 10;
            dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j] + cost);

            cost = (cur - target + 10) % 10;
            nj = j;
            dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j] + cost);
        }
    }

    int ans = INF;
    for (int j = 0; j <= 9; j++) {
        ans = min(ans, dp[n][j]);
    }

    cout << ans;
    
    return 0;
}
