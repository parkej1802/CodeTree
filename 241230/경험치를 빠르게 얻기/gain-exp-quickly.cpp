#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<pair<int, int>> quests;
vector<int> dp;

int n, m;

int main() {
    cin >> n >> m;

    quests.resize(n);
    int totalExp = 0;

    for (int i = 0; i < n; i++) {
        cin >> quests[i].first >> quests[i].second;
        totalExp += quests[i].first;
    }

    dp.resize(totalExp + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        int exp = quests[i].first;
        int time = quests[i].second;
        for (int j = totalExp; j >= exp; j--) {
            if (dp[j - exp] != INT_MAX) {
                dp[j] = min(dp[j], dp[j - exp] + time);
            }
        }
    }

    int result = INT_MAX;
    for (int i = m; i <= totalExp; i++) {
        result = min(result, dp[i]);
    }

    if (result == INT_MAX) {
        cout << -1;
    } else {
        cout << result;
    }

    return 0;
}
