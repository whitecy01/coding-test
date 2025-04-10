### 문제이름, 링크
---
- 큐 2
- https://www.acmicpc.net/problem/18258

### 생각한 흐름
- 그냥 함수에 맞춰서 풀면 됨

### 코드첨부와 코드 설명
```cpp
#include <iostream>
#include <queue>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    queue<int> qu;

    int n;

    cin >> n;

    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str == "push")
        {
            int num;
            cin >> num;
            qu.push(num);
        }
        else if (str == "pop"){
            if (!qu.empty())
            {
                cout << qu.front() << "\n";
                qu.pop();
            }
            else
                cout << "-1\n";
        }
        else if (str == "size"){
            cout << qu.size() << "\n";
        }
        else if (str == "empty"){
            cout << qu.empty() << "\n";
        }
        else if (str == "front"){
            if (!qu.empty())
                cout << qu.front() << "\n";
            else 
                cout << "-1\n";
        }
        else if (str == "back"){
            if (!qu.empty())
                cout << qu.back() << "\n";
            else 
                cout << "-1\n";
        }
    }
    
}
```