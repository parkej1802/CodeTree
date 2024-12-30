#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> quests;
vector<int> dp;

int n, m;
int maxExp = 1000000; 

int main() {

    cin >> n >> m;

    quests.resize(n);
    dp.resize(maxExp + 1, 1e9);

    for (int i = 0; i < n; i++) {
        cin >> quests[i].first >> quests[i].second;
    }

    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        int exp = quests[i].first;
        int time = quests[i].second;
        for (int j = exp; j <= maxExp; j++) {
            dp[j] = min(dp[j], dp[j - exp] + time);
        }
    }

    int result = 1e9;
    for (int i = m; i <= maxExp; ++i) {
        result = min(result, dp[i]);
    }

    if (result == 1e9) {
        cout << -1;
    } 
    else {
        cout << result << endl;
    }

    return 0;
}
