### 문제이름, 링크
---
- 키로거
- https://www.acmicpc.net/problem/5397

### 생각한 흐름
---
- 각 문제에서 요구한 대로 구현하면 된 <은 커서 왼쪽으로 >는 오른쪽으로 이동
- "-"는 지울 떄 좀 중요한데 "-" 왼쪽에 있는 걸 지워야하니 iter가 시작점이 아닐 때로 검사를 해야하고 지운 후에 iter가 뒤에 있는 걸 가리킬 수 있도록 함.

### 틀린 부분
- 문제가 이해가 안 되서 문제만 레퍼런스 참고를 좀 함 
- 첫 예제가 이해가 안 되었음 값을 삽입할 때 커서에 있는 위치에 해야된다는 사실을 까먹고 계속 뒤에서 넣으려고 해서 이상하게 생각함

### 코드첨부와 코드 설명
```cpp
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        list<char> ls;
        list<char>::iterator iter = ls.begin();
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == '<'){
                if (iter != ls.begin()){
                    iter--;
                }
            }
            else if (str[j] == '>'){
                if (iter != ls.end()){
                    iter++;
                }
            }
            else if (str[j] == '-'){
                if (iter != ls.begin()){
                    iter--;
                    iter = ls.erase(iter);
                }
            }
            else {
                ls.insert(iter, str[j]);
            }
        }
        for (auto c : ls)
        {
            cout << c;
        }
        cout <<"\n";
    }
    
}
```