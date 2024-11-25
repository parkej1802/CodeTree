#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<vector<int>> dp;
vector<int> opponent;
vector<int> player;

void numCardWar() {

    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            if (player[j] > opponent[i] && dp[i - 1][j - 1] != -1) {
                dp[i][j - 1] = max(dp[i][j - 1], dp[i - 1][j - 1]);
            }

            if (player[j] < opponent[i] && dp[i - 1][j - 1] != -1) {
                dp[i - 1][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + player[j]);
            }

            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
        }
        
    }

    /*
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
    */
    
    int result = 0;

    for(int i = 0; i <= n; i++) {
        result = max(result, dp[i][n]);
        result = max(result, dp[n][i]);
    }

    cout << result;
}

int main() {
    cin >> n;

    player.resize(n + 1, 0);
    opponent.resize(n + 1, 0);
    dp.resize(n + 1, vector<int>(n + 1, -1));


    for (int i = 1; i <= n; i++) {
        cin >> opponent[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> player[i];
    }

    numCardWar();
    
    return 0;
}