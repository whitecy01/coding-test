#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[202];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int v;
    cin >> v;

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == v) {
            count++;
        }
    }

    cout << count;
    return 0;
}