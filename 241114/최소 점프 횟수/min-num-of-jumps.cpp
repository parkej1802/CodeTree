#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> list;
int n, m, minJump = INT_MAX;


void backTracking(int current, int jumpCount) {

    if (current == n - 1) {
        minJump = min(minJump, jumpCount);
        return;
    }

    for (int i = 1; i <= list[current]; i++) {
        int next = i + current;
        if (next >= n) {
            next = n - 1;
        }
        backTracking(next, jumpCount + 1);
        
    }

}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> m;
        list.push_back(m);
    }

    backTracking(0, 0);

    if (minJump == INT_MAX) {
        cout << -1;
    }
    else {
        cout << minJump;
    }
   
    
    return 0;
}