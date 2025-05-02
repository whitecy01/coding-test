### 문제이름, 링크
---
- 괄호의 값
- https://www.acmicpc.net/problem/2504

### 생각한 흐름
- 뭔가 스택에 넣을 때 pair를 사용해서 넣는 걸 생각을 하긴 함.. 그런데 어떻게 풀어나가야 하지?
- 아 이건 도저히 모르겠다

### 참조 -> 이 문제 못품
- sum, num을 따로 두어 계싼
num은 현재까지 중첩된 깊이
- 여는 괄호를 만나면 '(', '['는 각각 num에 2, 3을 곱함
- 닫는 괄호를 만나면
    -> if 현재 위치에서 전에 닫는 괄호가 확실하면 sum += num을 진행 -> 이게 그냥 2,3을 더하는 거 
    -> sta.pop()
    -> num /= 2(3)
- 그냥 닫는 괄호를 만나면 곱하고 현재 위치 한 칸 앞에서 여는 괄호가 똑같은 게 처음 만나는 닫는 괄호를 기점으로 깊이가 끝났으니 sum에 더해주고 각 괄호에 맞는 걸 num에 나누기 연산해주어서 깊이를 빠져나옴 

### 코드첨부와 코드 설명, 틀린 부분
```cpp
#include <iostream>
#include <stack>

using namespace std;

stack<char> sta;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    int sum = 0;
    int num = 1;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '('){
            num *= 2;
            sta.push(str[i]);
        }
        else if (str[i] == '['){
            num *= 3;
            sta.push(str[i]);
        }
        else {
            if (str[i] == ')'){
                if (sta.empty() || sta.top() != '('){
                    cout << 0;
                    return 0;
                }
                if (str[i - 1] == '(') sum += num;
                sta.pop();
                num /= 2;
            }
            else{
                if (str[i] == ']'){
                    if (sta.empty() || sta.top() != '['){
                        cout << 0;
                        return 0;
                    }
                    if (str[i - 1] == '[') sum += num;
                    sta.pop();
                    num /= 3;
                }
            }
        }

    }
    cout << sum << "\n";
}
```


