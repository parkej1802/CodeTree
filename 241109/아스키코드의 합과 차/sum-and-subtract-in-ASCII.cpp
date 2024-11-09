#include <iostream>
using namespace std;

int main() {
    char c1, c2;

    cin >> c1 >> c2;

    int ascii1 = (int)c1;
    int ascii2 = (int)c2;

    int sum = ascii1 + ascii2;
    int diff = abs(ascii1 - ascii2);

    cout << sum << " " << diff << endl;

    return 0;
}