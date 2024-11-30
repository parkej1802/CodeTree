#include <iostream>
#include <cmath>
using namespace std;

int dp[20];


int bst(int n) {
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;

    for (int i = 4; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;
    
    int result = bst(n);

    cout << result;

    return 0;
}