#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
char c;

vector<char> list;

void getCrystal() {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
            if ((list[i - 1] == 'L' && j % 2 == 0) || (list[i - 1] == 'R' && j % 2 == 1)) {
                dp[i][j] += 1;
            }

            if (j > 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 
                    ((list[i - 1] == 'L' && j % 2 == 0) || (list[i - 1] == 'R' && j % 2 == 1) ? 1 : 0));
            }
        }
    }
    
    cout << *max_element(dp[n].begin(), dp[n].end());
}

int main() {
    
    cin >> n >> k;

    list.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    getCrystal();

    return 0;
}