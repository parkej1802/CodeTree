#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> list;
vector<int> dp;

int maxStickProfit() {

    dp[0] = 0;
    int result = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j <= i) {
                dp[i] = max(dp[i], dp[i - j] + dp[j]);
                result = max(result, dp[i]);
            }
        }
        
    }

    return result;
}

int main() {
    cin >> n;

    dp.resize(1);
    list.resize(1);

    for (int i = 1; i <= n; i++) {
        cin >> k;
        list.push_back(k);
        dp.push_back({k});
    }

    int result = maxStickProfit();

    cout << result;

    return 0;
}