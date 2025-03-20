### 문제이름, 링크
---
- 별 찍기 - 3
- https://www.acmicpc.net/problem/2440

### 생각한 흐름
---
- 이중 for문을 사용하여 두 번째 for 문에서 i를 사용하여 별을 찍어낸다.
- n이 5일때 i는 0부터 5까지 갈터이니 n에서 i만큼 빼준 만큼 별을 찍어내면 된다.

## **코드 설명**
```cpp
#include <iostream>

using namespace std;

int main() {
    int n; 

    cin >> n;

    for (int i = 0; i < n; i++){
        for(int j = 0; j < n - i; j++){
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}
예제 출력 
*****
****
***
**
*
```