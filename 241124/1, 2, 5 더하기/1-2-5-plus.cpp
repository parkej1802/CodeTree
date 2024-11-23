#include <iostream>
#include <vector>

using namespace std;

int n;

vector<int> dp;
vector<int> list;

int oneTwoFiveSum() {
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < list.size(); j++) {
            if (i >= list[j]) {
                dp[i] += dp[i - list[j]] % 10007;
            }
        }
    }

    return dp[n] % 10007;
}

int main() {

    cin >> n;

    dp.resize(n + 1, 0);
    
    list.push_back(1);
    list.push_back(2);
    list.push_back(5);

    int result = oneTwoFiveSum();

    cout << result;

    return 0;
}