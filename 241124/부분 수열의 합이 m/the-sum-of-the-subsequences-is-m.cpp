#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, m, k;

vector<int> list;
vector<int> dp;

int minSumSeq() {
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = m; j > 0; j--) {
            if (j >= list[i]) {
                if (dp[j - list[i]] == INT_MAX) continue;

                dp[j] = min(dp[j], dp[j - list[i]] + 1);
            }
            
        }
    }
    return dp[m];
}

int main() {
    
    cin >> n >> m;

    dp.resize(m + 1, INT_MAX);
    for (int i = 0; i < n; i++) {
        cin >> k;

        list.push_back(k);
    }

    int result = minSumSeq();

    if (result == INT_MAX) {
        cout << -1;
    }
    else {
        cout << result;
    }
    

    return 0;
}