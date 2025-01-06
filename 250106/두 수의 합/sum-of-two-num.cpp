#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, k;
int arr[100000];
unordered_map<int ,int> map;
int result = 0;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        map[arr[i]]++;
    }

    // Write your code here!

    for (auto &pair : map) {
        int num = pair.first;
        int count = pair.second;
        int target = k - num;

        if (map.find(target) != map.end()) {
            if (num == target) {
                result += count * (count - 1) / 2;
            } 
            else if (map[num] && map[target]) {
                result += count * map[target];
                map[target] = 0;
            }
            map[num] = 0;
        }
    }

    cout << result;

    return 0;
}

