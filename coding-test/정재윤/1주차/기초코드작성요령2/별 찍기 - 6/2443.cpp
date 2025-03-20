#include <iostream>

using namespace std;

int main() {
    int n; 

    cin >> n;

    for (int i = 0; i < n; i++){

        int k = 0;
        for (; k < i; k++)
        {
            cout << " ";
        }

        for(int j = 0; j < 2 * n - (i + 1 + k); j++){
            cout << "*";
        }
        
        cout << "\n";
    }
    return 0;
}