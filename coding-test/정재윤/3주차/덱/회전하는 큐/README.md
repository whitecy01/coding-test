### 문제이름, 링크
---
- 회전하는 큐
- https://www.acmicpc.net/problem/1021

### 생각한 흐름
- 이 문제는 N과 M이 들어오는데 N은 1부터 N까지 들어오고 M번 뽑을 거라는 말
- 두 번째 줄에 들어오는 게 어떤 수를 뽑을 가인가 
- 그래서 나는 find 함수를 써서 찾는 수의 인덱스를 알아내어서 그 인덱스 위치에서 변수 left, right를 사용해 left는 뽑으려고 하는 숫자의 위치, right에는 deque의 size에서 숫자 위치 인덱스를 뺀 값을 비교해서 left < right이면 left의 연산 횟수가 더 작으니 D.push_back(D.front()); D.pop_front(); 사용 연산 횟수를 리턴 해야되니 정답값 ans += left;
- right이 크거나 같으면 오른쪽으로 D.push_front(D.back()) D.pop_back(); 하고 마지막에 pop_front를 함


### 틀린 부분
- find 함수가 기억이 나지 않아서 찾아봄.
```cpp
int idx = find(D.begin(),D.end(), num_find) - D.begin(); //find 까먹음
```

### 코드첨부와 코드 설명
```cpp
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
    deque<int> D;

    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        D.push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int num_find;
        cin >> num_find;
        int idx = find(D.begin(),D.end(), num_find) - D.begin(); //find 함수
        
        int left, right;
        left = idx;
        right = D.size() - idx;
        if (left < right){
            ans += left;
            while (left--)
            {
                D.push_back(D.front());
                D.pop_front();
                
            }
            
        }
        else {
            ans += right;
            while (right--)
            {
                D.push_front(D.back());
                D.pop_back();
            }
        }
        D.pop_front();
        // cout << "ans : " << ans << "\n";
    }
    cout << ans << "\n";
    
}
```