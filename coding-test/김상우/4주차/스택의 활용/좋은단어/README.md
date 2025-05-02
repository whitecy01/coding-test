### 문제 이름, 링크
---

- 좋은 단어
- https://www.acmicpc.net/problem/3986

### 생각한 흐름
- A push 이후 A가 스택에 존재할때 A가 들어오면 pop?
- 그럼AAAAAA 는 1로 count 되나?
- 좋은 단어는 짝지어진 동일한 문자가 입접해서 전부 제거할 수 있는 단어다..
- ABBA -> 스택의 top을 보고 동일한 알파벳이면 pop 아니면 push하고 스택이 비어있으면 좋은 단어 카운트하는 방식으로 풀면 될거 같다.

### 틀린 부분
- 와 드디어 하나 맞췄다.
- 좀 어렵네..ㅜㅜ

### 코드 첨부 및 설명

```cpp

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;  //단어 개수 입력값 받음.

    int count = 0; //좋은 단어 카운트

    for (int i = 0; i < N; i++) {

        string word;  //string으로 입력값 받음.
        cin >> word;

        stack<char> s; //stack s

        for(int j =0; j < word.size(); j++){  //word의 크기만큼 반복
            char c = word[j];   //string word의 인덱스 활용 if AB 일때 word[1] 은 A word[2] 는 B
                                // 이 값을 c 에 넣고 씀.

            if(!s.empty()&&s.top() == c){ //s가 비어있지 않거나 s.top 값이 c일 경우 pop
                s.pop();
            }else{
                s.push(c);  //아니면 push
            }


        }

        if(s.empty()){  //위 for문이 끝나고 s가 비어있으면 좋은 단어 + 1
            count++;
        }



    }

    //반복 후 출력력

    cout << count << '\n';
    return 0;
}





```