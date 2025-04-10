### 문제 이름, 링크
---
- 오아시스 재결합
- https://www.acmicpc.net/problem/3015

### 생각한 흐름

- ...? 쌍..?

### 틀린 부분
- 알고리즘을 모른 관계로 다른 사람 코드참조조

### 코드 첨부 및 설명

```cpp

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int n, cnt;                                // n: 사람 수, cnt: 현재 키와 같은 사람 수
stack<pair<long long, int>> s;            // 스택에 {키, 같은 키 개수} 저장
long long hight;                           // 현재 사람의 키
long long ret;                             // 정답: 볼 수 있는 쌍의 수

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;  // 사람 수 입력

    for (int i = 0; i < n; i++)
    {
        cin >> hight;  // 현재 사람 키 입력
        cnt = 1;       // 같은 키를 가진 사람 수

        while (true)  // 볼 수 있는 앞사람들 pop하며 처리
        {
            if (s.empty())
            {
                // 앞에 아무도 없으면 스택에 push 하고 종료
                s.push({hight, cnt});
                break;
            }
            else if (s.top().first < hight)
            {
                // 스택의 top이 나보다 작으면 pop 가능 → 그 사람과 쌍 가능
                ret += s.top().second;  // 그 사람 수만큼 쌍을 만들 수 있음
                s.pop();                // pop하고 다음 앞사람 확인
            }
            else if (s.top().first == hight)
            {
                // 같은 키라면 모두 볼 수 있음
                ret += s.top().second;   // 같은 키만큼 쌍 추가
                cnt += s.top().second;   // 현재 사람은 같은 키를 하나로 합침
                s.pop();                 // pop하고 다음 앞사람 보기
            }
            else
            {
                // 나보다 키가 큰 사람 발견 → 이 사람은 pop 안 함
                // 단, 이 사람 1명은 볼 수 있으므로 +1
                ret++;
                s.push({hight, cnt});    // 현재 사람 push
                break;                   // 다음 사람으로
            }
        }
    }

    cout << ret;  // 최종 쌍의 수 출력
    return 0;
}


```
- https://coding232624.tistory.com/153#google_vignette
