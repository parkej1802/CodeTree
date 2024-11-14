#include <iostream>
#include <vector>
using namespace std;

vector<int> list;
vector<int> nums;

int n, m, k, maxValue = 0;

int getMaxValue() {
    int result = list[0];
    for (int i = 1; i < nums.size(); i++) {
        result ^= nums[i];
    }
    return result;
}

void backTracking(int current, int count) {

    if (current == m) {
        int result = getMaxValue();
        maxValue = max(maxValue, result);
        return;
    }

    for (int i = count; i < n; i++) {
        nums.push_back(list[i]);
        backTracking(current + 1, count + 1);
        nums.pop_back();
    }
} 


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> k;
        list.push_back(k);
    }

    backTracking(0, 0);

    cout << maxValue;
    return 0;
}