#include <iostream>
#include <vector>

#define MOD 1000000007 

using namespace std;

int n;

vector<long long> dp;
long long count = 0;

void threeSixNine() {

    for (long long i = 1; i <= n; i++) {
        if (i % 3 == 0) {
            count++;
        }
        else {
            long long temp = i;
            while (temp > 0) {
                if (temp % 10 == 3 || temp % 10 == 6 || temp % 10 == 9) {
                    count++;
                    break;
                }
                temp /= 10; 
            }
        }
    }
}

int main() {
    cin >> n;

    threeSixNine();
    cout << count % MOD;
    return 0;
}