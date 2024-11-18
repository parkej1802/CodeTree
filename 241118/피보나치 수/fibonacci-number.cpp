#include <iostream>
#include <vector>

using namespace std;

int dp[46];
vector<int> memo;

int fibbo(int n) {
    if (memo[n] != -1) {
        return memo[n];
    }
    if (n <= 2) {
        memo[n] = 1;
    }
    else {
        memo[n] = fibbo(n - 1) + fibbo(n - 2);
    }
    return memo[n];
}

int main() {
    int n;
    cin >> n;
    memo.resize(n + 1, -1);

    int result = fibbo(n);

    cout << result;
    
    return 0;
}