### 문제 이름, 링크
---
- 요세푸스 문제
- https://www.acmicpc.net/problem/1158


### 생각한 흐름
- 원형 연결 리스트를 사용. erase 를 반복 진행. iterator ++ 를 3번 진행 후 해당 erase(it) 이런식?
- 출력 후 제거 방식으로?
---
- 입력 :
- 입력 값으로 n, k 가 들어옴.
- cin >> n >> k;

---
- lnt 형 list 생성 이름은 pl
- n만큼 값을 생성함으로 n번 반복으로 list에 i 값 넣어 줌.
- iterator 지정.
- 이중 for문으로 출력 및 erase 지정할 자리로 이동.
- *it 을 통해 해당 값 출력.
- pl.end 일 경우 pl.begin으로 다시 앞으로 보냄으로 순환구조.



### 틀린 부분
1. , 를 마지막엔  생략해야 하나 현재 코드상
cout << *it << ","; 같은 경우 뒤에도 ,가 출력됨으로 오답.
2. 음... 그냥 단순히 i가 n-1이 아닐때만 , 출력으로 바꿔봄.
- 수정 전
```cpp
cout << *it << ",";
```
- 수정 후
```cpp
cout << *it;

if(i != n-1) cout << ",";
```

3. 이중 for문중 두번째 for문에서 
```cpp
for (int j =0; j < k; j++)
```
이 부분에서 이럴경우 k번 째를 가리킬 줄 알았지만
실제 가르켜야 하는 것은 k-1번째임.
3,7을 예시로
이미 첫번째를 지정한 상태에서 k가 3일 경우 첫번째 출력 값은 4가 되버림.
즉 int j = 1; 이 되야 한다.

### 코드 첨부와 코드 설명
```cpp
#include <iostream>
#include <list>

using namespace std;

int main(){
    int n, k; // n : 사람 수 , k : 제거될 다음 순번
    cin >> n >> k;

    list<int>pl;
    for(int i =1;i <= n;i++){
        pl.push_back(i);   //list에 값들 입력.
    }

    list<int>::iterator it = pl.begin();  // iterator로 시작 지점 지정.
    cout << "<";


    for (int i =0; i < n; i++){   // 단순 첫번재 for문은 n만큼 돌며 값들을 지우고 출력.
        for(int j =1; j < k; j++){ // 두번째 for문은 iterator를 k번째 값으로 지정.(int j = 1;)
            it++;
            if(it == pl.end()){
                it = pl.begin();
            }
        }

        cout << *it;

        it = pl.erase(it);
        if(it == pl.end()){
            it = pl.begin();
        }
        if(i != n -1) cout << ",";
    }

    cout << ">\n";
    return 0;
}

```