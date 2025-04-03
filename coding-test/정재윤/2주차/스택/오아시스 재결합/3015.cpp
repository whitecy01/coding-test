#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  stack<pair<int,int>> sta;
  int n;
  cin >> n;
  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    int cns = 1;
    
    // 스택에 있는 사람들 중에서, 나보다 키가 작거나 같은 사람들은
    // 내가 전부 볼 수 있으므로 처리
    while (!sta.empty() && sta.top().first <= temp)
    {
        ans += sta.top().second;//// 스택 top의 사람 수만큼 쌍을 만들 수 있음
        if ( sta.top().first == temp) cns += sta.top().second; // 키가 같은 놈들은 같이 처리
        sta.pop();  
    }
    
    // 현재 스택이 비어있지 않다는 것은
    // 아직 나보다 키가 큰 사람이 스택에 있다는 것
    // → 나와 그 사람은 서로를 볼 수 있음
    if (!sta.empty()) ans++;
    sta.push({temp, cns});

  }
  cout << ans << "\n";
  

}