#include <iostream>
#include <vector>
using namespace std;

vector<int> list;
int n;
int count = 0;

bool isBeautiful() {
    int i = 0;
    
    while (i < n) {
        int currentNum = list[i]; 
        int cnt = 1; 
        
        while (i + cnt < n && list[i + cnt] == currentNum) {
            cnt++;
        }
        
        if (cnt % currentNum != 0) {
            return false;
        }
        
        i += cnt;
    }

    return true;
}


void print() {
    for (int num : list) {
        cout << num;
    }
    cout << endl;
}

void beautifulNumber(int current) {
    if (current == n) {
        //print();
        if (isBeautiful()) {
            count++;
        }
        return;
    }

    for (int i = 1; i <= 4; i++) {
        list.push_back(i);
        beautifulNumber(current + 1);
        list.pop_back();
    }

}

int main() {
    
    cin >> n;

    beautifulNumber(0);
    
    cout << count;

    return 0;
}