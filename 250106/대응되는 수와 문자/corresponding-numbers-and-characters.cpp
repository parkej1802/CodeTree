#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m;
string words[100000];
string queries[100000];
unordered_map<string, int> map;
unordered_map<int, string> mapR;

bool digits(string &str)
{
    return str.find_first_not_of("0123456789") == string::npos;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> words[i];
        mapR[i] = words[i];
        map[words[i]] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> queries[i];
        if (digits(queries[i])) {
            int a = stoi(queries[i]);
            cout << mapR[a] << endl;
        }
        else {
            cout << map[queries[i]] << endl;;
        }
    }

    

    return 0;
}
