### 문제이름, 링크
---
- AC
- https://www.acmicpc.net/problem/5430

### 생각한 흐름
- 이 문제는 입력 받은대로 R은 reverse D는 버리기 함수 즉 deque의 제일 앞을 pop을 하면 됨
- 관건은 이제 [1,2,3,4]를 어떻게 처리할 지와 reverse

### 틀린 부분
- split 함수에서 istringstream과 getline을 어떻게 구해야하는지 까먹음
- 난 처음에 vector를 사용함 그래서 reverse를 reverse함수reverse(vec.begin(), vec.end())를 써서  이런 구조로 했는데 시간 초과가 나버림..
- 어떻게 하면 좋을지 생각이 안나서 찾아보니 R이 나올 때마다 bool 변수에 true와 false값을 주어서 체크 한 다음에 마지막에 rbegin rend, begin end를 써서 출력
- 여기서 D를 할 때는 bool 변수를 보고 앞에 부분을 지울지 뒤에 부분을 지울지 결정


### 코드첨부와 코드 설명
```cpp
#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;


deque<int> split(string arr, char search){
    istringstream ss(arr);
    string word;

    deque<int> num;
    while (getline(ss, word, search))
    {
        // cout << word<<"\n";
        num.push_back(stoi(word));
    }
    return num;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        int size;
        cin >> size;

        string arr;
        cin >> arr;
        string pashre_arr = arr.substr(1, arr.size() - 2);
        deque<int> vec = split(pashre_arr, ',');
        bool check = true;
        bool isReversed = false;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == 'R'){
                isReversed = !isReversed;
            }
            else if (str[i] == 'D'){
                if (vec.empty()){
                    check = false;
                    cout << "error\n";
                    break;
                }
                if (isReversed){
                    vec.pop_back();
                }
                else vec.pop_front ();
            }
        }
        if (check == true){
            cout << "[";
            if (isReversed) {
                for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
                    cout << *it;
                    if (it + 1 != vec.rend()) cout << ",";
                }
            } else {
                for (auto it = vec.begin(); it != vec.end(); ++it) {
                    cout << *it;
                    if (it + 1 != vec.end()) cout << ",";
                }
            }
            cout <<"]\n";
            
        }

        
    }
}
```