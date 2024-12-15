#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <climits>

using namespace std;

vector<char> alpha;
vector<char> sign;
unordered_map<char, int> map;
int maxValue = INT_MIN; 

int calculate(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return 0;
}

int getResult() {
    int result = map[alpha[0]];
    for (int i = 0; i < sign.size(); ++i) {
        result = calculate(result, map[alpha[i + 1]], sign[i]);
    }
    return result;
}

void backTrack(int index) {
    if (index == alpha.size()) {
        int result = getResult();
        maxValue = max(maxValue, result);
        return;
    }

    for (int num = 1; num <= 4; ++num) {
        map[alpha[index]] = num;
        backTrack(index + 1);
    }
}

int main() {
    string input;
    cin >> input;

    for (char ch : input) {
        if (ch == '+' || ch == '-' || ch == '*') {
            sign.push_back(ch);
        } else {
            alpha.push_back(ch);
        }
    }

    backTrack(0);

    cout << maxValue << endl;
    return 0;
}
