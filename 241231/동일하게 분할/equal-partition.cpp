#include <iostream>
#include <vector>

using namespace std;

int n, totalSum, k;
vector<int> list;
vector<bool> dp;

void minSub() {
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        int num = list[i];
        for (int j = totalSum / 2; j >= num; j--) {
            if (dp[j - num]) {
                dp[j] = true;
            }
        }
    }

    if (dp[totalSum / 2]) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}

int main() {
    cin >> n;

    list.resize(n + 1);

    totalSum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> list[i];
        totalSum += list[i];
    }

    if (totalSum % 2 != 0) {
        cout << "No";
        return 0;
    }

    dp.resize(totalSum / 2 + 1, false);
    minSub();

    return 0;
}
