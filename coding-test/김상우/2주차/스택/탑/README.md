### 문제 이름, 링크
---
- 탑
- https://www.acmicpc.net/problem/2493

### 생각한 흐름
- 탑은 항상 왼쪽으로 신호를 보냄.
- 신호를 보낸 탑보다 작은 탑은 신호를 받지 못함.
- 즉 스택 top이 낮은 탑이면 pop 높은 탑일 경우 레이저를 받은 탑
- 출력예시에서 6과  9 는 0 5와 7은 2 4는 4..? 
-  수신 받는 탑을 출력할텐데? 2라는 탑은 존재하지 않음. 뭐임?
- 아 수신 받는 탑들의 개수를 출력하라는 듯?
- 아니네..몇번째 탑에서 수신 받았는 지를 출력함.
- 스택 인덱스를 어떻게 쓰는지 모르니.. 배열을 사용.
- vector 높이를 입력값으로 채워주고
- i 와 j 위치의 인덱스를 확인. 만약 *j 가 *i보다 크다면 j 출력.

- 없을 경우를 bool을 false로 두고 0 출력.

### 틀린 부분

- cout << j << " ";  -> 탑 번호는 1부터 시작이기 때문에
- cout << j + 1 << " "; + 1 하는게 맞음.
- 시간 초과. 다른 사람 코드 봐야할 듯?

### 코드 첨부 및 설명

```cpp

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> height(N);
    for (int i = 0; i < N; i++) {
        cin >> height[i];
    }

    for (int i = 0; i < N; i++) {
        bool found = false;
        for (int j = i - 1; j >= 0; j--) {
            if (height[j] > height[i]) {
                cout << j + 1 << " ";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << 0 << " ";
        }
    }

    return 0;
}





```