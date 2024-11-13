#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int matrix[1000];

vector<pair<int, int>> linePos;
vector<pair<int, int>> lines;

int maxLine = 0;

int overlap() {
    if (lines.empty()) return 0;
    int numLineCount = 1;
    int lastEnd = lines[0].second;

    for (int i = 0; i < lines.size(); i++) {

        if (lines[i].first > lastEnd) {
            numLineCount++;
            lastEnd = lines[i].second;
        }
        
    }
    return numLineCount;
}

void backTracking(int current) {
    if (current == n) {
        int result = overlap();
        maxLine = max(result, maxLine);
        return;
    }

    backTracking(current + 1);

    lines.push_back(linePos[current]);
    backTracking(current + 1);
    lines.pop_back();
    
}

int main() {
    
    cin >> n;

    int x1, x2;
    
    for (int i = 0; i < n; i++) {
        cin >> x1 >> x2;
        linePos.push_back({x1, x2});
    }
    sort(linePos.begin(), linePos.end());
    
    backTracking(0);
    
    cout << maxLine;

    return 0;
}