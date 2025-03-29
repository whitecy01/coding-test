### 문제이름, 링크
---
- 스택 수열
- https://www.acmicpc.net/problem/1874

### 생각한 흐름

### 틀린 부분
- 처음에 문제를 잘못 이해해서 입력한 수를 오름차순으로 정렬할 수 있는지 물어보는 줄 알았다
- 그게 아니고 먼저 1부터 8까지 숫자가 있다.
```cpp
8
5
3
6
8
7
5
2
1
```
{1}
{1,2}
{1,3}
{1,2,3} = result{4};
{1,2} = result{4,3};
{1,2,5} = result{4,3};
{1,2,5,6} = result{4,3};
{1,2,5} = result{4,3,6};
{1,2,5,7} = result{4,3,6};
{1,2,5,7,8} = result{4,3,6};
{1,2,5,7} = result{4,3,6,8};
{1,2,5} = result{4,3,6,8,7};
{1,2} = result{4,3,6,8,7,5};
{1} = result{4,3,6,8,7,5,2};
{} = result{4,3,6,8,7,5,2,1};

- 이렇게 되기에 1에서 8을 저장하는 무언가가 필요하다 그걸 queue를 이용해서 플오야한다.
- 밑 테스트 케이스가 왜 안 되는지 보자
```cpp
5
1
2
5
3
4
```
{1} 
{} = result{1}
{2} = result{1}
{} = result{1,2}
{3} = result{1,2}
{3,4} = result{1,2}
{3,4,5} = result{1,2}
{3,4} = result{1,2,5}
- 여기서 막혀버린다. 문제에서 스택에 push하는 순서는 반드시 오름차순이라고 했는데 queue에 있는 값을 push할 때의 오름차순을 지켜야한다는 말이다.



### 코드첨부와 코드 설명
```cpp
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

stack<int> sta;
queue<int> Q;
queue<char> ans;


int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        Q.push(temp);
    }
    
    int l = 1;
    while (!Q.empty())
    {
        if (sta.size() && sta.top() == Q.front()){
                sta.pop();
                Q.pop();
                ans.push('-');
        }
        else if (l <= Q.front()){
            while (l <= Q.front())
            {
                sta.push(l++);
                ans.push('+');
            }
        }
        else {
            cout << "NO\n";
            return 0;
        }
    }
    while (ans.size())
    {
        cout << ans.front() << "\n";
        ans.pop();

    }
}

```