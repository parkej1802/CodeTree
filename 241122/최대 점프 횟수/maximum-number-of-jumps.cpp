#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<int> list;
vector<int> dp;

int maxJump() {
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {

            if (list[j] + j >= i) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int numJump = 0;

    for (int i = 0; i < dp.size(); i++) {
        numJump = max(numJump, dp[i]);
    }

    return numJump;
}

int main() {
    cin >> n;

    list.resize(n);
    dp.resize(n, INT_MIN);

    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    
    int result = maxJump();

    cout << result;
    
    return 0;
}