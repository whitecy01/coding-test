### 문제 이름, 링크
---
- 덱
- https://www.acmicpc.net/problem/10866

### 생각한 흐름
- STL의 deque를 사용하여 첫번째 입력값이 들어오면 while 또는 for문으로 n만큼 반복하며 명령어를 입력값으로 넣고 해당 입력값을 if else 조건문으로 확인하는 식으로 진행.

- push_front X: 정수 X를 덱의 앞에 넣는다.
- push_back X: 정수 X를 덱의 뒤에 넣는다.
- push 일 경우 변수를 하나 두고 다음 입력 값을 받고 push_front(변수)

- pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
- pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
- else if 문 안에 if문으로 조건 처리시키면 됨.

- size: 덱에 들어있는 정수의 개수를 출력한다.
- empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
- front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
- back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.

### 틀린 부분분



### 코드 첨부 및 설명
