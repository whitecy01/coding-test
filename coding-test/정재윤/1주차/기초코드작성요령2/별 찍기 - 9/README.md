### 문제이름, 링크
---
- 별 찍기 - 9
- https://www.acmicpc.net/problem/2446

### 생각한 흐름
---
- 이중 for문을 2개 사용한다.
- 별의 갯수가 9,7,5,3,1로 찍히는 거 하나, 3,5,7,9로 찍히는 거 하나 이렇게 해서 진행하면 된다.
- 첫 번째 큰 for 문에서 공백부터 처리를 하고, 별을 찍는다.

    - 별을 찍을 때 N의 값을 이용해서 9,7,5,3,1을 만들어주면 된다.
- 두 번쨰 큰 for문에서는 반대로 해주면 된다.

    - 반대로 i를 사용해서 3,5,7,9를 만들어주면 된다.

## **코드 설명**
```cpp
#include <iostream>

using namespace std;

int main() {
    int n; 

    cin >> n;

    for (int i = 0; i < n; i++){
        int j = 0;
        for (; j < i; j++)
        {
            cout << " ";
        }
        
        for (int q = 0; q < 2 * n - (i + j + 1); q++)
        {
            cout << "*";
        }
        cout << "\n";
    }

    for (int i = 1; i < n; i++){
      
        for (int j = 0; j < n - 1 - i; j++)
        {
            cout << " ";
        }
        for (int q = 0; q < 2 * i + 1; q++)
        {
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
   ***
  *****
 *******
*********
```