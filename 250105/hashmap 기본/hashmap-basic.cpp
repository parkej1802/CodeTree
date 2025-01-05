#include <iostream>
#include <unordered_map>

using namespace std;

int n;

void hashMap() {
    
}

int main() {
    int n, k, v;
    string str;

    cin >> n;
    unordered_map<int, int> map;

    for (int i = 0; i < n; ++i) {
        cin >> str;

        if (str == "add") {
            
            cin >> k >> v;
            map[k] = v;
        } 
        else if (str == "find") {
            cin >> k;
            if (map.find(k) != map.end()) {
                cout << map[k] << endl;
            } 
            else {
                cout << "None" << endl;
            }
        } 
        else if (str == "remove") {
            cin >> k;
            map.erase(k);
        }
    }

    return 0;
}
