#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, k;
vector<int> seq;
vector<int> dp;

int maxSeq() {
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            
            if (seq[j] < seq[i]) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }
    int maxValue = 0;

    for (int i = 0; i < dp.size(); i++) {
        maxValue = max(maxValue, dp[i]);
    }
    return maxValue;
}



int main() {
    cin >> n;

    seq.resize(n);
    dp.resize(n, INT_MIN);

    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    int result = maxSeq();
    

    cout << result;
    return 0;
}