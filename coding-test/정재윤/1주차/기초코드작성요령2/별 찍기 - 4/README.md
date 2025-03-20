### 문제이름, 링크
---
- 별 찍기 - 4
- https://www.acmicpc.net/problem/2440

### 생각한 흐름
---
- 이중 for문을 사용하여 두 번째 for 문에서 i를 사용하여 별을 찍어낸다.
- 첫 번째 for문에서는 공백 출력을 하는데 공백이 0,1,2,3,4이렇게 가되니 i값을 이용해서 공백을 출력하면 된다
- 두 번째 for문에서는 5인 n에서 i값만큼 뺴면서 출력하면 된다.

## **코드 설명**
```cpp
#include <iostream>

using namespace std;

int main() {
    int n; 

    cin >> n;

    for (int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            cout << " ";
        }

        for (int j = 0; j < n - i; j++)
        {
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