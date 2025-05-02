### 문제 이름, 링크
---
- 쇠막대기기
- https://www.acmicpc.net/problem/10799


### 생각한 흐름

- 우선 스택을 활용할 예정이다.
- 쇠막대기는 자신보다 긴 쇠막대기 위에만 놓일 수 있다. 쇠막대기를 다른 쇠막대기 위에 놓는 경우 완전히 포함되도록 놓되, 끝점은 겹치지 말아야 한다.
- 긴 쇠막대기를자르는 레이저는 적어도 하나 존재한다.
- 레이저는 어떤 쇠막대기의 양 끝점과도 겹치지 않는다.

- 레이저는 여는 괄호와 닫느 괄호의 인접한 쌍 () 으로 표현된다. 모든 () 는 반드시 레이저를 표현한다.
- 쇠막대기의 왼쪽 끝은 여는 괄호 `(` 로 오른쪽 끝은 닫힌 괄호 `)`로 표현된다.

- 즉 () 는 레이저 ( ) 는 3칸짜리 쇠막대기를 뜻한다. `(` 가 쇠막대기의 시작 점 `)` 가 끝점.
- 잘랐을때 잘려진 쇠막대기 조각의 총 개수를 구하는 문제.
- 그렇다면 `(`가 나오면 그대로 push 와 동시에 쇠막대기 수 + 1 증가. `)` 가 나오면 pop 이후 쇠막대기 수 - 1 을 한다고 가정한다.
- `(`가 push되고 바로 `)` 가 pop되면 레이저로 간주하여 이제껏 push된 쇠막대기들을 모두 자른다 즉 쇠막대기 수 X 2 하면 조각의 수가 된다. 

### 틀린 부분
- 틀림.
```cpp
// 기존 코드
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string str;
    cin >> str;

    stack<char> s;
    int count = 0;     
    int result = 0;       

    for (int i = 0; i < str.size(); i++) {
        char c = str[i];

        if (c == '(') {
            s.push('(');
            count++; 
        } else {
            s.pop();  
            count--; 

            if (str[i - 1] == '(') {
               
                result += count * 2;
            } else {
                result += 1;
            }
        }
    }

    cout << result << '\n';
    return 0;
}




```

### 코드 첨부 및 설명

```cpp
// gpt가 고쳐준 코드.

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    stack<char> s;
    int result = 0;

    for (int i = 0; i < str.size(); i++) {
        char c = str[i];

        if (c == '(') {
            // 여는 괄호는 스택에 push
            s.push(c);
        } else {
            // 닫는 괄호가 나올 때 pop

            s.pop(); 

            if (str[i - 1] == '(') {
                // 바로 앞이 '(' → 레이저임.
                
                result += s.size(); // s.size()...???????????? why? 왜지?
            } else {
                // 바로 앞이 ')' → 막대기 끝
                // 조각 1개 추가됨
                result += 1;
            }

        }
    }

    cout << result << '\n';
    return 0;
}



```

- 이 코드는 맞았따. 뭐가 다른거고 뭐가 틀린지 모르겠다. 내가 보기엔 똑같아 보인다.