#include <iostream>
#include <vector>

using namespace std;

int n, f, s;

vector<pair<int, int>> list;
vector<int> dp;

int chooseLine() {

    dp[0] = 1;
    int result = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (list[j].second < list[i].first) {
                dp[i] = max(dp[i], dp[j] + 1);
                result = max(result, dp[i]);
            }
            
        }
    }

    return result;
}

int main() {

    cin >> n;

    dp.resize(n, 1);
    
    for (int i = 0; i < n; i++) {
        cin >> f >> s;
        list.push_back({f, s});
    }

    int result = chooseLine();

    cout << result;

    return 0;
}