#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> list;
vector<vector<int>> dp;

void rightEquation() {
    dp[0][list[0] + 20] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = -20; j <= 20; j++) {
            int index = j + 20;

            if (dp[i - 1][index] > 0) {
                int add = j + list[i];
                int sub = j - list[i];

                if (add >= -20 && add <= 20) {
                    dp[i][add + 20] += dp[i - 1][index];
                }
                if (sub >= -20 && sub <= 20) {
                    dp[i][sub + 20] += dp[i - 1][index];
                }
            }
        }
    }
    cout << dp[n][m + 20];
}

int main() {
    cin >> n >> m;

    list.resize(n, 0);
    dp.resize(n + 1, vector<int>(41, 0));

    for (int i = 1; i <= n; i++) {
        cin >> list[i];
    }

    rightEquation();

    return 0;
}
