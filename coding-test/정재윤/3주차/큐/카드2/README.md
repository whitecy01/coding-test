### 문제이름, 링크
---
- 카드2
- https://www.acmicpc.net/problem/2164

### 생각한 흐름
- queue를 써서 앞에 부분 지워주고 뒤로 넘겨주면 끝

### 코드첨부와 코드 설명
```cpp
#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    queue<int> Q;
    
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        Q.push(i);
    }

    while (Q.size() != 1)
    {
        Q.pop();
        Q.push(Q.front());
        Q.pop();
    }
    cout << Q.front() << "\n";
    
    
}
```