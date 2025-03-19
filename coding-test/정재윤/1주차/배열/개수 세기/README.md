### 문제이름, 링크
---
- 개수 세기
- https://www.acmicpc.net/problem/10807

### 생각한 흐름
---
- arr 배열을 만들어서 각 숫자들이 나오는 횟수를 찾으면 된다.
- 이떄 문제가 발생한다 v는 -100보다 크거나 같으면 100보다 작거나 같다라는 조건이 나온다. 음수의 형태의 인덱스를 해결해주기 위해 abs를 사용해 절댓값으로 음수일 경우 인덱스 범위는 + 100을 해주어 해결

### 코드첨부와 코드 설명
```cpp
#include <iostream>
#include <algorithm>
using namespace std;


int arr[500] = {0};
int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp < 0){
            temp = abs(temp) + 100; // 음수 해결
        }
        arr[temp]++;
    }
    int v; 
    cin >> v;
    if (v < 0){
        v = abs(v) + 100; // 음수 해결
    }
    cout << arr[v] << "\n";
}
```