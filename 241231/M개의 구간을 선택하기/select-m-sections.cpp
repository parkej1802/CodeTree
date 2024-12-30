#include <iostream>
#include <algorithm>

#define MAX_N 500
#define MAX_M 250
#define MIN_ANS -500000
#define NUM_STATE 2

enum STATE {
    NOT_BELONG,
    BELONG
};

using namespace std;

int n, m;

int dp[MAX_N + 1][MAX_M + 1][NUM_STATE];

int a[MAX_N + 1];

void Initialize() {

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            dp[i][j][NOT_BELONG] = dp[i][j][BELONG] = MIN_ANS;
        }
    }

    for(int i = 0; i <= n; i++) {
        dp[i][0][NOT_BELONG] = 0;
    }
}

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    Initialize();

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j][BELONG] = max(dp[i - 1][j - 1][NOT_BELONG] + a[i],
                                   dp[i - 1][j][BELONG] + a[i]);

            dp[i][j][NOT_BELONG] = max(dp[i - 1][j][NOT_BELONG],
                                       dp[i - 1][j][BELONG]);
        }
    }

    cout << max(dp[n][m][NOT_BELONG], dp[n][m][BELONG]);
}