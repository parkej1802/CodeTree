#include <iostream>
#include <vector>

using namespace std;

int dp[1001];

int stair(int n) {
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 1;
    dp[5] = 2;
    dp[6] = 2;
    dp[7] = 3;

    for (int i = 8; i <= n; i++) {
        dp[i] = dp[i - 2] + dp[i - 3];
        dp[i] = dp[i] % 10007;
    }

    return dp[n];
}

int main() {
    int n;

    cin >> n;

    int result = stair(n);
    cout << result;
    return 0;
}