#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s, t;

    cin >> s >> t;

    int n = s.length();
    int m = t.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } 
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int sLength = n + m - dp[n][m];

    cout << sLength;

    return 0;
}
