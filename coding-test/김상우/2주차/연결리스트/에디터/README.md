# 문제이름, 링크
---
- 에디터터
- https://www.acmicpc.net/problem/1406


## 생각한 흐름
- 강의에서 봤던 것 처럼 배열을 통해 리스트를 만들기 보다는 STL list를 활용
- L : 커서를 왼쪽 이동 / D : 커서를 오른쪽 이동 / B : 커서 왼쪽 문자 삭제 / p $ : 커서 왼쪽 $ 삽입

- 입력 :
- 입력 받는 것이 문제인데.. list<char> cd;
- while 문을 사용하여 단순하게 받아옴 if 계행이 들어올 경우 break;

- '커서' 개념이 문제다. 커서는 문장의 맨 앞, 맨뒤 도는 중간 임의의 곳에 위치 가능하다.
- ->  [ |abc ]/[ a|bc ]/[ abc| ]가  가능하다.
- 커서를 기준으로 왼쪽 문자를 삭제 -> lsit<char>::iterator cursor = cd.end();
- if else 로 들어오는 문자열 처리
- 문제. 커서의 왼쪽을삭제 허나 여기서 삭제로 인해 커서는 왼쪽으로 이동한 것처럼 나타나지만, 실제로 커서의 오른쪽에 있던 문자는 그대로다. 왼쪽으로 이동 후 삭제.

### 틀린 부분
- 런타임 에러...?

- 확인해 보니 입력 부분에서 cin >> cmd 중 줄바꿈 문자가 읽힐 수 있다는 점.
- 예시로
    abc
    3
    B
    P x
    L
을 입력 받을 경우 
abc\n -> 가지 잘 받고
cin >> M 에서 3을 잘 받으나
cin >> cmd; 에서 앞에 남아 있는 계행 문자가 읽힐 수 있다는 점.
cin.ignore() 를 통해 계행을 제거해야함.
---
해봤으나 역시나 에러..
문제는 cin >> char 하면 \n이 출력 버퍼에 남는 문제가 발생할 수 있다는 점.

즉 입력 자체를 바꿔야 함.

하.. 입력에는 문제가 없었다...
걍 cd.erase(cursor); 문제 였다는 점.

### 코드 첨부와 코드 설명

- 기존 입력 코드
```cpp
 char c;

    while(true){
        c = cin.get();
        if(c == '\n') break;
        cd.push_back(c);
    }

    while(M--){
        char cmd;
        cin >> cmd;
    }
    
```
- 변경 후

```cpp

string str;
    cin >> str;

    for (char c : str) {
        cd.push_back(c);  // 문자 하나씩 리스트에 삽입
    }

    for(int i =0; i < M; i++){
        char cmd;
        cin >> cmd;}


```
---
- 변경전

```cpp 
    cd.erase(cursor);
```

- 변경후
```cpp 
    cursor = cd.erase(cursor);
```