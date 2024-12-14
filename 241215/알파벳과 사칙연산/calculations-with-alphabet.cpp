#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int max = 0;
vector<char> alpha;
vector<char> sign;  
vector<int> values;
int maxValue = INT_MIN;

int getValue() {
    int result = values[0];

    for (int i = 0; i < sign.size(); ++i) {
        if (sign[i] == '+') result += values[i + 1];
        else if (sign[i] == '-') result -= values[i + 1];
        else if (sign[i] == '*') result *= values[i + 1];
    }

    return result;
}

void backTrack(int index) {
    if (index == alpha.size()) {
        int result = getValue();
        maxValue = std::max(maxValue, result);
        return;
    }

    for (int num = 1; num <= 4; ++num) {
        values[index] = num;
        backTrack(index + 1);
    }
}

int main() {
    string input;

    cin >> input;

    for (char ch : input) {
        if (ch == '+' || ch == '-' || ch == '*') {
            sign.push_back(ch);
        }
        else {
            alpha.push_back(ch);
        }
    }

    values.resize(alpha.size(), 0);
    backTrack(0);

    cout << maxValue;
    
    return 0;
}