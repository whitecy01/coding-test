#include <iostream>
using namespace std;

void func(int a, int b, int n){ // a : 시작 기둥 번호, b : 도착 기둥 번호, n : 옮겨야 하는 원판의 개수
  if(n == 1){
    cout << a << ' ' << b << '\n';
    return;
  }
  func(a, 6-a-b, n-1); 
  cout << a << ' ' << b << '\n';
  func(6-a-b, b, n-1);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k;
  cin >> k;
  cout << (1<<k) - 1 << '\n';
  func(1, 3, k);
}