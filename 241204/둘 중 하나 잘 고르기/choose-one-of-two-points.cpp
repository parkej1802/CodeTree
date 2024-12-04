#include <iostream>
#include <vector>

using namespace std;

vector<int> red;
vector<int> blue;
vector<vector<int>> dp;

int n;

void chooseBestCard() {

    dp[0][0] = 0;

    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 0; j <= n; j++) {
            if (j > i) break;
                
            if (j > 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + red[i - 1]);
            }

            if (i - j > 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + blue[i - 1]);
            }
        }
    }

    cout << dp[2 * n][n];
}

int main() {
    cin >> n; 

    red.resize(2 * n);
    blue.resize(2 * n);

    dp.resize(2 * n + 1, vector<int>(n + 1, -1));

    for (int i = 0; i < 2 * n; i++) {
        cin >> red[i] >> blue[i];
    }

    chooseBestCard();
    
    return 0;
}