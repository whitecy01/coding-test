#include <iostream>

using namespace std;

int ans = 0;
void fun2(int n){
    if (n == 0)
        return ;
    fun2(--n);
    ans += n;
}

void fun1(int n){
    if (n == 0)
        return;
    cout << n << " ";
    fun1(--n);
}

int main(){
    int n = 10;
    fun1(n);
    cout << "\n";
    fun2(n);
    cout << ans << "\n";
}