#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string a, b;
        cin >> a >> b;

        int arr1[26] = {0};
        int arr2[26] = {0};

        for (char ch : a) arr1[ch - 'a']++;
        for (char ch : b) arr2[ch - 'a']++;

        bool possible = true;
        for (int i = 0; i < 26; i++) {
            if (arr1[i] != arr2[i]) {
                possible = false;
                break;
            }
        }

        cout << (possible == true ? "Possible" : "Impossible") << '\n';
    }

    return 0;
}