### 문제이름, 링크
---
- 별 찍기 - 2
- https://www.acmicpc.net/problem/2439

### 생각한 흐름
---
- 이중 for문을 사용하여 두 번째 for 문에서 i를 사용하여 별을 찍어낸다.
- n이 5일 때 - 1을 하면 4가 된다. 이때 i는 0부터 시작해서 4까지 갈 터인데 첫 번째 for문에서 j < n - 1 - i을 계산해보면 4,3,2,1,0이런형태로 가게 되고 그 수만큼 공백을 출력하게 된다.
- 두 번쨰 for문에서는 별들을 순차적으로 1~5번 출력을 하면 되는데 i 값을 가지고 이용하면 된다.

## **코드 설명**
```cpp
#include <iostream>

using namespace std;

int main() {
    int n; 

    cin >> n;

    for (int i = 0; i < n; i++){
        for(int j = 0; j < n - 1 - i; j++){
            cout << " ";
        }
        for(int j = i; j >= 0 ; j--){
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