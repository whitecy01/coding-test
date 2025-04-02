#include <iostream>
#include <string>
using namespace std;

int main() {


    string a, b;
    cin >> a >> b;

    int A[26] = {0};
    int B[26] = {0};
    
    for (char ch : a) A[ch - 'a']++;
    for (char ch : b) B[ch - 'a']++;

    int dd = 0;
    for (int i = 0; i < 26; i++) {
        if (A[i] > B[i]) {
            dd += A[i] - B[i];
        } else {
            dd += B[i] - A[i];
        }
    }

    cout << dd;
    return 0;
}