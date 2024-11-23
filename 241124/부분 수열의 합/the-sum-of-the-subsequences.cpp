#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, m;
vector<int> dp;
vector<int> list;

string seqSum() {
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = m; j > 0; j--) {
            if (j >= list[i]) {
                dp[j] = max(dp[j], dp[j - list[i]] + 1);
            }   
        }
    }

    if (dp[m] > 0) {
        return "Yes";
    }
    return "No";
}

int main() {
    cin >> n >> m;

    list.resize(n);
    dp.resize(m + 1, INT_MIN);

    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    string result = seqSum();

    cout << result;

    return 0;
}