#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1987654321

int n, m, k;
int dp[15][205][205];

int main() {
    cin >> n >> m >> k;

    for(int i = 1; i <= m; i++) dp[1][i][i] = 1;
    
    for(int i = 1; i < n; i++) {
        for(int sum = 1; sum <= m; sum++) {
            for(int last = 1; last <= m; last++) {
                for(int num = 1; num <= last; num++) {
                    if(sum + num <= m) {
                        dp[i + 1][sum + num][num] += dp[i][sum][last];
                        dp[i + 1][sum + num][num] = min(dp[i + 1][sum + num][num], (int)1e9);
                    }
                }
            }
        }
    }

    int cur_sum = m;
    int cur_last = 1;
    for(int i = n; i >= 1; i--) {
        while(dp[i][cur_sum][cur_last] < k) {
            k -= dp[i][cur_sum][cur_last]; 
            cur_last++;
        }

        cout << cur_last << " ";
        cur_sum -= cur_last;
    }

    return 0;
}
