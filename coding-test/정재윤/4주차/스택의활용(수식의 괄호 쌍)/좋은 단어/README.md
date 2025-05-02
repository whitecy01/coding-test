### 문제이름, 링크
---
- 좋은 단어
- https://www.acmicpc.net/problem/3986

### 생각한 흐름
첫 번째
1. 첫 번쨰 자리를 push 같은지 안 같은지 보고 
    - 같으면 pop
    - 다르면 push
2. 스택이 남아있으면 count = 0으로 초기화 or 스택이 비어있지 않으면 count += 개수

규칙 찾기
ABAB
AABB -> 이거 2개 == 스택에 아무것도 안 남아있음
ABBA

AAA  == 짝이 하나 지어지긴 했지만 A가 스택에 남아있음
AA -> 1개 == 스택에 아무것도 안 남아있음
AB

ABBABB -> BB가 살아남음 

다시 생각해본 결과 
1. 첫 번째 push
2. 두 번쨰 
    - top이랑 같으면 팝 count ++
    - top 이랑 다르면 그냥 팝

- 이 코드로 했는데 값은 잘 나오는데 계속 틀린다 이유가 뭘까 도저히 모르겠다
```cpp
#include <iostream>
#include <stack>

using namespace std;

string str[1000002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str_temp;
        cin >> str_temp;
        str[i] = str_temp;
    }

    long long count = 0;
    for (int i = 0; i < n; i++)
    {    
        stack<char> sta;
        long long temp_count = 0;
        string str_str = str[i];
        for (int j = 0; j < str_str.size(); j++)
        {
            if (!sta.empty() && str_str[j] == sta.top()){
                sta.pop();
                temp_count++;
            }
            else if (!sta.empty() && str_str[j] != sta.top()){
                sta.pop();
            }
            else{
                sta.push(str_str[j]);
            }
        }
        
        // while (!sta.empty())
        // {
        //     cout << sta.top() << " ";
        //     sta.pop();
        // }
        
        
        
        if (sta.empty())
            count += temp_count;
    }
    cout << count << "\n";
}

```
### 코드첨부와 코드 설명, 틀린 부분
문제를 잘못 이해함
- 나는 이게 각 단어를 하나씩 말하는 줄 알았는데 한 줄에 하나임

```cpp
#include <iostream>
#include <stack>

using namespace std;

string str[1000002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str_temp;
        cin >> str_temp;
        str[i] = str_temp;
    }

    long long count = 0;
    for (int i = 0; i < n; i++)
    {    
        stack<char> sta;
        long long temp_count = 0;
        string str_str = str[i];
        for (int j = 0; j < str_str.size(); j++)
        {
            if (!sta.empty() && str_str[j] == sta.top()){
                sta.pop();
                
            }
            else{
                sta.push(str_str[j]);
            }
        }
        
        if (sta.empty())
            count++;
    }
    cout << count << "\n";
}
```


