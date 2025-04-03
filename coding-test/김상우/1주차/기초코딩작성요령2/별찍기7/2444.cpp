#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    // 총 줄 수는 2n-1
    for(int i = 1; i <= 2 * n - 1; i++){

        if(i <= n){
            // n보다 작을때
            for(int j = 0; j < n - i; j++)
                cout << " ";
            for(int j = 0; j < 2 * i - 1; j++)
                cout << "*";
        }
        else{
            //n 보다 클때때
            for(int j = 0; j < i - n; j++)
                cout << " ";
            for(int j = 0; j < 2 * (2 * n - i) - 1; j++)
                cout << "*";
        }

        cout << "\n";
    }
    return 0;
}
