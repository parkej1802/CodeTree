#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string str;
vector<char> sign;
vector<char> alpha;
unordered_map<char, int> map;
vector<int> list;
vector<int> cal;

int maxNum = 0;

int calculate() {
    int result = map[alpha[0]];

    for (int i = 0; i < sign.size(); ++i) {
        char operation = sign[i];
        int value = map[alpha[i + 1]];
        if (operation == '+') {
            result += value;
        } else if (operation == '-') {
            result -= value;
        } else if (operation == '*') {
            result *= value;
        }
    }
    
    return result;
}

void assignHashMap() {
    int index = 0;
    for (char c = 'a'; c <= 'f'; c++) {
        map[c] = list[index++];
    }
}

void print() {
    for (int num : list) {
        cout << num << " ";
    }
    cout << endl;
}

void backTracking() {
    if (list.size() == 6) {
        assignHashMap();
        int result = calculate();
        maxNum = max(result, maxNum);
        return;
    }

    for (int i = 1; i <= 4; i++) {
        list.push_back(i);
        backTracking();
        list.pop_back();
    }
} 

int main() {

    cin >> str;

    for (char c : str) {
        if (c == '+' || c == '-' || c == '*') {
            sign.push_back(c);
        }
        else {
            alpha.push_back(c);
        }
    }

    backTracking();

    cout << maxNum;

    return 0;
}