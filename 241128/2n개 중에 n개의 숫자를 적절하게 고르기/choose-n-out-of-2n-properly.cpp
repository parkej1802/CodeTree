#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int n;
vector<int> list;
vector<int> groupA;
vector<int> groupB;

int calculateMinSum() {
    int groupASum = 0, groupBSum = 0;

    for (int i = 0; i < groupA.size(); i++) {
        groupASum += groupA[i];
    }

    for (int i = 0; i < groupB.size(); i++) {
        groupBSum += groupB[i];
    }

    return abs(groupASum - groupBSum);
}

int minSum = INT_MAX;

void backTracking(int current) {
    if (current == 2 * n) {
        int result = calculateMinSum();
        minSum = min(minSum, result);
        return;
    }

    groupA.push_back(list[current]);
    backTracking(current + 1);
    groupA.pop_back(); 

    groupB.push_back(list[current]);
    backTracking(current + 1); 
    groupB.pop_back(); 
}

int main() {
    cin >> n; 

    list.resize(2 * n);

    for (int i = 0; i < 2 * n; i++) {
        cin >> list[i];
    }

    backTracking(0);

    cout << minSum;

    return 0;
}
