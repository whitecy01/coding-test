#include <iostream>

using namespace std;

int main() {
    int n; 

    cin >> n;

    for (int i = 0; i < n; i++){
        int j = 0;
        for (; j < i; j++)
        {
            cout << " ";
        }
        
        for (int q = 0; q < 2 * n - (i + j + 1); q++)
        {
            cout << "*";
        }
        cout << "\n";
    }

    for (int i = 1; i < n; i++){
      
        for (int j = 0; j < n - 1 - i; j++)
        {
            cout << " ";
        }
        for (int q = 0; q < 2 * i + 1; q++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}