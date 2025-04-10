### 문제 이름, 링크
---
- 스택
- https://www.acmicpc.net/problem/10828


### 생각한 흐름
- 스택 자료구조를 구현..
- 다른 블로거 참고함. -> 알고리즘을 어떻게 짜야할지 감이안옴.
- 예제 입력과 출력에 대해서 이해가 잘 안가는듯?
- 첫번째 입력으로는 N 즉, 명령어의 수
- 그 다음으로 push냐 pop이냐 인데. empty 구현을 어떵하냐..
- size 같은 경우 a.size() 함수 활용.
- empty 는 a.size() 가 0 일 경우 1을 출력 아닐경우 0을 출력 if문 사용..? 맞나?




### 틀린 부분


### 코드 설명 및 첨부


- 다른 사람 코드 첨부
---

```cpp 
#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> s;      // 스택
	int N;             // 명령의 수
	string command;    // 명령어
	int num;           // push 연산 시, 스택에 넣을 정수
	int result = 0;    // 각 명령어의 결과값

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> command;

		// 1. push
		if (command == "push") {
			cin >> num;
			s.push(num);
		}

		// 2. pop
		//    스택이 비어있으면 -1을 출력, 그 외에는 top 값을 출력 후 pop
		else if (command == "pop") {
			if (s.size() == 0) {
				result = -1;
				cout << result << endl;
			}
			else {
				result = s.top();
				cout << result << endl;
				s.pop();
			}
		}

		// 3. size
		else if (command == "size") {
			cout << s.size() << endl;
		}

		// 4. empty
		//    size함수를 통해, size가 0이면 스택이 빈 것이므로 1, 아니면 0 출력     
		else if (command == "empty") {
			if (s.size() == 0) {
				result = 1;
				cout << result << endl;
			}
			else {
				result = 0;
				cout << result << endl;
			}
		}

		// 5. top
		//    스택이 비어있으면 -1을 출력, 그 외에는 top 값을 출력
		else if (command == "top") {
			if (s.size() == 0) {
				result = -1;
				cout << result << endl;
			}
			else {
				result = s.top();
				cout << result << endl;
			}
		}
	}

	return 0;
}

```