#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;
    vector<char> r;
    int c = 1; 

    bool possible = true;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        while (c <= t) {
            s.push(c);
            r.push_back('+');
            c++;
        }

        if (s.top() == t) {
            s.pop();
            r.push_back('-');
        } else {
            
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << "NO" << endl; // 계행 n에서 endl로 바꿈 괜히 n도 인식할까봐..
    } else {
        for (char ch : r) {
            cout << ch << '\n';
        }
    }

    return 0;
}
