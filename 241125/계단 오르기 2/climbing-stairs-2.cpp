#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<vector<int>> dp;
vector<int> list;

int n;

void stair() {

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {

        for (int j = 0; j <= 3; j++) {

           if (j > 0 && dp[i - 1][j - 1] != INT_MIN) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + list[i]);
            }
        

            if (i >= 2 && dp[i - 2][j] != INT_MIN) {
                dp[i][j] = max(dp[i][j], dp[i - 2][j] + list[i]);
            }

        }
    }

    cout << dp[n][3];
}

int main() {
    
    cin >> n;

    list.resize(n + 1);
    dp.resize(n + 1, vector<int>(4, INT_MIN));

    for (int i = 1; i <= n; i++) {
        cin >> list[i];
    }

    stair();
    
    return 0;
}