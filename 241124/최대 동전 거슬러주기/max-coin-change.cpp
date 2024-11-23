#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> list;
vector<int> dp;

int n, m;

int maxCoin() {

    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            
            if (j >= list[i]) {
                if (dp[j - list[i]] == INT_MIN) continue;
                dp[j] = max(dp[j], dp[j - list[i]] + 1);
            }
        }
    }   

    return dp[m];
}

int main() {
    
    cin >> n >> m;

    list.resize(n);
    dp.resize(m + 1, INT_MIN);

    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    int result = maxCoin();

    if (dp[m] == INT_MIN) {
        cout << -1;
    }
    else {
        cout << result;
    }


    return 0;
}