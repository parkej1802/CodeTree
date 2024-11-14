#include <iostream>
#include <vector>

using namespace std;

vector<int> list;
int n, m;

void print() {
    for (int i = 0; i < m; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

void backTracking(int current, int count) {

    if (current == m) {
        print();
        return;
    }

    for (int i = count; i <= n; i++) {
        list.push_back(i);
        backTracking(current + 1, i + 1);
        list.pop_back();
    }

}

int main() {
    cin >> n >> m;

    backTracking(0, 1);

    return 0;
}