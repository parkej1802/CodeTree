#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> list;
vector<int> dp;

int maxDecreasingSeq() {
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {

            if (list[i] < list[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxSeq = 0;

    for (int i = 0; i < dp.size(); i++) {
        maxSeq = max(maxSeq, dp[i]);
    }
    return maxSeq;

}

int main() {
    cin >> n;

    list.resize(n);
    dp.resize(n, 1);

    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }


    int result = maxDecreasingSeq();

    cout << result;

    return 0;
}