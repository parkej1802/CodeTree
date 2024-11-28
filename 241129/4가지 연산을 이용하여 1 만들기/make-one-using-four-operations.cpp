#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

int n;

map<pair<int, int>, int> mapCount;
unordered_map<int, int> minCount;

vector<int> minTime;

// 0: 빼기 1 : 더하기 2 : 나누기2 3: 나누기 3

int bfs(int n) {
    queue<pair<int, int>> q;
    q.push({n, 0});

    while (!q.empty()) {

        int num = q.front().first;
        int count = q.front().second;
        q.pop();
        
        if (num == 1) {
            return count;
        }

        if (num % 2 == 0 && mapCount[{num, 2}] == 0) {
            int n2 = num / 2;
            mapCount[{num, 2}]++;
            q.push({n2, count + 1});
        } 
        if (num % 3 == 0 && mapCount[{num, 3}] == 0) {
            int n3 = num / 3;
            mapCount[{num, 3}]++;
            q.push({n3, count + 1});
        }
        if (mapCount[{num, 0}] == 0) {
            mapCount[{num, 0}]++;
            q.push({num - 1, count + 1});
        }
        if (mapCount[{num, 1}] == 0) {
            mapCount[{num, 1}]++;
            q.push({num + 1, count + 1});
        }
    }
    
    return -1;
}

int main() {
    cin >> n;

    int result = bfs(n);

    cout << result;

    return 0;
}