#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<pair<int, int>> bag;
vector<int> dp;

int n, m, f, s;

int maxValueBag() {

    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = m; j > 0; j--) {
            
            if (j >= bag[i].first) {
                
                dp[j] = max(dp[j], bag[i].second + dp[j - bag[i].first]);
            }
            
        }
    
    }

    int result = 0;
    for (int i = 0; i < dp.size(); i++) {
        result = max(dp[i], result);
    }
    
    return result;
}

int main() {
    cin >> n >> m;

    dp.resize(m + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> f >> s;
        bag.push_back({f, s});
    }

    int result = maxValueBag();

    cout << result;

    return 0;
}