### 문제 이름, 링크
---
- 키로거
- https://www.acmicpc.net/problem/5397

### 생각한 흐름

- 빈 연결 리스트 생성 -? 커서를 head 위치에 초기화.
- 입력 문자열을 한 글자씩 반복
- 현재 문자 확인
- "<" : 커서가 이전 노드로 이동
- ">" : 커서가 다음 노드로 이동
- "-" : 커서 이전노드 삭제

- 문자일 경우 커서 앞에 새 노드 삽입 후 커서를 새 노드로 이동..?
- 연결 리스트를 처음붵 끝까지 탐색 -> 문자열 생성

### 틀린 부분
- 사실 전 문제들이랑 흐름적이나 코드적으로 너무 비슷해서 틀릴 부분이 없음.

### 코드 첨부 및 설명

```cpp 
    #include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string input;
        cin >> input;

        list<char> text;
        auto cursor = text.begin(); // 자동으로 타입을 정해 준다고 함. -> 신기방기

        for (char ch : input) {
            if (ch == '<') {
                if (cursor != text.begin()) cursor--; // 커서를 맨 앞에 놓음.
            } else if (ch == '>') {
                if (cursor != text.end()) cursor++;
            } else if (ch == '-') {
                if (cursor != text.begin()) {
                    cursor = text.erase(--cursor);  // 앞의 문자 삭제 후 커서를 삭제된 다음 이동
                    // 위에 이 부분은 솔직히 이해가 아직도 잘 안된다.. 코드 짤때 또 생략했다가 런타임 에러 뜸. -> 흠..일단 안쓰면 런타임 에러라 쓰는 느낌임.
                }
            } else {
                cursor = text.insert(cursor, ch);  // 커서 앞에 문자 삽입
                cursor++;   // 커서를 삽입한 문자 뒤로 이동시킴.
        }

        for (char c : text) {
            cout << c;
        }
        cout << '\n';
    }
    return 0;
}


```