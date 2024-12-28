#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int n, m, x, y;
vector<pair<int, int>> list;
vector<pair<int, int>> btList;

double minResult = INT_MAX;

float calculateDistance(pair<int, int>& a, pair<int, int>& b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

void distCalculation() {
    double maxDist = 0;
    for (int i = 0; i < btList.size(); i++) {
        for (int j = i + 1; j < btList.size(); j++) {
            double dist = calculateDistance(btList[i], btList[j]);
            maxDist = max(maxDist, dist);
        }
    }

    minResult = min(minResult, maxDist);
}

void backTrack(int current) {
    if (btList.size() == m) {
        distCalculation();
        return;
    }

    for (int i = current; i < list.size(); i++) {
        btList.push_back(list[i]);
        backTrack(i + 1);
        btList.pop_back();
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        list.push_back({x, y});
    }

    backTrack(0);
    cout << minResult * minResult;

    return 0;
}
