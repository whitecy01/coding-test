### 문제이름, 링크
---
- 제로
- https://www.acmicpc.net/problem/10773

### 생각한 흐름
- stack을 만들어 입력받은 수가 0이 아니면 sta.push를 진행하고 아니면 sta.pop을 한다. pop을 할 때 sta가 비어있으면 pop을 하지 않는다.
- 입력값을 다 처리한 후 pop을 하며 다 더해준다.

### 코드첨부와 코드 설명
```cpp
#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;

    int ans = 0;
    stack<int> sta;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if (num == 0){
            if (!sta.empty()) // pop 하는 부분
                sta.pop();
        }
        else
            sta.push(num); /// push 하는 부분
    }
    int size_sta = sta.size();
    for (int i = 0; i < size_sta; i++)
    {
        ans += sta.top();
        sta.pop();
    }
    cout << ans << "\n";
    
    
}
```