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
        
    }

    // Write your code here!

    for (int i = 0; i < n; i++) {
        int temp = k - arr[i];
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (temp == arr[j]) {
                result++;
            }
        }
    }

    cout << result / 2;

    return 0;
}
