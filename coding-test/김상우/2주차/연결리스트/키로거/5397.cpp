#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string input;
        cin >> input;

        list<char> text;
        auto cursor = text.begin(); // 자동으로 타입을 정해 준다고 함. -> 신기방기

        for (char ch : input) {
            if (ch == '<') {
                if (cursor != text.begin()) cursor--;
            } else if (ch == '>') {
                if (cursor != text.end()) cursor++;
            } else if (ch == '-') {
                if (cursor != text.begin()) {
                    cursor = text.erase(--cursor); 
                }
            } else {
                cursor = text.insert(cursor, ch); 
                cursor++; 
            }
        }

        for (char c : text) {
            cout << c;
        }
        cout << '\n';
    }
    return 0;
}
