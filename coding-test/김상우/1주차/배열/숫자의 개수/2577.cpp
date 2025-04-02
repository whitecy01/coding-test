#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int count[10] = {0};

    string result = to_string(a * b * c);  // 문자열로 변환

    for (char ch : result) {
        count[ch - '0']++;  // 문자를 숫자로 변환해서 카운트
    }

    for (int i = 0; i < 10; ++i) {
        cout << count[i] << '\n';
    }

    return 0;
}
