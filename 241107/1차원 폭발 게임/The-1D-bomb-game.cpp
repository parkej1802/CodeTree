#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> oneDimensionalBomb(int n, int m, vector<int>& bombs) {
    
    bool loop = true;
    vector<int> result;

    while (loop) {
        int bombSize = bombs.size();
        for (int i = 0; i < n; i++) {
            int count = 1;
            for (int j = 1; j < bombs.size(); j++) {
                if (i + j < bombs.size()) {
                    if (bombs[i] == bombs[i + j]) {
                        count++;
                    }
                    else {
                        break;
                    }
                }
                
            }

            if (count >= m) {
                bombs.erase(bombs.begin() + i, bombs.begin() + i + count);
                i++;
            }
            
        }
        if (bombSize == bombs.size() || bombs.empty()) {
            loop = false;
        }
    }
    return bombs;
}

int main() {
    int n, m;

    cin >> n >> m;

    vector<int> bombs(n);

    for (int i = 0; i < n; i++) 
        cin >> bombs[i];
    

    vector<int> result = oneDimensionalBomb(n, m, bombs);

    cout << bombs.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}