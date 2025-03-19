### 문제이름, 링크
---
- 방 번호
- https://www.acmicpc.net/problem/2577

### 생각한 흐름
---
- a,b,c 값을 전부 곱하고 곱한 값이 int 범위를 벗어날 수 있으니 long long으로 처리한다 
- 각 자리수마다 등장 횟수를 구한다음 출력해주면 된다.


### 코드첨부와 코드 설명
```cpp
while (temp) // 등장 횟수 처리하는 코드
{
    int t = temp % 10;
    arr[t]++;
    temp = temp / 10;
}
```