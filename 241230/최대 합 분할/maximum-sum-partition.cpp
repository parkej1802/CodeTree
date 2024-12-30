#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define OFFSET 100000

using namespace std;

int n, m = 0;
vector<int> list;

vector<vector<int>> dp(2, vector<int>(200002, INT_MIN));

void Update(int cur, int j, int prev, int pj, int val) {
    if (pj < -m || pj > m || dp[prev][pj + OFFSET] == INT_MIN) return;
    dp[cur][j + OFFSET] = max(dp[cur][j + OFFSET], dp[prev][pj + OFFSET] + val);
}

int main() {
    cin >> n;
    list.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> list[i];
        m += list[i];
    }

    dp[0][0 + OFFSET] = 0;

    for (int i = 1; i <= n; i++) {
        int cur = i % 2, prev = (i - 1) % 2;

        fill(dp[cur].begin(), dp[cur].end(), INT_MIN);

        for (int j = -m; j <= m; j++) {
            Update(cur, j, prev, j - list[i], list[i]); 
            Update(cur, j, prev, j + list[i], 0);
            Update(cur, j, prev, j, 0);
        }
    }

    cout << dp[n % 2][0 + OFFSET];
    return 0;
}
