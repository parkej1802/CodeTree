#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int> blocks(n);

    for (int i = 0; i < n; i++) {
        cin >> blocks[i];
    }

    int s1, e1;
    cin >> s1 >> e1;

    blocks.erase(blocks.begin() + s1 - 1, blocks.begin() + e1);

    int s2, e2;
    cin >> s2 >> e2;

    blocks.erase(blocks.begin() + s2 - 1, blocks.begin() + e2);

    cout << blocks.size() << endl;

    for (int block : blocks) {
        cout << block << endl;
    }

    return 0;
}