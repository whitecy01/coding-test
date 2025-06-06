### 문제 이름, 링크
---
- 회전하는 큐
- https://www.acmicpc.net/problem/1021

### 생각한 흐름
- 입력값 N 과 M을 받음.
- N은 원소의 개수 M은 뽑아내려고 하는 수의 개수

- 3가지 연산 수행 가능

1. 첫 번째 원소를 뽑아낸다. 이 연산을 수행하면, 원래 큐의 원소가 a1, ..., ak이었던 것이 a2, ..., ak와 같이 된다.
2. 왼쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 a2, ..., ak, a1이 된다.
3. 오른쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 ak, a1, ..., ak-1이 된다.

- 여기서 입력값으로 N은 덱을 채우는데 사용.
- M 만큼 반복시키기 위해 while 문으로 활용.
- 다음 원소가 주어질때 해당 원소를 출력하기 위한 연산(2번, 3번)의 최솟값.
- 연산을 보면 왼쪽 한칸 이동 시 front 가 back으로 이동
- 오른쪽 이동 시 back이 front로 이동. pop은 첫번째 인덱스만 뽑음.

- 예제를 보면 1 2 3 같은 경우 출력이 0 즉 front_pop만 하면 2번 3번 연산은 안들어감으로 0
- 총 연산 횟수를 구하기 위한 변수 하나 둠.
- 2 9 5 일때 덱의 최대 값은 10 이럴 경우의 최소값은 2번 연산 1번 -> 3번 연산 3번 -> 3번 연산 4번
- 1 2 3 4 5 6 7 8 9 10 
- 2 3 4 5 6 7 8 9 10 1 (2번 1)
- 3 4 5 6 7 8 9 10 1    
- 1 3 4 5 6 7 8 9 10    (3번 1)
- 10 1 3 4 5 6 7 8 9    (3번 2)
- 9 10 1 3 4 5 6 7 8    (3번 3)
- 10 1 3 4 5 6 7 8
- 1 3 4 5 6 7 8 10      (3번 4)
- 3 4 5 6 7 8 10 1      (3번 5)
- 4 5 6 7 8 10 1 3      (3번 6)
- 5 6 7 8 10 1 3 4      (3번 7)
- 6 7 8 10 1 3 4     
- 총 8번.

- 그렇다면 2번 과 3번을 다음 입력값에 따라 최소값이 나오게 해야한다. 이걸 어떻게 하나..?


### 틀린 부분
- 최솟값을 어떻게 구해야할지 감이 안잡힘.


### 코드 첨부 및 설명

```cpp

#include <iostream>     
#include <deque>        
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; 

    deque<int> dq;
    for (int i = 1; i <= n; i++) {
        dq.push_back(i); 
    }

    int total_ops = 0;  // 총 연산 횟수

    while (m--) { 
        int target;
        cin >> target;  // 이번에 뽑아야 할 숫자

        int idx = 0;
        // 덱 안에서 target이 몇 번째 위치에 있는지 찾기
        for (int i = 0; i < dq.size(); i++) {
            if (dq[i] == target) {
                idx = i;  // 찾은 위치 저장
                break;
            }
        }

        // 덱의 앞쪽 절반에 위치한다면 → 왼쪽으로 회전
        if (idx <= dq.size() / 2) {
            // 덱의 맨 앞이 target이 될 때까지 왼쪽 회전
            while (dq.front() != target) {
                dq.push_back(dq.front());  // 맨 앞 값을 맨 뒤로 보냄
                dq.pop_front();            // 맨 앞 제거
                total_ops++;               // 연산 횟수 증가
            }
        } 
        // 덱의 뒷쪽 절반에 위치한다면 → 오른쪽으로 회전
        else {
            while (dq.front() != target) {
                dq.push_front(dq.back());  // 맨 뒤 값을 맨 앞에 삽입
                dq.pop_back();             // 맨 뒤 제거
                total_ops++;               // 연산 횟수 증가
            }
        }

        // 맨 앞이 target이므로 제거 (이건 연산 횟수에 포함 X)
        dq.pop_front();
    }

    // 총 회전 연산 횟수 출력
    cout << total_ops << endl;
    return 0;
}


```
