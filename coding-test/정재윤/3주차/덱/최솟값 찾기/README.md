### 문제이름, 링크
---
- 최솟값 찾기
- https://www.acmicpc.net/problem/11003

### 생각한 흐름
- 이 문제는 문제에 대해 생각을 잘해봐야한다.
- 문제에서 D_i = A_i-L+1 ~ A_i 을 이야기 했는데
i가 0에서부터 3까지 된다고 가정하고 L은 3, N은 12라고 한다면
i = 0; D_0 = A_0-3+1 = A_-2 
i = 1; D_1 = A_1-3+1 = A_-1
i = 2; D_2 = A_2-3+1 = A_0

즉 
12 3
1 5 2 3 6 2 3 7 3 5 2 6
이렇게 값이 들어왔을 때
i = 0 번째 인덱스부터 -2 인덱스까지 3자리 중 최솟값을 찾는 것 
i = 1 번째 인덱스부터 -1 인덱스까지 3자리 중 최솟값을 찾는 것 


### 틀린 부분
- 처음에 
```cpp
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(){
    int n, L;
    cin >> n >> L;

    vector<int> vec;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }

    deque<int> D;
    for (int i = 0; i < n; i++)
    {
        int order = i - L + 1;
        int check = L;
        while (check--)
        {
            if(order >= 0){
                if (!D.empty() && D.front() > vec[i]){
                    D.pop_front();
                    D.push_back(vec[i]);
                }
                else 
                    D.push_back(vec[i]);
            }
            order++;
        }
        cout << D.front() << " ";
        D.pop_front();
        
    }
}
```
- 위 코드 처럼 풀었는데 계속 틀림 그래서 구현 부분이 너무 막혀서 바킹독님 코드를 봄
- pair를 사용해서 deque를 만듦 -> 이게 첫 번째는 인덱스의 위치 i값, 뒤에는 숫자값을 넣음
- deque를 오름차순 상태로 유지한다. 가장 작은 값은 항상 front에 가장 큰 값은 마지막에 위치하도록 함
알고리즘
1. 새로운 숫자는 항상 삽입
2. first의 값을 이용해 L값이 넘어가는 front는 삭제
3. 들어온 num이 deque back과 비교했을 때 dq가 더 크면 pop_back을 해서 오름차순을 만들어주는 과정

이렇게 되면 자동적으로 L번씩 보면서 최솟값이 front에 자동 저장됨

### 코드첨부와 코드 설명
```cpp
// Authored by : unluckyjung
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/a3aef39bd578432d814a0be26957bc9c
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  deque<pair<int, int>> dq;

  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;

    // 새로운 숫자가 deque내에서 가장 큰 값의 숫자이고 마지막에 위치하도록 합니다.
    // deque안의의 숫자들은 오름차순 상태를 유지하게 되고, 구간내 가장 작은값은 항상 맨앞(front)에 있는 상태를 가지게 됩니다.
    while (!dq.empty() && dq.back().second >= num) {
      dq.pop_back();
    }
    
    // 새로운 숫자는 항상 삽입됩니다.
    dq.push_back({i, num});

    // 주어진 구간을 벗어나는 outdate된 숫자들은 제거해줍니다.
    if (dq.front().first <= i - m) {
      dq.pop_front();
    }

    cout << dq.front().second << " ";
  }

  return 0;
}
```