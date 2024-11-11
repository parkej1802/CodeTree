#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& answer) {
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
}

void backTracking(int currentNum, int k, int n, vector<int>& result) {
    if (result.size() == n) {
        print(result);
        return;
    }

    for (int i = 1; i <= k; i++) {
        result.push_back(i);
        backTracking(i, k, n, result);
        result.pop_back();
    }
}

int main() {
    int k, n;
    cin >> k >> n;

    vector<int> result;
    backTracking(1, k, n, result);

    return 0;
}