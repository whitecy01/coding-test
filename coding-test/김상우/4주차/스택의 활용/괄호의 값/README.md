### 문제 이름, 링크
---
- 괄호의 값
- https://www.acmicpc.net/problem/2504

### 생각한 흐름

- () = 2
- [] = 3

- (X) = 2 x X
- [X] = 3 x X
- XY = X + Y

- 스택의 활용 문제이기 때문에 스택으로 풀어봐야한다.
- 우선 괄호가 닫힐때 계산한다고 생각하면 될 듯.
- 스택으로 괄호 짝을 맞출 예정이다.
- 열린 괄호가 나오면 push 닫힌 괄호가 나오면 계산과 동시에 pop하여 짝을 맞추며 계산까지 하면 된다.
- stack에 숫자가 나와도 push 이후 () 또는 [] 는 숫자 2 와 3으로 계산된다.
- 그럼 (()) 는 4인가?
- ? 어떻게 풀지..

### 틀린 부분



### 코드 첨부 및 설명

```cpp 

#include <iostream>   
#include <stack>     
#include <string>     
using namespace std;

int main() {
    string str;
    cin >> str; 

    stack<char> s;     
    stack<int> value;   

    bool valid = true; 

    
    for (char c : str) {
        if (c == '(' || c == '[') {
            // 여는 괄호면 괄호 스택에 넣고,
            // 계산용 스택에는 0 넣어서 구간을 나눔
            s.push(c);
            value.push(0);
        } else {
            // 닫는 괄호인데 스택이 비어 있다? → 짝이 없음
            if (s.empty()) {
                valid = false;
                break;
            }

            char top = s.top(); // 최근 열린 괄호 확인
            s.pop();            // 짝이 맞았다고 가정하고 pop

            int temp = 0;

            // 계산 스택에서 괄호 안에 있던 값들을 꺼냄 (0 이전까지)
            while (!value.empty() && value.top() != 0) {
                temp += value.top();
                value.pop();
            }

            // 괄호 열림이 없었는데 닫힘만 나왔다? → 잘못된 입력
            if (value.empty()) {
                valid = false;
                break;
            }

            value.pop(); // 열렸던 구간 구분용 0 제거

            // 괄호 종류에 따라 계산 처리
            if (c == ')' && top == '(') {
                // () → 2, (X) → 2 * X
                value.push(temp == 0 ? 2 : 2 * temp);
            } else if (c == ']' && top == '[') {
                // [] → 3, [X] → 3 * X
                value.push(temp == 0 ? 3 : 3 * temp);
            } else {
                // 짝이 안 맞는 괄호 (예: (] 같은 거)
                valid = false;
                break;
            }
        }
    }

    // 에러거나 괄호가 다 닫히지 않았을 경우
    if (!valid || !s.empty()) {
        cout << 0 << '\n';
    } else {
        int result = 0;

        // 계산된 값들 다 더해서 출력
        while (!value.empty()) {
            result += value.top();
            value.pop();
        }

        cout << result << '\n';
    }

    return 0;
}


/*
설명에 도움이 될 스택 상태 변화

 S                         value                     
(         | (            | 0                  | 여는 괄호 → 0 push
(         | ( (          | 0 0                | 또 여는 괄호 → 또 0 push
)         | (            | 0 2                | () → 2 계산 후 push
[         | ( [          | 0 2 0              | 여는 [ → 또 0 push
[         | ( [ [        | 0 2 0 0            | 여는 [ → 또 0 push
]         | ( [          | 0 2 0 3            | [] → 3 계산 후 push
]         | (            | 0 2 9              | [3×3] → 9 계산 후 push
)         |              | 28                 | (2+9)×2 = 28


*/





```