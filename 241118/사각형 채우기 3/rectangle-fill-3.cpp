#include <iostream>
using namespace std;

long dp[1001];

long rec(int n) {
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 7;
    
    
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] * 2 + dp[i - 2] * 3;
        dp[i] = dp[i] % 1000000007;
        for (int j = i - 3; j >= 0; j--) {
            dp[i] = dp[i] + 2 * dp[j];
            dp[i] = dp[i] % 1000000007;
        }
    }

    return dp[n];

}


int main() {
    int n; 

    cin >> n;

    long result = rec(n);

    cout << result;

    return 0;
}