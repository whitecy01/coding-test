#include <iostream>

using namespace std;

int main() {
    int n; 

    cin >> n;

    for (int i = 0; i < n; i++){

        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // cout << "*";
        for(int j = 0; j < 2 * i + 1; j++){
            cout << "*";
        }
        cout << "\n";
    }

    for (int i = 1; i <= n - 1; i++)
    {
        int k = 1;
        for (; k <= i ; k++)
        {
            cout << " ";
        }
        // cout << k;

        for (int j = 0; j < 2 * n - k - i; j++)
        {
            cout << "*";
        }
        // cout << "*";
        cout << "\n";
    }
    
    return 0;
}