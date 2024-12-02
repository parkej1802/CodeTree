#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m;

struct cloth {
    int start;
    int end;
    int value;
};

vector<cloth> clothes;

vector<vector<int>> dp;
int totalSum = 0;

void chooseCloth() {

    for (int i = 0; i < n; i++) {
         if (clothes[i].start <= 1 && clothes[i].end >= 1) {
            dp[1][i] = 0;
        }
    }

    for (int day = 2; day <= m; day++) { 
        for (int current = 0; current < n; current++) {
            if (clothes[current].start <= day && clothes[current].end >= day) { 
                for (int prev = 0; prev < n; prev++) {
                    if (clothes[prev].start <= day - 1 && clothes[prev].end >= day - 1) { 
                        int diff = abs(clothes[current].value - clothes[prev].value);
                        dp[day][current] = max(dp[day][current], dp[day - 1][prev] + diff); 
                    }
                }
            }
        }
    }

    
}

int main() {
    cin >> n >> m;

    clothes.resize(n);
    dp.resize(m + 1, vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
        cin >> clothes[i].start >> clothes[i].end >> clothes[i].value;
    }

    chooseCloth();

    int maxValue = -1;
    for (int i = 0; i < n; i++) {
        if (clothes[i].start <= m && clothes[i].end >= m) {
             maxValue = max(maxValue, dp[m][i]);
        }
    }

    cout << maxValue << endl;

    return 0;
}
