### 문제 이름, 링크
---
- AC
- https://www.acmicpc.net/problem/5430

### 생각한 흐름
- 배열 숫자 값을 줄 때 [1,2,3,4] 이렇게 주면 숫자값으로 못넣음.
- 뒤집는다를 어떻게 코드로 표현하는가? 
- 배열에 들어있는 수 / 2 하여 그 값만큼 뒤로 보내면 되나?

### 틀린 부분
- 뒤집을 경우 뒤에서 pop 아니면 앞에서 pop 하면 됨.

### 코드 첨부 및 설명명
```cpp

#include <iostream>     
#include <deque>        
#include <string>       
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T; // 테스트 케이스 개수 입력

    while (T--) {
        string p;      // 명령어 문자열 (예: RDD)
        int n;         // 배열에 들어있는 숫자 개수
        string arrStr; // 배열 문자열 (예: [1,2,3])

        cin >> p >> n >> arrStr;

        deque<int> dq; // 숫자를 저장할 덱
        string num = ""; // 숫자 누적용 문자열 변수

    //문자열 파싱 코드
        for (int i = 0; i < arrStr.size(); i++) {
            char c = arrStr[i];

            if (isdigit(c)) { // isdigit(c) -> 문자 c 가 숫자인지 확인
                num += c; 
            } else if (c == ',' || c == ']') {
                if (!num.empty()) { //num이 비어있지 않을 경우
                    dq.push_back(stoi(num)); // stoi(num) -> 문자열 "123" 을 정수 123으로 변환
                    num = ""; // 다음 숫자를 위해 초기화
                }
            }
        }

        bool isReversed = false; // 방향 뒤집힘 여부
        bool isError = false;    // 에러 발생 여부

        for (int i = 0; i < p.size(); i++) {
            char cmd = p[i]; // 명령어 하나씩 처리

            if (cmd == 'R') {
                isReversed = !isReversed; // 방향을 반대로 바꿈 (true <-> false)
            } else if (cmd == 'D') {
                if (dq.empty()) {
                    isError = true; // 비었는데 D를 하면 에러
                    break;
                }

                // 방향에 따라 앞이나 뒤에서 제거
                if (isReversed) dq.pop_back();
                else dq.pop_front();
            }
        }

        // ===== 출력 =====
        if (isError) {
            cout << "error\n";
        } else {
            cout << '[';

            if (!dq.empty()) {
                if (isReversed) {
                    // 뒤집힌 상태면 뒤에서부터 출력
                    for (int i = dq.size() - 1; i >= 0; i--) {
                        cout << dq[i];
                        if (i != 0) cout << ','; // 마지막 숫자엔 쉼표 없음
                    }
                } else {
                    // 정방향 출력
                    for (int i = 0; i < dq.size(); i++) {
                        cout << dq[i];
                        if (i != dq.size() - 1) cout << ','; // 마지막 숫자엔 쉼표 없음
                    }
                }
            }

            cout << "]\n"; // 닫는 대괄호 + 줄바꿈
        }
    }

    return 0;
}






```