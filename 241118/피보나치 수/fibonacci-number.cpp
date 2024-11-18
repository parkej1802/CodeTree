#include <iostream>
using namespace std;

int dp[46];

int fibo(int n) {
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    int result = fibo(n);

    cout << result;
    
    return 0;
}