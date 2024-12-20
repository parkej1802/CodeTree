#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007
int n;

vector<vector<long long>> dp;

void numStair() {

    for (int j = 1; j <= 9; j++) {
        dp[1][j] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j > 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            }
            dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            
        }
    }

    long long result = 0;

    for (int j = 0; j <= 9; j++) {
        result = (result + dp[n][j]) % MOD;
    }

    cout << result << endl;
}

int main() {
    cin >> n;

    dp.resize(n + 1, vector<long long>(10, 0));

    numStair();

    return 0;
}


