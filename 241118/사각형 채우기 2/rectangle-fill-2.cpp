#include <iostream>
using namespace std;

long dp[1000];

int rect(int n) {
    dp[1] = 1;
    dp[2] = 3;
    
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] * 2;
        dp[i] = dp[i] % 10007;
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    int result = rect(n);

    cout << result;
    return 0;
}