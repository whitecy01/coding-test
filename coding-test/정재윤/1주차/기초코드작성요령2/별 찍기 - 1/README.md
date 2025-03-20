### 문제이름, 링크
---
- 별 찍기 - 1
- https://www.acmicpc.net/problem/2438

### 생각한 흐름
---
- 이중 for문을 사용하여 두 번째 for 문에서 i를 사용하여 별을 찍어낸다.
- i는 첫 번째로 0이 될테니 j를 i만큼 가게 하면 별이 순차적으로 나온다.

## **코드 설명**
```cpp
#include <iostream>

using namespace std;

int main() {
    int n; 

    cin >> n;

    for (int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) 
        { 
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}
예제 출력 
*
**
***
****
*****
```