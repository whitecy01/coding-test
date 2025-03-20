### 문제이름, 링크
---
- 별 찍기 - 7
- https://www.acmicpc.net/problem/2444

### 생각한 흐름
---
- 이중 for문을 2개 사용한다. n이 5개일 떄 별이 9개까지 출력되는 부분인가 그 밑에 2개로 나눈다.
- 첫 번째 큰 for 문에서 공백부터 처리를 하고, 별을 찍는다.
- 두 번쨰 큰 for문에서 마찬가지로 공백부터 처리를 하고, 별을 찍는다.

## **코드 설명**
```cpp
#include <iostream>

using namespace std;

int main() {
    int n; 

    cin >> n;

    for (int i = 0; i < n; i++){

        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // cout << "*";
        for(int j = 0; j < 2 * i + 1; j++){
            cout << "*";
        }
        cout << "\n";
    }

    for (int i = 1; i <= n - 1; i++)
    {
        int k = 1;
        for (; k <= i ; k++)
        {
            cout << " ";
        }
        // cout << k;

        for (int j = 0; j < 2 * n - k - i; j++)
        {
            cout << "*";
        }
        // cout << "*";
        cout << "\n";
    }
    
    return 0;
}
예제 출력 
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
```