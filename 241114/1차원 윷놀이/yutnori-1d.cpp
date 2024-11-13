#include <iostream>
#include <vector>
using namespace std;

int n, m, k, l;

vector<int> list;
vector<int> horseOrder;

int maxHorseScore = 0;

int maxScore() {
    int score = 0;
    vector<int> horseScore(k + 1, 0);

    for (int i = 0; i < horseOrder.size(); i++) {
        horseScore[horseOrder[i]] += list[i];
    }

    for (int i = 1; i <= k; i++) {
        if (horseScore[i] >= m - 1) {
            score++;
        }
    }

    return score;
}

void backTracking(int current) {

    if (current == n) {
        int ms = maxScore();
        maxHorseScore = max(maxHorseScore, ms);
        return;
    }
    
    for (int i = 1; i <= k; i++) {
        horseOrder.push_back(i);
        backTracking(current + 1);
        horseOrder.pop_back();
    }
}

int main() {

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> l;
        list.push_back(l);
    }

    backTracking(0);
 
    cout << maxHorseScore;

    return 0;
}