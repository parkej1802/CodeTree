#include <iostream>
#include <vector>

using namespace std;

vector<int> visited;
vector<int> list;
int n;

void print() {

    for (int num : list) {
        cout << num << " ";
    }
    cout << endl;
}

void backTrack(int current) {

    if (current == n) {
        print();
        return;
    }

    for (int i = n; i > 0; i--) {
        if (visited[i]) continue;

        visited[i] = true;
        list.push_back(i);
        backTrack(current + 1);
        list.pop_back();
        visited[i] = false;
    }
}

int main() {
    cin >> n;

    visited.resize(n + 1, false);
    backTrack(0);

    return 0;
}