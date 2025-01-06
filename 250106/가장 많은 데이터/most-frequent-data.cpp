#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int n;
string words[100000];
unordered_map<string, int> map;
int result = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        map[words[i]]++;
        result = max(result, map[words[i]]);
    }

    cout << result;
    


    return 0;
}
