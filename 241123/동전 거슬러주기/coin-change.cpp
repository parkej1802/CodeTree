#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, m, k;

vector<int> list;
vector<int> dp;

int pickItem() {
    dp[0] = 0;
    int result = INT_MAX;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= list[j]) {
                if (dp[i - list[j]] == INT_MAX) {
                    continue;
                }

                dp[i] = min(dp[i], dp[i - list[j]] + 1);
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

    int result = pickItem();

    if (result == INT_MAX) {
        cout << -1;
    }
    else {
        cout << result;
    }
  

    return 0;
}