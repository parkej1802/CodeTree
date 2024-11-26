#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<vector<int>> dp;
vector<int> list;

void treasureMap() {

    dp[0][0] = list[0];

    int result = dp[0][0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {

            if (list[i] > 0) {
                dp[i][j] = max(list[i], dp[i - 1][j] + list[i]);
                
            }
            else if (j > 0 && list[i] < 0) {
                dp[i][j] =  max(dp[i][j], dp[i - 1][j - 1] + list[i]);
            }

            result = max(result, dp[i][j]);
        }
    }
    cout << result;
    
}

int main() {
    cin >> n >> k;

    dp.resize(n + 1, vector<int>(k + 1, -1));
    list.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    treasureMap();

    return 0;
}