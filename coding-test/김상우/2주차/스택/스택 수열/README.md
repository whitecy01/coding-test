### 문제 이름, 링크
---
- 스택 수열
- https://www.acmicpc.net/problem/1874

### 생각한 흐름

- 스택같은 경우 전에 짠 코드와 비슷한 흐름으로 할 수 있으나 push 순서를 오름차순을 지키도록한다?
- 이건 사고다.
- 아 잠깐만. 생각해보니 쉬울 수도 있겠다. 우선 N이 주어지니 입력 받는다.
- 수열을 1개씩 입력 받으면서 현재 수열의 수 와 이제 push될 수열의 수가 크다면 push
- 작다면.. 엥? 문제 이해가 안되네..
- 이건 문제 이해가 안됨. 알고리즘이고 뭐고...
- 아...1부터 N까지 스택에 push하면서 입력된 값들이 나올때 pop해서 수열을 만들어라?
- 오케이 다시 생각해보면.
- 수열이 만들어질 수 없다면 No가 출력되어야 하기 때문에 for문이 돌때마다 + 나 -를 출력할 수는 없을 듯. 즉 한번에 출력해야 한다.
- vector를 사용 -> + 와 - 를 vector나 뭐 배열 크게 하나 뒀다가 하나씩 출력하는 식으로 ㄱㄱ
- if문으로 만약 입력 값이 top보다 크다면 NO 출력. -> bool 써서 상태관리하는 방식으로 출력을 뒤로 미루는게 맞을 듯?
- 입력값과 같을때까지 push하며 +를 배열에 넣어 줌. top이 입력값과 같다면? pop 아니라면 impossible

### 틀린 부분
- X
### 코드 첨부 및 설명

```cpp 

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;  //for문을 위한 n값 받음.

    stack<int> s;  //스택생성
    vector<char> r;
    int c = 1; 

    bool possible = true;       //수열생성 가능 불가능을 정해주는 bool

    for (int i = 0; i < n; i++) {  //다음 t로 입력받아 줌.
        int t;
        cin >> t;

        while (c <= t) {    //원하는 숫자 나올때 까지 push 해줌.
            s.push(c);
            r.push_back('+');
            c++;
        }

        if (s.top() == t) {
            s.pop();
            r.push_back('-');
        } else {
            
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << "NO" << endl; // 계행 n에서 endl로 바꿈 괜히 n도 인식할까봐..
    } else {
        for (char ch : r) {
            cout << ch << '\n';
        }
    }

    return 0;
}





```