### 문제이름, 링크
---
- 별 찍기 - 8
- https://www.acmicpc.net/problem/2445

### 생각한 흐름
---
- 이중 for문을 2개 사용한다. n이 5개일 떄 별이 9개까지 출력되는 부분인가 그 밑에 2개로 나눈다.
- 큰 두 개의 for문에서 또 2개의 종류로 나눈다.
- 첫 번째 큰 for 문에서 공백부터 처리를 하고, 별을 찍는다.

    -  첫 번쨰에서는 공백을 먼저 별의 갯수가 필요한 1,2,3,4,5 만큼 별을 찍는 for문 1개
    -  4,3,2,1 순으로 가는 공백처리를 하나 하는 for문
    - 4,3,2,1 순으로 가는 공백처리를 하나 하는 for문
    - 나머지 1,2,3,4,5 형태로 가는 별 찍는 for문
- 두 번쨰 큰 for문에서는 반대로 해주면 된다.

## **코드 설명**
```cpp
#include <iostream>

using namespace std;

int main() {
    int n; 

    cin >> n;

    for (int i = 0; i < n; i++){

        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < n - 1 - i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < n - 1 - i; j++)
        {
            cout << " ";
        }

        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        // cout << "*";
        // for(int j = 0; j < 2 * i + 1; j++){
        //     cout << "*";
        // }
        cout << "\n";
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "*";
        }
        for (int j = 0; j <= i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "*";
        }
        

        cout << "\n";
    }
    
    
    return 0;
}
예제 출력 
*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *
```