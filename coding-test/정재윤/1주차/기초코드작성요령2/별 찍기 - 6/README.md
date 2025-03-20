### 문제이름, 링크
---
- 별 찍기 - 6
- https://www.acmicpc.net/problem/2443

### 생각한 흐름
---
- 이중 for문을 사용하여 두 번째 for 문에서 i를 사용하여 별을 찍어낸다.
- 첫 번째 for문에서 공백을 처리한다. n이 5일 때 i가 0에서 4까지 가게 되는데 이 값을 이용해서 순차적으로 공백을 출력한다
- 두 번쨰 for문에서는 i가 0~5까지 가는데 
    - 2 * 5 - (0 + 1 + 0)은 9
    - 2 * 5 - (1 + 1 + 1)은 7
    - 2 * 5 - (2 + 1 + 2)은 5
    - 이 형태에 맞게 별을 출력하면 된다.

## **코드 설명**
```cpp
#include <iostream>

using namespace std;

int main() {
    int n; 

    cin >> n;

    for (int i = 0; i < n; i++){

        int k = 0;
        for (; k < i; k++)
        {
            cout << " ";
        }

        for(int j = 0; j < 2 * n - (i + 1 + k); j++){
            cout << "*";
        }
        
        cout << "\n";
    }
    return 0;
}
예제 출력 
*********
 *******
  *****
   ***
    *
```