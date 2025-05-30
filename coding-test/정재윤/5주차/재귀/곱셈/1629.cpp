#include <iostream>

using namespace std;

long long func(long long a, long long b, long long c){
    if (b == 1) return a % c;
    long long val = func(a, b/2, c);
    val = val * val % c;
    if ( b %2 == 0) return val;
    return val * a % c;
}


int main(){
    long long a,b,c;
    cin >> a >> b >> c;

    long long ans = func(a,b,c);
    cout << ans << "\n";
}