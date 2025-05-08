#include <iostream>
using namespace std;


using ll = long long;
ll POW(ll a, ll b, ll c){
    if(b==1) return a % c;
    ll val = POW(a, b/2, c); // 여기에서 계속 b를 2로 나누는 작업으로 최종적으로 b == 1을 목표로 함.
    val = val * val % c; // 위 함수 호출이 끝나면 스택에 쌓인 대로 POP 되며 이
    if(b%2 == 0) return val; //base condition
    return val * a % c;
}