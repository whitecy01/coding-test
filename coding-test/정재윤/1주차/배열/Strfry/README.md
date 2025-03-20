### 문제이름, 링크
---
- 알파벳 개수
- https://www.acmicpc.net/problem/11328

### 생각한 흐름
---
- 문자열 a,b는 각각 등장횟수를 arr_a, arr_b에 체크를 한다. 
- arr_a과 arr_b의 각 똑같은 인덱스의 값들을 검사하는데 둘의 값을 뻇을 때 0이 아니면 만들 수 없기 떄문에 Impossible을 출력한다

## **코드 설명**
```cpp
if (arr_a[k] - arr_b[k] != 0){ // 빼는 부분
    cout << "Impossible" << "\n";
    check = false;
    break;
}
```