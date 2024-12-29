#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int dynamicDist(string &a, string &b) {
    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i)  {
        dp[i][0] = i;
    }
    for (int j = 1; j <= m; ++j) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } 
            else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
    }

    return dp[n][m];
}

int main() {
    string a, b;

    cin >> a >> b;

    cout << dynamicDist(a, b);

    return 0;
}
