#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

   
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; ++j) cout << ' ';                  // 공백 i개
        for (int j = 0; j < 2 * (N - i) - 1; ++j) cout << '*';    // 별 2*(N-i)-1개
        cout << '\n';
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N - i - 1; ++j) cout << ' ';   // 공백 N-i-1개
        for (int j = 0; j < 2 * i + 1; ++j) cout << '*';    // 별 2*i+1개5
        cout << '\n';
    }

    return 0;
}
