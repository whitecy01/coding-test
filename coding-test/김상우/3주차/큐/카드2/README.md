### 문제 이름, 링크
---
- 카드2
- https://www.acmicpc.net/problem/2164


### 생각한 흐름
- 1부터 N가지 번호가 적힌 카드
- 제일 위의 카드르 버리고
- 그 다음 카드를 제일 아래로 옮긴다.
- 마지막에 남는 카드 번호는?

- 제일 위 카드를 pop() 으로 버리고.
- 다음 카드를 아래로 보낸다.
- push(q.front())
- 보낸 카드 삭제. q.pop() 끝.

- q.size가 1이 될때까지?


### 코드 첨부 및 설명

```cpp 

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    queue<int> q;

    // 큐에 입력. n까지 해주고고
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    // q.size가 1보다 클때까지 while 반복복
    while (q.size() > 1) {
        q.pop();                 
        // 제일 위 카드 버리기
        q.push(q.front());      
        // 다음 카드 제일 아래로
        q.pop();                
        // 제일 앞 카드 삭제
    }

    // 마지막 남은 카드 출력
    cout << q.front() << '\n';

    return 0;
}



```