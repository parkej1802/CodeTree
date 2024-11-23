#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<int> list;
vector<int> dp;

int maxSeq() {
    

    dp[0] = list[0];
    int result = dp[0];
    
    for (int i = 1; i < n; i++) {
        dp[i] = max(list[i], list[i] + dp[i - 1]);
        result = max(dp[i], result);
    }

    return result;
}

int main() {
    
    cin >> n;

    list.resize(n);
    dp.resize(n, INT_MIN);

    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    int result = maxSeq();

    cout << result;

    return 0;
}