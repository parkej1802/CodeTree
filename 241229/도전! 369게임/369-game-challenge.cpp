#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
#define ll long long

string a;
int n;
ll pt[100005];
ll dp[100005][5];
ll ans;
bool is_suc;
int sm;

int main() {
    cin >> a;
    n = a.length();

    pt[0] = 1;
    for(int i = 1; i <= n; i++) {
        pt[i] = pt[i - 1] * 10 % MOD;
    }

    for(int i = 0; i < n; i++) {
        int num = a[i] - '0';
        for(int x = 0; x < 10; x++) {
            if(x == 3 or x == 6 or x == 9) {
                ans += (dp[i][0] + dp[i][1] + dp[i][2]) * pt[n - i - 1] % MOD;
                ans %= MOD;
                continue;
            }
            
            for(int k = 0; k < 3; k++) {
                dp[i + 1][(x + k) % 3] += dp[i][k];
                dp[i + 1][(x + k) % 3] %= MOD;
            }
        }

        for(int x = 0; x < num; x++) {
            if(is_suc or x == 3 or x == 6 or x == 9) {
                ans += pt[n - i - 1];
                ans %= MOD;
            }
            else {
                dp[i + 1][(x + sm) % 3]++;
                dp[i + 1][(x + sm) % 3] %= MOD;
            }
        }

        if(num == 3 or num == 6 or num == 9) {
            is_suc = true;
        }
        else {
            sm += num;
        }
    }

    if(is_suc) {
        ans++;
        ans %= MOD;
    }
    else {
        dp[n][sm % 3]++;
        dp[n][sm % 3] %= MOD;
    }

    ans += dp[n][0];
    ans += (MOD - 1);
    ans %= MOD;
    cout << ans;

    return 0;
}