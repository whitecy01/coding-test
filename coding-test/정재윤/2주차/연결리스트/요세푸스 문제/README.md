### 문제이름, 링크
---
- 요새푸스 문제
- https://www.acmicpc.net/problem/1158

### 생각한 흐름
- queue를 이용해서 k번째를 구해야하니까 k - 1번째 까지 앞에 있는 값을 뒤로 넘겨주면 k번째에 도착함 그걸 vector에 넣어서 값을 구한다.

### 틀린 부분

1. 첫 번째 생각했던 부분은 list에서 원형 리스트로 개념을 생각한 뒤에 k번째 마다 돌면서 구할 생각이었는데 뭐가 계속 터져버림 아마 k번째를 찾고 삭제를 시켰는데 그 다음 순회할 게 없어서 터지는 것 같음
2. vector로 구해보려고 함 그런데 vector로 하려니 첫 번째 k번째 칸을 간 다음 k번째 만큼 가면 안 되고 k - 1번째까지 가야된다는 점에서 막힘..
3. 다른 사람 예제 코드를 참조해서 queue로 구현하였는데 list로도 바로 구현 가능할 것 같다.


### 코드첨부와 코드 설명
```cpp
int main(){

    int n,k;
    cin >> n >> k;

    queue<int> ls;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        ls.push(i);        
    }

    cout << "<";
    while (!ls.empty())
    {
        for (int j = 0; j < k - 1; j++)
        {
            ls.push(ls.front());
            ls.pop();
        }
        ans.push_back(ls.front());
        ls.pop();
    }
    
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i != ans.size() - 1)
            cout << ", ";
    }
    cout << ">\n";
    

    여기는 list로 해봄 -> 틀렸음
    int main(){

    int n,k;
    cin >> n >> k;

    list<int> ls;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        ls.push_back(i);        
    }
    
    list<int>::iterator iter = ls.begin();

    
    for (int i = 0; i < n; i++)
    {
        int k_temp = k - 1;

        for (int i = 0; i < k_temp; i++)
        {
            if (iter == ls.end()){
                iter = ls.begin();
            }
            iter++;
        }
        
        ans.push_back(*iter);
        
        iter = ls.erase(iter);
        if (iter == ls.end())
            iter = ls.begin();
        for (auto a : ans)
        {
            cout << a << " ";
        }
        cout << "\n";
    }
    for (auto a : ans)
    {
        cout << a << " ";
    }
    
}
```