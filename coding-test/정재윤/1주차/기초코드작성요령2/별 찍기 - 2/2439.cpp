#include <iostream>

using namespace std;

int main() {
    int n; 

    cin >> n;

    for (int i = 0; i < n; i++){
        for(int j = 0; j < n - 1 - i; j++){
            cout << " ";
        }
        for(int j = i; j >= 0 ; j--){
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}