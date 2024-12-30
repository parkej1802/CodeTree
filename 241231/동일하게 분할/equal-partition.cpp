#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, k;
vector<int> list;
vector<vector<bool>> dp;

void minSub() {
    
    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j >= list[i] && dp[i - 1][j - list[i]]) {
                dp[i][j] = true;
            }
            if (dp[i - 1][j]) {
                dp[i][j] = true;
            }
        }
    }

    int result = INT_MAX;
    for (int i = 1; i < k; i++) {
        if (dp[n][i]) {
            result = min(result, abs(i - (k - i)));
        }
    }

    if (result == INT_MAX) {
        cout << "No";
    } else {
        cout << "Yes";
    }
}

int main() {
    cin >> n;

    list.resize(n + 1);

    int total_sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> list[i];
        total_sum += list[i];
    }

    if (total_sum % 2 != 0) {
        cout << "No";
        return 0;
    }

    k = total_sum / 2;
    
    dp.resize(n + 1, vector<bool>(k + 1, false));
    minSub();

    return 0; 
}
