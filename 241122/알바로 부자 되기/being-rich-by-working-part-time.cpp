#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int n, s, e, p;

vector<pair<int, int>> list;
vector<int> pay;
vector<int> dp;

int maxProfit() {

    dp[0] = pay[0];
    int result = dp[0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = pay[i];
            if (list[i].first > list[j].second) {
                dp[i] = max(dp[i], dp[j] + pay[i]);
            }
        }
        result = max(result, pay[i]);
    }

    return result;
}

int main() {
    cin >> n;

    dp.resize(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> s >> e >> p;

        list.push_back({s, e});
        pay.push_back(p);
    }

    sort(list.begin(), list.end());

    int result = maxProfit();

    cout << result;

    return 0;
}