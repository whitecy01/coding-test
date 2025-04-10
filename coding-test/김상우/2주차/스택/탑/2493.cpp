#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> height(N);
    for (int i = 0; i < N; i++) {
        cin >> height[i];
    }

    for (int i = 0; i < N; i++) {
        bool found = false;
        for (int j = i - 1; j >= 0; j--) {
            if (height[j] > height[i]) {
                cout << j + 1 << " ";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << 0 << " ";
        }
    }

    return 0;
}
