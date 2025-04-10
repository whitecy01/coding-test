### 문제 이름 , 링크
---

- 제로
- https://www.acmicpc.net/problem/10773

### 생각한 흐름
- 즉 0이 입력되면 pop이라는 소리며
- 첫줄에 정수 K는 명령어 개수 즉 입력을 N으로 받는다.
- stack<int> s; 로 생성.
- 다음 입력 값들을 for문으로 n만큼 입력 받으며 if else문으로 0이면 pop 아니면 push
- 마지막으로 모든 값들을 pop하면 pop된 값들을 하나씩 더하고 값을 내면? 되는데 
- 여기서 문제가 몇번 pop을 시키냐. while문으로 stack이 빌때까지? 하면 될듯.
### 틀린 부분


### 코드 첨부 및 설명

```cpp 

#include <iostream>
#include <stack>

using namespace std;

int main(){
    int N;
    cin >> N; //명령어 개수 입력 받음.


    stack<int> s;

    for (int i =0; i < N; i++){  //for문으로 명령어 값들 받고고
        int num;
        cin >> num;


        if(num ==0){
            if(!s.empty()){  //하나씩 확인해가면 0이면 pop실행 아니면 push(num) 실행행
                s.pop();
            }
        }else{
            s.push(num);
        }


    }

    int sum = 0;

    while(!s.empty()){    //스택 가장 위에 있는 놈들 더한다음 pop하면 다음 놈 또 더하는 간단식식
        sum += s.top();
        s.pop();
    }

    cout << sum << "\n";

    return 0;
}


```