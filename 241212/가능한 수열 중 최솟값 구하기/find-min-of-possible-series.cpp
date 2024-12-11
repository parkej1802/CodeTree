#include <iostream>
#include <vector>

using namespace std;

vector<int> list;
vector<int> result;

int n;

bool possible() {
    int length = list.size();

    for (int i = 1; i <= length / 2; i++) {
        bool isSame = true;
        for (int j = 0; j < i; j++) {
            if (list[length - i + j] != list[length - 2 * i + j]) {
                isSame = false;
                break;
            }
        }
        if (isSame) return false;
    }

    return true;
}

void print() {
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
}

bool backTracking() {

    if (!possible()) return false; 

    if (list.size() == n) {
        if (result.empty()) {
            result = list;
            print();
        }
        return true;
    } 

    list.push_back(4);
    if (backTracking()) return true;
    list.pop_back();

    list.push_back(5);
    if (backTracking()) return true;
    list.pop_back();

    list.push_back(6);
    if (backTracking()) return true;
    list.pop_back();

    return false;
}

int main() {
    cin >> n;

    backTracking();

    return 0;
}