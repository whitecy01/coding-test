### 문제이름, 링크
---
- 알파벳 개수
- https://www.acmicpc.net/problem/1919

### 생각한 흐름
---
- a에서 각 알파벳의 등장 횟수를 arr_a에 담아준다.
- b문자열을 검사하면서 등장 횟수를 arr_a에서 뺴준다.
- arr_a에 a와 b에 각각 등장하지 않았던 알파벳이 전부 arr_a에 남게 된다 음수 처리를 위해 abs를 사용해서 다 더 해준다.
## **코드 설명**
```cpp
ans += abs(arr_a[i]); // 전부 다 더해주는 부분
```