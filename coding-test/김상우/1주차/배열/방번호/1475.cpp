#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int count[10] = {0};

    for (char c : s) {
        int num = c - '0';
        count[num]++;
    }

    
    int a = count[6] + count[9];
    count[6] = count[9] = (a + 1) / 2;

    int max = 0;
    for (int i = 0; i < 10; ++i) {
        if (count[i] > max) {
            max = count[i];
        }
    }

    cout << max;
    return 0;
}