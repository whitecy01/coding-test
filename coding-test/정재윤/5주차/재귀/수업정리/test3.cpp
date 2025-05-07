#include <iostream>

using namespace std;

int func1(int a, int b, int m){
    int val = 1;
    while (b--)
    {
        val *= a;
    }
    cout << "val : " << val << "\n";
    return val % m;

}
void func2(int a, int b, int m){
    long long val = 1;
    while (b--)
    {
        val *= a;
        cout << val << " ";
    }
    cout << "val : " << val << "\n";
    
}

int main(){
    int ans = func1(6, 100, 5);
    cout << ans << "\n";

    func2(6, 100, 5);
    cout << 60466176 % 5 << "\n";
}