#include <iostream>
#include <vector>
using namespace std;

int n;
vector<bool> visited;
vector<int> nums;

void print() {
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void backTracking(int current) {
    if (current == n + 1) {
        print();
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            continue;
        }
        visited[i] = true;
        nums.push_back(i);
        backTracking(current + 1);
        nums.pop_back();
        visited[i] = false;
        
    }
}

int main() {
    cin >> n;

    visited.resize(n + 1, false);
    backTracking(1);

    return 0;
}