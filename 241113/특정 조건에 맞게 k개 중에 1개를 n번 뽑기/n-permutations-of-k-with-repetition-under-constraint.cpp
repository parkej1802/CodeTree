#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;
int k, n;

void print() {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

void backTrack(int current) {
    if (current == n) {
        print();
        return;
    }

    for (int i = 1; i <= k; i++) {
        int size = nums.size();
        if (size >= 2 && nums[size - 1] == i && nums[size - 2] == i) {
            continue;
        }

        nums.push_back(i);
        backTrack(current + 1);
        nums.pop_back();
    }
}

int main() {

    cin >> k >> n;
    backTrack(0);

    return 0;
}