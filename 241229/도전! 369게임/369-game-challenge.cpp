#include <iostream>
#include <vector>

#define MOD 1000000007 

using namespace std;

int n;

vector<long long> dp;
long long count = 0;

bool isClap(int num) {
    if (num % 3 == 0) return true;
    while (num > 0) {
        if (num % 10 == 3 || num % 10 == 6 || num % 10 == 9) {
            return true;
        }
        num /= 10;
    }
    return false;
}

void threeSixNine() {

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        
        if (isClap(i)) {
            dp[i] = (dp[i] + 1) % MOD;
        }
    }
}

int main() {
    cin >> n;

    dp.resize(n + 1, 0);

    threeSixNine();

    cout << dp[n] % MOD;

    return 0;
}