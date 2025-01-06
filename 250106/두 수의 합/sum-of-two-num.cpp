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

    for (int i = 0; i < n; i++) {
        map[arr[i]]--;
        int a = k - arr[i];
        if (map[a]) {
            result++;
            map[a]--;
        }
    }

    cout << result;

    return 0;
}

