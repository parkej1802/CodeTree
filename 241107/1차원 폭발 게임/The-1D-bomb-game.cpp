#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void oneDimensionalBomb(int n, int m, vector<int>& bombs) {
    
    bool loop = true;
    
    while (loop) {
        int bombSize = bombs.size();
        for (int i = 0; i < bombs.size(); i++) {
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
            }
            
        }
        if (bombSize == bombs.size()) {
            loop = false;
        }

        if (bombs.empty()) {
            loop = false;
        }
    }
}

int main() {
    int n, m;

    cin >> n >> m;

    vector<int> bombs(n);

    for (int i = 0; i < n; i++) 
        cin >> bombs[i];
    

    oneDimensionalBomb(n, m, bombs);

    cout << bombs.size() << endl;
    for (int i = 0; i < bombs.size(); i++) {
        cout << bombs[i] << endl;
    }

    return 0;
}