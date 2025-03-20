#include <iostream>

using namespace std;

int arr[10];

int main(){
    cin.tie(0);
    
    int a,b,c;
    cin >> a >> b >> c;

    long long temp = a * b * c;
    // cout << temp;
    while (temp)
    {
        int t = temp % 10;
        arr[t]++;
        temp = temp / 10;
    }
    
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << "\n";
    }
    
}