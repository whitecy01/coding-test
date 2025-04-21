### 문제이름, 링크
---
- 쇠막대기
- https://www.acmicpc.net/problem/10799

### 생각한 흐름
- 바킹독 힌트
이 문제의 경우 괄호 쌍을 볼 때 지금 보고 있는 이 닫힌 괄호가 레이저를 의미하는지 쇠막대기를 의미하는지는 그 앞의 괄호를 보면 알 수 있을 것이다.
그리고 레이저를 쏠 때 몇 개의 막대기가 잘려나가는지는 그 순간에 스택의 길이와 연관해서 생각해보면 느낌이 올 수도 있다.

1. 현재 위치에서 '(' 그리고 ')'
    -> ans += stack.size()
2. stack이 안 비어있고 sta.top이랑 str[i]의 짝 체크 '(', ')'
    -> 맞으면 ans++;, sta.pop();
- ++을 해주는 이유가 막대기가 사라질 때 반으로 잘렸으면 오른쪽 꺼까지 체크해야하기 때문
3. sta.push();


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
    int ans = 0;
    for (int i = 0; i < str.size(); i++)
    {
        char first = str[i];
        char second = str[i + 1]; 
        // cout << "i : " << i << "  first : " << first << " second : " << second <<"\n";
        if (first ==  '(' && second == ')'){
            ans += sta.size();
            // cout << "1. i : " << i << "  ans : " << ans <<"\n";
            // if (i < str.size()- 1)
            i++;
        }
        else if (!sta.empty() && sta.top() == '(' && first == ')'){
            // cout << "2. i : " << i << "  ans : " << ans << " sta.size() : " << sta.size() << "\n";
            ans++;
            sta.pop();
        }else{
            sta.push(first);
            // cout << "3. i : " << i << "  ans : " << ans <<"\n";
        }
    }
    cout << ans << "\n";
    
}
```


