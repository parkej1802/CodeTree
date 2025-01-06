#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MAX_N = 100000;

int n, m;
vector<int> arr;
vector<int> nums;
unordered_map<int, int> map;

void function() {

    for (int i = 0; i < n; i++) {
        map[arr[i]]++;
    }

    for (int i = 0; i < m; i++) {
        cout << map[nums[i]] << " ";
    }

}



int main() {
    cin >> n >> m;

    arr.resize(n);
    nums.resize(m);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> nums[i];
    }

    function();
    
    return 0;
}
