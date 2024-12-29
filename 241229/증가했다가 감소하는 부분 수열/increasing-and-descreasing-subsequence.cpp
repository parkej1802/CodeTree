#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> list;
vector<int> dpUp;
vector<int> dpDown;

void increaseDecreaseSeq() {

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (list[i] > list[j]) {
                dpUp[i] = max(dpUp[i], dpUp[j] + 1);
            }
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (list[i] > list[j]) {
                dpDown[i] = max(dpDown[i], dpDown[j] + 1);
            }
        }
    }

    int result = 0;
    for (int i = 0; i < n; ++i) {
        result = max(result, dpUp[i] + dpDown[i] - 1);
    }

    cout << result;
}

int main() {
    cin >> n;

    list.resize(n);
    dpUp.resize(n, 1);
    dpDown.resize(n, 1);

    for (int i = 0; i < n; ++i) {
        cin >> list[i];
    }

    increaseDecreaseSeq();

    return 0;
}
