#include <iostream>
#include <climits>

using namespace std;

int applyRunLengthEncoding(string a) {
    int count = 1;
    string result;

    for (int i = 1; i < a.length(); i++) {
        if (a[i] == a[i - 1]) {
            count++;
        }
        else {
            result += a[i - 1] + to_string(count);
            count = 1;
        }
    }
    
    result += a[a.length() - 1] + to_string(count);

    return result.length();
}

int runLengthEncoding(string a) {
    int strLength = a.length() - 1;
    int encodingLength = 0;
    int minResult = INT_MAX;
    

    for (int i = 0; i < a.length(); i++) {

        encodingLength = applyRunLengthEncoding(a);
        minResult = min(minResult, encodingLength);

        char temp = a[strLength];
        for (int j = strLength; j > 0; j--) {
            a[j] = a[j - 1];
        }
        a[0] = temp;

    }

    return minResult;
}   

int main() {
    string a;

    cin >> a;

    int result = runLengthEncoding(a);

    cout << result;

    return 0;
}