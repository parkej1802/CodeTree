#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, m, f, s;

vector<int> dp;
vector<pair<int, int>> bag;

int maxValueBagTwo() {

    dp[0] = 0;
    int result = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            
            if (i >= bag[j].first) {
                dp[i] = max(dp[i], dp[i - bag[j].first] + bag[j].second);
                result = max(result, dp[i]);
            }
        }
    }

    return result;
}


int main() {
    cin >> n >> m;

    dp.resize(m + 1, INT_MIN);

    for (int i = 0; i < n; i++) {
        cin >> f >> s;
        bag.push_back({f, s});
    }

    int result = maxValueBagTwo();

    cout << result;

    return 0;
}